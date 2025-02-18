#include <stdio.h>

#include "../include/functionBook.h"
#include "../include/functionCustomer.h"
#include "../include/config.h"


#include <string.h>

#define USERNAME "hoang"
#define PASSWORD "1512"

void saveLoginData() {
    FILE *file = fopen("../data/login.bin", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fwrite(USERNAME, sizeof(char), strlen(USERNAME) + 1, file);
    fwrite(PASSWORD, sizeof(char), strlen(PASSWORD) + 1, file);
    fclose(file);
}

void loadLoginData(char *username, char *password) {
    FILE *file = fopen("../data/login.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fread(username, sizeof(char), 10, file);
    fread(password, sizeof(char), 10, file);
    fclose(file);
}

// mat khau++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void login();
void mainMenu();

int main(int argc, char *argv[]) {
    loadBookData();
    loadCusData();
    int choice;
    mainMenu();
    scanf("%d", &choice);
    clearScreen();
}
 
void login() {
    char username[10];
    char passWord[10];
    char storedUsername[10];
    char storedPassword[10];

    loadLoginData(storedUsername, storedPassword);

    printf("\n==============================\n");
    printf("        LOGIN SYSTEM\n");
    printf("==============================\n");
    printf("Enter your username: ");
    fgets(username, 10, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter your password: ");
    fgets(passWord, 10, stdin);
    passWord[strcspn(passWord, "\n")] = '\0';

    while (strcmp(username, storedUsername) != 0 || strcmp(passWord, storedPassword) != 0) {
        printf("Incorrect username or password. Access denied.\n");
        printf("Enter your username: ");
        fgets(username, 10, stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Enter your password: ");
        fgets(passWord, 10, stdin);
        passWord[strcspn(passWord, "\n")] = '\0';
    }

    printf("Access granted.\n");
    printf("==============================\n");
}

// menu chinh+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mainMenu(){
    login();
    int choice;
    clearScreen();
    do {
        printf("***library management System\n");
        printf("\t\tCHOOSE YOUR ROLE\n");
        printf("\t======================\n");
        printf("\t[1] Admin.\n");
        printf("\t[2] Member.\n");
        printf("\t[0] Exit\n");
        printf("\t======================\n");
        printf("Enter The Choice...");
        scanf("%d", &choice);
        clearScreen();
        switch (choice) {
            case 1:
                bookManagement();
                break;
            case 2:
                customerManagement();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}
