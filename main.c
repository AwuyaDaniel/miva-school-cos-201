#include <stdio.h>
#include "student.h"

int main() {
    char user[50];
    int choice;

    printf("=====**** Student Record System ****=====\n");
    printf("Enter your name(NO SPACES): ");
    scanf("%s", user);
    printf("Hello %s!\n", user);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Modify Student\n");
        printf("4. Delete Student\n");
        printf("5. Search\n");
        printf("6. Average Marks\n");
        printf("7. Sort Ascending\n");
        printf("8. Sort Descending\n");
        printf("9. Save\n");
        printf("10. Load\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: modifyStudent(); break;
            case 4: deleteStudent(); break;
            case 5: searchStudent(); break;
            case 6: calculateAverage(); break;
            case 7: sortStudents(1); break;
            case 8: sortStudents(0); break;
            case 9: saveToFile(); break;
            case 10: loadFromFile(); break;
        }

    } while(choice != 0);

    freeMemory();
    printf("Goodbye!\n");
    return 0;
}