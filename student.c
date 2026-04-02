#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

Student *students = NULL;
int count = 0;

// ADD
void addStudent() {
    students = realloc(students, (count + 1) * sizeof(Student));

    printf("Enter name: ");
    scanf("%s", students[count].name);

    printf("Enter roll number: ");
    scanf("%d", &students[count].roll);

    printf("Enter marks: ");
    scanf("%f", &students[count].marks);

    if (students[count].marks >= 40)
        printf("Status: PASS\n");
    else
        printf("Status: FAIL\n");

    count++;
}

// DISPLAY
void displayStudents() {
    if(count == 0) {
        printf("No records available.\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("Name: %s | Roll: %d | Marks: %.2f\n",
               students[i].name,
               students[i].roll,
               students[i].marks);
    }
}

// MODIFY
void modifyStudent() {
    int roll, found = 0;

    printf("Enter roll number to modify: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(students[i].roll == roll) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);

            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            found = 1;
        }
    }

    if(!found) printf("Student not found.\n");
}

// DELETE
void deleteStudent() {
    int roll, index = -1;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(students[i].roll == roll) index = i;
    }

    if(index == -1) {
        printf("Student not found.\n");
        return;
    }

    for(int i = index; i < count - 1; i++)
        students[i] = students[i + 1];

    count--;
    students = realloc(students, count * sizeof(Student));
    printf("Record deleted.\n");
}

// SEARCH
void searchStudent() {
    int roll, found = 0;

    printf("Enter roll number: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(students[i].roll == roll) {
            printf("Name: %s | Marks: %.2f\n",
                   students[i].name,
                   students[i].marks);
            found = 1;
        }
    }

    if(!found) printf("Student not found.\n");
}

// AVERAGE
void calculateAverage() {
    if(count == 0) return;

    float sum = 0;
    for(int i = 0; i < count; i++)
        sum += students[i].marks;

    printf("Average marks = %.2f\n", sum / count);
}

// SORT
void sortStudents(int ascending) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = i + 1; j < count; j++) {
            int condition = ascending ?
                students[i].marks > students[j].marks :
                students[i].marks < students[j].marks;

            if(condition) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Records sorted.\n");
}

//  SAVE
void saveToFile() {
    FILE *fp = fopen("students.txt", "w");
    if(fp == NULL) return;

    for(int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %.2f\n",
                students[i].name,
                students[i].roll,
                students[i].marks);
    }

    fclose(fp);
    printf("Saved successfully.\n");
}

// LOAD
void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");
    if(fp == NULL) return;

    free(students);
    students = NULL;
    count = 0;

    while(1) {
        students = realloc(students, (count + 1) * sizeof(Student));

        if(fscanf(fp, "%s %d %f",
                  students[count].name,
                  &students[count].roll,
                  &students[count].marks) != 3)
            break;

        count++;
    }

    fclose(fp);
    printf("Records loaded.\n");
}


void freeMemory() {
    free(students);
}