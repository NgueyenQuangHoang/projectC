#include <stdio.h>
#include "functionCheck.c"

int main(int argc, char *argv[]) {
    loadBookData();
    int choice;
    mainMenu();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bookManagement();
            break;
        case 2:
            customerManagement();
            break;
        case 3:
            
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}
