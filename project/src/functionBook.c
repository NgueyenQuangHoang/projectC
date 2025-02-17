#include "../include/datatype.h"
#include <stdio.h>
#include "../include/config.h"
#define MAX_BOOK 100

Book books[MAX_BOOK];
int bookCount = 0;


// load va save data+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void loadBookData(){
    FILE *file = fopen("book.bin", "rb");
    if (file == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }
    while (fread(&books[bookCount], sizeof(Book), 1, file) == 1)
    {
        bookCount++;
    }
    fclose(file);
}

void saveBookData(){
    FILE *file = fopen("book.bin", "wb");
    if (file == NULL)
    {
        printf("Cannot open file.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++)
    {
        fwrite(&books[i], sizeof(Book), 1, file);
    }
    fclose(file);
}

// kiem tra du lieu nhap vao của book+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int checkID(char *idB) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookId, idB) == 0) {
            return 0;
        }
    }
    return 1;
}

int checkTitle(char *title) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return 0;
        }
    }
    return 1;
}

void getBookId(char *idB) {
    do {
        printf("Enter book id: ");
        fgets(idB, 5, stdin);
        idB[strcspn(idB, "\n")] = '\0';
        if (strlen(idB) == 0) {
            printf("Book id cannot be empty. Please enter again.\n");
        } else if (!checkID(idB)) {
            printf("Book id already exists. Please enter a unique id.\n");
        }
    } while (strlen(idB) == 0 || !checkID(idB));
}

void getBookTitle(char *title) {
    do {
        printf("Enter book title: ");
        fgets(title, 30, stdin);
        title[strcspn(title, "\n")] = '\0';
        if (strlen(title) == 0) {
            printf("Book title cannot be empty. Please enter again.\n");
        } else if (!checkTitle(title)) {
            printf("Book title already exists. Please enter a unique title.\n");
        }
    } while (strlen(title) == 0 || !checkTitle(title));
}

void getBookAuthor(char *author) {
    do {
        printf("Enter author: ");
        fgets(author, 20, stdin);
        author[strcspn(author, "\n")] = '\0';
        if (strlen(author) == 0) {
            printf("Author cannot be empty. Please enter again.\n");
        }
    } while (strlen(author) == 0);
}

void getBookQuantity(int *quantity) {
    do {
        printf("Enter quantity: ");
        scanf("%d", quantity);
        if (*quantity <= 0) {
            printf("Quantity must be greater than 0. Please enter again.\n");
        }
    } while (*quantity <= 0);
}

void getPublicationDate(int *date, int *month, int *year) {
    do {
        printf("Enter publication date (mm/dd/yyyy): ");
        scanf("%d %d %d", date, month, year);
        if (*date <= 0 || *date > 31 || *month <= 0 || *month > 12 || *year <= 0) {
            printf("Invalid date. Please enter again.\n");
        }
    } while (*date <= 0 || *date > 31 || *month <= 0 || *month > 12 || *year <= 0);
}

void getPrice(char *price) {
    do {
        printf("Enter price: ");
        scanf("%s", price);
        if (strlen(price) == 0) {
            printf("Price cannot be empty. Please enter again.\n");
        }
    } while (strlen(price) == 0);
}

// =======================================================================================================
// Phan function cua Admin++++++++++++++++++++++++++++++++++++++
void displayBooklist(){
    if (bookCount == 0)
    {
        printf("[-HOLLOW-]\n");
        return;
    }
    printf("\t\t\t\t\t**BOOK LIST**\n");
    printf("|======|==============================|=====================|====|============|================|\n");
    printf("|id    | Title                        | Author              |Qty | Published  | Price          |\n");
    printf("|======|==============================|=====================|====|============|================|\n");
    for (int i = 0; i < bookCount; i++)
    {
        printf("| %-3s | %-29s | %-19s | %-2d | %02d/%02d/%04d | %-14s |\n",
               books[i].bookId, books[i].title, books[i].author, books[i].quantity,
               books[i].publication.date, books[i].publication.month, books[i].publication.year, books[i].price);
    }
    printf("|======|==============================|=====================|====|============|================|\n");
}

