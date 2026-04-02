#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int roll;
    float marks;
} Student;

void addStudent();
void displayStudents();
void modifyStudent();
void deleteStudent();
void searchStudent();
void calculateAverage();
void sortStudents(int ascending);
void saveToFile();
void loadFromFile();
void freeMemory();

#endif