#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct book
{
    char title[100];
    char author[100];
    char isbn[20];
    char edition[20];
    int numCopy;


};



void addBooks(){

    FILE *fptr = fopen("books.txt", "a");
    struct book newBook;

    printf("Add book Title: \n");
    gets(newBook.title);

    printf("Add book Author: \n");
    gets(newBook.author);

    printf("Add book ISBN: \n");
    gets(newBook.isbn);

    printf("Add book edition: \n");
    gets(newBook.edition);

    printf("Add book number of copy: \n");
    scanf("%d", &newBook.numCopy);



    fputs(newBook.title, fptr);
    fprintf(fptr, "\n");
    fputs(newBook.author, fptr);
    fprintf(fptr, "\n");
    fputs(newBook.isbn, fptr);
    fprintf(fptr, "\n");
    fputs(newBook.edition, fptr);
    fprintf(fptr, "\n");
    fprintf(fptr,"%d", newBook.numCopy);
    fprintf(fptr, "\n");

    fclose(fptr);



}

void showBooks(){
    FILE *fptr = fopen("books.txt", "r");

    struct book booklist[2000];
    int index = 0;
    int trc = 0;
    char singleBook[100];
    while(fgets(singleBook, sizeof singleBook , fptr) != NULL){
        if(index == 0){
            strcpy(booklist[trc].title, singleBook);
            index++;
        }
        else if( index == 1){
            strcpy(booklist[trc].author, singleBook);
            index++;
        }
        else if( index == 2){
            strcpy(booklist[trc].isbn, singleBook);
            index++;
        }
        else if ( index == 3){
            strcpy(booklist[trc].edition, singleBook);
            index++;
        }
        else if( index == 4){
            int n = 0;
            int s = sizeof(singleBook) / sizeof(singleBook[0]);
            int t = 0;
            for(int i  = s - 1; i >= 0 ; i--){
                n += pow(singleBook[0] - '0' , t);
                t++;
            }
            booklist[trc].numCopy = n;
            index = 0;
            trc++;
        }
    }
    for(int i = 0; i < trc - 1; i++ ){
            puts(booklist[i].title);
            puts(booklist[i].author);
            puts(booklist[i].isbn);
            puts(booklist[i].edition);
            printf("%d", booklist[i].numCopy);
            printf("\n");
            printf("\n");
            printf("\n");
        }
    fclose(fptr);
}



int main(){
    int choice;



    while (true){
        printf("Press 1 for add student. \nPress 2 for show all books. \nPress 7 for exit.");

        scanf("%d", &choice);
        char buffer[5];
        gets(buffer);
        if(choice == 1){
            addBooks();
        }
        else if(choice == 2){
            showBooks();
        }
        else if(choice == 7){
            return 0;
        }
    }





}
