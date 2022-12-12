#include <stdio.h>
#include <stdlib.h>

struct Book{
	char title[100];
	char author[100];
	int year;
};

typedef struct Book Book;

void loadBook(Book *book){
	printf("Title: \n");
	scanf(" %[^\n]s", book->title);
	printf("Author: \n");
	scanf(" %[^\n]s", book->author);
	printf("Year: \n");
	scanf(" %d", &book->year);
}

void printBook(Book *book){
	printf("Title: %s\n", book->title);
	printf("Author: %s\n", book->author);
	printf("Year: %d\n", book->year);
}

int main(){
	int n;
	Book *book;

	printf("Enter number of books: \n");
	scanf("%d", &n);
	book = (Book*) malloc(n*sizeof(Book));

	for(int i=0; i<n; i++){
		loadBook(&book[i]);
	}

	for(int i=0; i<n; i++){
		printf("\nBook %d\n", i);
		printBook(&book[i]);
	}

	return 0;
}