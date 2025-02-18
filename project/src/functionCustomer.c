#include <stdio.h>
#include "../include/datatype.h"
#include "../include/config.h"
#define MAX_CUSTOMER 100

Customer cus[MAX_CUSTOMER];
int cusCount = 0;


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void loadCusData(){
    FILE *file = fopen("customer.bin", "rb");
    if (file == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }
    while (fread(&cus[cusCount], sizeof(Customer), 1, file) == 1)
    {
        cusCount++;
    }
    fclose(file);
}

void saveCusData(){
    FILE *file = fopen("customer.bin", "wb");
    if (file == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }
    for (int i = 0; i < cusCount; i++)
    {
        fwrite(&cus[i], sizeof(Customer), 1, file);
    }
    fclose(file);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// kiểm tra dữ liệu nhập vào của khách hàng
int checkCusID(char *idC){
    for (int i = 0; i < cusCount; i++)
    {
        if (strcmp(cus[i].cusId, idC) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int checkCusPhone(char *Phone){
    for (int i = 0; i < cusCount; i++)
    {
        if (strcmp(cus[i].phone, Phone) == 0)
        {
            return 0;
        }
    }
    return 1;
}

void getCusId(char *idC){
    do
    {
        printf("Enter Customer ID:");
        fgets(idC, 10, stdin);
        idC[strcspn(idC, "\n")] = '\0';
        if (strlen(idC) == 0)
        {
            printf("Customer ID cannot be empty. Please enter Id:\n");
        }else if (!checkCusID(idC))
        {
            printf("Customer's id already exists. Please enter a unique id.\n");
        }
    } while (strlen(idC) == 0 || !checkCusID(idC));
}

void getCusName(char *Name){
    do
    {
        printf("Enter customer's name: ");
        fgets(Name, 30, stdin);
        Name[strcspn(Name, "\n")] = '\0';
        if (strlen(Name) == 0) {
            printf("Customer's name cannot be empty. Please enter again.\n");
        }
    } while (strlen(Name) == 0);
}

void getCusPhone(char *Phone){
    do
    {
        printf("Enter Customer's Phone:");
        fgets(Phone, 20, stdin);
        Phone[strcspn(Phone, "\n")] = '\0';
        if (strlen(Phone) == 0)
        {
            printf("Customer's phone cannot be empty. Please enter again\n");
        }else if (!checkCusPhone(Phone))
        {
            printf("Customer's Phone already exists. Please enter a unique Phone.\n");
        }
    } while (strlen(Phone) == 0 || !checkCusPhone(Phone));
}

void getCusStatus(bool *status) {
    char input[10];
    do {
        printf("Enter Customer's Status (active/inactive): ");
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) == 0) {
            printf("Customer's status cannot be empty. Please enter again.\n");
        } else if (strcmp(input, "active") == 0) {
            *status = true;
        } else if (strcmp(input, "inactive") == 0) {
            *status = false;
        } else {
            printf("Invalid status. Please enter 'active' or 'inactive'.\n");
        }
    } while (strlen(input) == 0 || (strcmp(input, "active") != 0 && strcmp(input, "inactive") != 0));
}

//=========================================================================================================
// function Quản lý customer+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void displayCustomer() {
    if (cusCount == 0) {
        printf("[Hollow!]\n");
        return;
    }
    printf("\t\t\t\t\t**CUSTOMER LIST**\n");
    printf("|======|===============================|================|================|===============|\n");
    printf("|id    | Name                          | Phone          | Status         | Borrowed Book |\n");
    printf("|======|===============================|================|================|===============|\n");
    for (int i = 0; i < cusCount; i++) {
        printf("| %-3s  | %-29s | %-14s | %-14s | %-14s |\n", 
            cus[i].cusId, cus[i].name, cus[i].phone, cus[i].status ? "active" : "inactive", cus[i].borrowedBook);
    }
    printf("|======|===============================|================|================|===============|\n");
}

void addCustomer(){
    if (cusCount == MAX_CUSTOMER) {
        printf("The customer list is full. Cannot add more customers.\n");
        return;
    }
    getCusId(cus[cusCount].cusId);
    getCusName(cus[cusCount].name);
    getCusPhone(cus[cusCount].phone);
    getCusStatus(&cus[cusCount].status);
    cusCount++;
    saveCusData();
    printf("Customer added successfully.\n");
}

void editCustomer(){
    char idC[10];
    printf("Enter id of customer to edit:...");
    scanf("%s", idC);
    getchar(); // clear newline character from input buffer
    for (int i = 0; i < cusCount; i++) {
        if (strcmp(cus[i].cusId, idC) == 0) {
            getCusName(cus[i].name);
            getCusPhone(cus[i].phone);
            getCusStatus(&cus[i].status);
            saveCusData();
            printf("Customer edited successfully.\n");
            return;
        }
    }
    printf("Customer not found.\n");
}

// menu book(cus)++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void showCustomerManagement(){
    printf("***library management System\n");
    printf("\t\tCUSTOMER MENU\n");
    printf("\t======================\n");
    printf("\t[1] Customer list.\n");
    printf("\t[2] Add customer.\n");
    printf("\t[3] Edit customer information\n");
    printf("\t[4] Manage Account Access\n");
    printf("\t[5] Book lending\n");
    printf("\t[6] Return\n");
    printf("\t[0] Back to main menu\n");
    printf("\t======================\n");
    printf("Enter The Choice...");
}

void customerManagement(){
    int choice;
    do {
        showCustomerManagement();
        scanf("%d", &choice);
        getchar();
        clearScreen();
        switch (choice) {
            case 1:
                displayCustomer();
                break;
            case 2:
                addCustomer();
                break;
            case 3:
                editCustomer();
                break;
            case 4:
                // manageAccountAccess();
                break;
            case 5:
                // borrowBook();
                break;
            case 6:
                // returnBook();
                break;
            case 0:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}
