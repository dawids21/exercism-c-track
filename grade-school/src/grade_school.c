#include "grade_school.h"
#include <string.h>

static int grade_cuts[MAX_GRADES * 2];

static roster_t roster = {
    .count = 0};

static int find_place_for_student(char *name, uint8_t grade);
static int get_grade_cut_start(uint8_t grade);
static void refresh_cuts(uint8_t added_grade);

roster_t get_roster(void)
{
    return roster;
}

void clear_roster(void)
{
    memset(&roster, 0, sizeof(roster_t));
    memset(&grade_cuts, 0, sizeof(grade_cuts));
}

bool add_student(char *name, uint8_t grade)
{
    if (roster.count == MAX_STUDENTS)
    {
        return false;
    }
    int place_for_student = find_place_for_student(name, grade);

    /*Shift students to the right to make room for another one*/
    for (int i = roster.count - 1; i >= place_for_student; i--)
    {
        memcpy(&roster.students[i + 1], &roster.students[i], sizeof(student_t));
    }

    strcpy(roster.students[place_for_student].name, name);
    roster.students[place_for_student].grade = grade;
    roster.count++;
    refresh_cuts(grade);
    return true;
}

roster_t get_grade(uint8_t grade)
{
    roster_t grade_roster;
    memset(&grade_roster, 0, sizeof(roster_t));
    for (int i = grade_cuts[get_grade_cut_start(grade)]; i < grade_cuts[get_grade_cut_start(grade) + 1]; i++)
    {
        memcpy(&grade_roster.students[grade_roster.count], &roster.students[i], sizeof(student_t));
        grade_roster.count++;
    }
    return grade_roster;
}

static int find_place_for_student(char *name, uint8_t grade)
{
    int place_for_student = -1;
    int grade_cut_start = grade_cuts[get_grade_cut_start(grade)];
    int grade_cut_end = grade_cuts[get_grade_cut_start(grade) + 1];

    /*If the grade is not present find correct place by comparing grades*/
    if (grade_cut_start == grade_cut_end)
    {
        place_for_student = grade_cuts[get_grade_cut_start(grade)];
    }

    /*If the grade is present find correct place by comparing names*/
    else
    {
        if (strcmp(name, roster.students[grade_cut_start].name) < 0)
        {
            place_for_student = grade_cut_start;
        }
        else if (strcmp(name, roster.students[grade_cut_end - 1].name) > 0)
        {
            place_for_student = grade_cut_end;
        }
        else
        {
            for (int i = grade_cut_start; i < grade_cut_end - 1; i++)
            {
                if (strcmp(name, roster.students[i].name) > 0 && strcmp(name, roster.students[i + 1].name) < 0)
                {
                    place_for_student = i + 1;
                    break;
                }
            }
        }
    }
    return place_for_student;
}

static int get_grade_cut_start(uint8_t grade)
{
    return grade * 2 - 2;
}

static void refresh_cuts(uint8_t added_grade)
{
    for (int i = get_grade_cut_start(added_grade) + 1; i < MAX_GRADES * 2; i++)
    {
        grade_cuts[i]++;
    }
}