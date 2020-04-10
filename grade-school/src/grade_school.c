#include "grade_school.h"
#include <string.h>

static roster_t roster = {
    .count = 0};

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
    for (int i = grade_start_index; i < roster.count; i++)
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
}

/* Find first item with given grade. If not found return -1 */
static int get_grade_start_index(uint8_t grade)
{
    return -1;
}