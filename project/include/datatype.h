#ifndef DATATYPE_H 
#define DATATYPE_H 

#include<string.h>
#include<stdbool.h>

typedef struct Date{
    int month, date, year;
}Date;

typedef struct Book{
    char bookId[4];
    char title[30];
    char author[20];
    int quantity;
    char price[10];
    Date publication;
}Book;

typedef struct Customer{
    char cusId[10];
    char name[20];
    char phone[10];
    bool status;
    Book borrowedBook[10];
}Customer;

#endif