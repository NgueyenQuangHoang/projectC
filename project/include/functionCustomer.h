// functionCustomer.h
#ifndef FUNCTION_CUSTOMER_H
#define FUNCTION_CUSTOMER_H

#include "../include/datatype.h" 
#include <stdio.h>    
#include <string.h>   
#include <stdbool.h>  

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
