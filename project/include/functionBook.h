
#ifndef FUNCTIONBOOK_H
#define FUNCTIONBOOK_H

#include "../include/datatype.h" 
#include <stdio.h>    
#include <string.h>   


#define MAX_BOOK 100

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


#endif // FUNCTION_H
