#include <stdio.h>
#include "function.c"
int main(int argc, char *argv[]) {
    loadBookData();
    int choice;
    mainMenu();
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            adminMenu();
            break;
        case 2:
            
            break;
        case 3:
            
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}