void addBook(){// them sach++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    if (bookCount == MAX_BOOK)
    {
        printf("The library is full. Cannot add more books.\n");
        return;
    }
    getBookId(books[bookCount].bookId);
    getBookTitle(books[bookCount].title);
    getBookAuthor(books[bookCount].author);
    getBookQuantity(&books[bookCount].quantity);
    getPublicationDate(&books[bookCount].publication.date, &books[bookCount].publication.month, &books[bookCount].publication.year);
    getPrice(books[bookCount].price);
    bookCount++;
    printf("Book added successfully.\n");
    saveBookData();
}

void editBook(){
    char idB[10];
    printf("Enter id of book to edit:...");
    scanf("%s", idB);
    for (int i = 0; i < bookCount; i++)
    {
        if (strcmp(books[i].bookId, idB) == 0)
        {
           
            getBookTitle(books[i].title);
            getBookAuthor(books[i].author);
            getBookQuantity(&books[i].quantity);
            getPublicationDate(&books[i].publication.date, &books[i].publication.month, &books[i].publication.year);
            getPrice(books[i].price);
            saveBookData();
            printf("Book edited");
            return;
        }
        else("Book not found.\n");
    }
    
}

void deleteBook(){
    char idB[10];
    printf("Edit id of book to remove:...");
    scanf("%s", &idB);
    for (int i = 0; i < bookCount; i++)
    {
        if (strcmp(books[i].bookId, idB) == 0)
        {
            for (int j = i; j < bookCount -1; j++)
            {
                books[j] = books[j+1];
            }
            bookCount--;
            printf("Book removed!");
            saveBookData();
            return;
        }
    }
}

void searchBook(){
    char title[30];
    printf("Enter title to search:...");
    getchar(); 
    fgets(title, 30, stdin);
    title[strcspn(title, "\n")] = '\0'; 
    for (int i = 0; i < bookCount; i++)
    {
        if (strcmp(books[i].title, title) == 0)
        {
            printf("|====|===============================|=====================|====|============|================|\n");
            printf("| %-2s | %-29s | %-19s | %-2d | %02d/%02d/%04d | %-14s |\n", 
            books[i].bookId, books[i].title, books[i].author, books[i].quantity, 
            books[i].publication.date, books[i].publication.month, books[i].publication.year, books[i].price);
            printf("|====|===============================|=====================|====|============|================|\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void Sort(){
    int choice;
    printf("sort by...\n");
    printf("[1] Highest price.\n");
    printf("[2] Lowest price\n");
    printf("[0] Exit\n");
    printf("Enter the choice...");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        for (int i = 0; i < bookCount; i++)
        {
            int maxIdx = i;
            for (int j = i + 1; j < bookCount; j++)
            {
                if (strcmp(books[j].price, books[maxIdx].price) > 0)
                {
                    maxIdx = j;
                }
                
            }
            if (maxIdx != i)
            {
                Book temp = books[i];
                books[i] = books[maxIdx];
                books[maxIdx] = temp;
            }
            
        }
        printf("Sorted by highest price.\n");
        break;
    case 2:
        for (int i = 0; i < bookCount; i++)
        {
            int minIdx = i;
            for (int j = i + 1; j < bookCount; j++)
            {
                if (strcmp(books[j].price, books[minIdx].price) < 0)
                {
                    minIdx = j;
                }
                
            }
            if (minIdx != i)
            {
                Book temp = books[i];
                books[i] = books[minIdx];
                books[minIdx] = temp;
            }
            
        }
        printf("Sorted by lowest price.\n");
        break;
    case 0:
        printf("Returning to main menu...\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
}

// ========================================================================================================
// menu book(admin)++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void showBookManagement(){
    printf("***library management System\n");
    printf("\t\tADMIN MENU\n");
    printf("\t======================\n");
    printf("\t[1] Book list.\n");
    printf("\t[2] Add new book.\n");
    printf("\t[3] Edit book information\n");
    printf("\t[4] Delete book\n");
    printf("\t[5] Search\n");
    printf("\t[6] Sort\n");
    printf("\t[0] Back to main menu\n");
    printf("\t======================\n");
    printf("Enter The Choice...");
}

void bookManagement(){
    int choice;
    do {
        showBookManagement();
        scanf("%d", &choice);
        getchar();
        clearScreen();
        switch (choice) {
            case 1:
                displayBooklist();
                break;
            case 2:
                addBook();
                break;
            case 3:
                editBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                searchBook();
                break;
            case 6:
                Sort();
                break;
            case 0:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}
