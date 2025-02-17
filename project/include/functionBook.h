// function.h
#ifndef FUNCTIONBOOK_H
#define FUNCTIONBOOK_H

#include "../include/datatype.h" // Assuming datatype.h is needed in the header
#include <stdio.h>    // For FILE* etc.
#include <string.h>   // For string functions

// Constants
#define MAX_BOOK 100

// Function prototypes (declarations)
void loadBookData();
void saveBookData();

int checkID(char *idB);
int checkTitle(char *title);

void getBookId(char *idB);
void getBookTitle(char *title);
void getBookAuthor(char *author);
void getBookQuantity(int *quantity);
void getPublicationDate(int *date, int *month, int *year);
void getPrice(char *price);

void displayBooklist();
void addBook();
void editBook();
void deleteBook();
void searchBook();
void Sort();

void showBookManagement();
void bookManagement();

// Any other necessary includes or definitions

#endif // FUNCTION_H
