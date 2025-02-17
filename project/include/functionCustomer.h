// functionCustomer.h
#ifndef FUNCTION_CUSTOMER_H
#define FUNCTION_CUSTOMER_H

#include "../include/datatype.h" // Assuming datatype.h is needed
#include <stdio.h>    // For FILE* and printf
#include <string.h>   // For string functions
#include <stdbool.h>  // For bool type

// Constants
#define MAX_CUSTOMER 100

// Function prototypes
void loadCusData();
void saveCusData();

int checkCusID(char *idC);
int checkCusPhone(char *Phone);

void getCusId(char *idC);
void getCusName(char *Name);
void getCusPhone(char *Phone);
void getCusStatus(bool *status);

void displayCustomer();
void addCustomer();
void editCustomer();

void showCustomerManagement();
void customerManagement();

#endif // FUNCTION_CUSTOMER_H
