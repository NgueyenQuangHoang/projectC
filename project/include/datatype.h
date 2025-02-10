#include<stdio.h>
#include<stdlib.h>
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
    Date publication;
}Book;

typedef struct Member{
    char memberId[10];
    char name[20];
    char phone[10];
    bool status;
    Book borrowedBook[];
}Member;

