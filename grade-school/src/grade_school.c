#include "grade_school.h"
#include <string.h>

static roster_t roster = {
    .count = 0};

static int get_grade_start_index(uint8_t grade);
static int get_grade_end_index(uint8_t grade, int grade_start_index);
static int find_place_for_student(char *name, uint8_t grade);

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
    if (grade_start_index == -1)
    {
        return grade_roster;
    }
    for (int i = grade_start_index; (size_t)i < roster.count; i++)
    {
        if (roster.students[i].grade == grade)
        {
            strcpy(grade_roster.students[grade_roster.count].name,
                   roster.students[i].name);
            grade_roster.students[grade_roster.count].grade = grade;
            grade_roster.count++;
        }
        else
        {
            break;
        }
    }
    return grade_roster;
}

/* Find first item with given grade. If not found return -1 */
static int get_grade_start_index(uint8_t grade)
{
    for (size_t i = 0; i < roster.count; i++)
    {
        if (roster.students[i].grade == grade)
        {
            return (int)i;
        }
    }
    return -1;
}

static int find_place_for_student(char *name, uint8_t grade)
{
    int place_for_student = -1;
    int grade_start_index = get_grade_start_index(grade);
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
            for (size_t i = 1; i < roster.count - 1; i++)
            {
                if (roster.students[i].grade < grade && roster.students[i + 1].grade > grade)
                {
                    place_for_student = i + 1;
                    break;
                }
            }
        }
    }
    else
    {
        int grade_end_index = get_grade_end_index(grade, grade_start_index);
        if (strcmp(name, roster.students[grade_start_index].name) < 0)
        {
            place_for_student = grade_start_index;
        }
        else if (strcmp(name, roster.students[grade_start_index].name) > 0)
        {
            place_for_student = grade_end_index + 1;
        }
        else
        {
            for (int i = grade_start_index + 1; i < grade_end_index; i++)
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

static int get_grade_end_index(uint8_t grade, int grade_start_index)
{
    int grade_end_index = grade_start_index;
    for (size_t i = grade_start_index; i < roster.count - 1; i++)
    {
        if (roster.students[i + 1].grade != grade)
        {
            grade_end_index = (int)i;
            break;
        }
        else if (i == roster.count - 2)
        {
            grade_end_index = (int)roster.count - 1;
        }
    }
    return grade_end_index;
}