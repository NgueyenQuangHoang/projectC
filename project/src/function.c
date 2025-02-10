#include "../include/datatype.h"

#define MAX_BOOK 100

Book books[MAX_BOOK];
int bookCount = 0;

void loadBookData(){
    FILE *file = fopen("book.dat", "rb");
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
    FILE *file = fopen("book.dat", "wb");
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

// Phan function cua Admin++++++++++++++++++++++++++++++++++++++
void displayBooklist(){
    if (bookCount == 0)
    {
        printf("[-HOLLOW-]\n");
        return;
    }
    printf("\t\t\t\t\t**BOOK LIST**\n");
    printf("|===|==============================|====================|===|==========|\n");
    printf("|ID | Title                        | Author             |Qty| Published|\n");
    for (int i = 0; i < bookCount; i++)
    {
        printf("|%-3s| %-30s| %-20s| %-3d| %d/%d/%d|\n", books[i].bookId, books[i].title, books[i].author, books[i].quantity, books[i].publication.month, books[i].publication.date, books[i].publication.year);
    }
    printf("|===|==============================|====================|===|==========|\n");
}

// them sach++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void addBook(){
    if (bookCount == MAX_BOOK)
    {
        printf("The library is full. Cannot add more books.\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%s", books[bookCount].bookId);
    printf("Enter book title: ");
    getchar(); // Clear the newline character left by scanf
    fgets(books[bookCount].title, 30, stdin);
    printf("Enter author: ");
    fgets(books[bookCount].author, 20, stdin);
    printf("Enter quantity: ");
    scanf("%d", &books[bookCount].quantity);
    printf("Enter publication date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &books[bookCount].publication.month, &books[bookCount].publication.date, &books[bookCount].publication.year);
    bookCount++;
    printf("Book added successfully.\n");
    saveBookData();
}

// =======================================================================================================
// menu chinh+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void mainMenu(){
    printf("***library management Systerm\n");
    printf("\t\tCHOOSE YOUR ROLE\n");
    printf("\t======================\n");
    printf("\t[1] Admin.\n");
    printf("\t[2] Member.\n");
    printf("\t[0] Exit\n");
    printf("\t======================\n");
    printf("Enter The Choice...");
}

// menu book(admin)++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void showAdminmenu(){
    printf("***library management Systerm\n");
    printf("\t\tADMIN MENU\n");
    printf("\t======================\n");
    printf("\t[1] Book list.\n");
    printf("\t[2] Add new book.\n");
    printf("\t[3] Edit book information\n");
    printf("\t[4] Delete book\n");
    printf("\t[5] Search\n");
    printf("\t[6] Sort\n");
    printf("\t======================\n");
    printf("Enter The Choice...");
}
void adminMenu(){
    int choice;
    showAdminmenu();
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        displayBooklist();
        break;
    case 2:
        addBook();
        break;
    case 3:
        // editBook();
        break;
    case 4:
        // deleteBook();
        break;
    case 5:
        // searchBook();
        break;
    case 6:
        // sortBook();
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
}
// menu book(student)++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void showCusmenu(){
    
}