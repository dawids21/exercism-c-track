#include "grade_school.h"
#include <string.h>

static roster_t roster = {
    .count = 0};

static int find_place_for_student(char *name, uint8_t grade);
static int get_grade_start_index(uint8_t grade);
static int get_grade_end_index(uint8_t grade, int grade_start_index);

roster_t get_roster(void)
{
    return roster;
}

void clear_roster(void)
{
    memset(&roster, 0, sizeof(roster_t));
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
    return true;
}

roster_t get_grade(uint8_t grade)
{
    roster_t grade_roster;
    memset(&grade_roster, 0, sizeof(roster_t));
    int grade_start_index = get_grade_start_index(grade);

    /*If grade is not present return empty roster*/
    if (grade_start_index == -1)
    {
        return grade_roster;
    }

    for (int i = grade_start_index; i < (int)roster.count; i++)
    {
        if (roster.students[i].grade == grade)
        {
            memcpy(&grade_roster.students[grade_roster.count],
                   &roster.students[i],
                   sizeof(student_t));
            grade_roster.count++;
        }
        else
        {
            break;
        }
    }
    return grade_roster;
}

static int find_place_for_student(char *name, uint8_t grade)
{
    int place_for_student = -1;
    int grade_start_index = get_grade_start_index(grade);

    /*If the grade is not present find correct place by comparing grades*/
    if (grade_start_index == -1)
    {
        if (grade < roster.students[0].grade)
        {
            place_for_student = 0;
        }
        else if (grade > roster.students[roster.count - 1].grade)
        {
            place_for_student = roster.count;
        }
        else
        {
            for (int i = 0; i < (int)roster.count - 1; i++)
            {
                if (roster.students[i].grade < grade && roster.students[i + 1].grade > grade)
                {
                    place_for_student = i + 1;
                    break;
                }
            }
        }
    }

    /*If the grade is present find correct place by comparing names*/
    else
    {
        int grade_end_index = get_grade_end_index(grade, grade_start_index);
        if (strcmp(name, roster.students[grade_start_index].name) < 0)
        {
            place_for_student = grade_start_index;
        }
        else if (strcmp(name, roster.students[grade_end_index].name) > 0)
        {
            place_for_student = grade_end_index + 1;
        }
        else
        {
            for (int i = grade_start_index; i < grade_end_index; i++)
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

/* Find first item with given grade. If not found return -1 */
static int get_grade_start_index(uint8_t grade)
{
    for (int i = 0; i < (int)roster.count; i++)
    {
        if (roster.students[i].grade == grade)
        {
            return i;
        }
    }
    return -1;
}

/*Find last index with given grade*/
static int get_grade_end_index(uint8_t grade, int grade_start_index)
{
    int grade_end_index = grade_start_index;
    for (int i = grade_start_index; i < (int)roster.count - 1; i++)
    {
        if (roster.students[i + 1].grade != grade)
        {
            grade_end_index = i;
            break;
        }
        else if (i == (int)roster.count - 2)
        {
            grade_end_index = roster.count - 1;
        }
    }
    return grade_end_index;
}