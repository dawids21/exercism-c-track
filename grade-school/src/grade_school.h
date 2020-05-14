#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_NAME_LEN 20
#define MAX_STUDENTS 20
#define MAX_GRADES 10

typedef struct
{
    uint8_t grade;
    char name[MAX_NAME_LEN];
} student_t;

typedef struct
{
    size_t count;
    student_t students[MAX_STUDENTS];
} roster_t;

roster_t get_roster(void);
void clear_roster(void);
bool add_student(char *name, uint8_t grade);
roster_t get_grade(uint8_t grade);

#endif
