#include "grade_school.h"
#include <string.h>

static roster_t roster = {
    .count = 0};

static int get_grade_start_index(uint8_t grade);
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
    //TODO
    return 0;
}