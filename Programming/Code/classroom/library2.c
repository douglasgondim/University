#include <stdio.h>
#define SIZE 100

struct Book{
	int code;
	char title[100];
	char author[100];
	int isbn;
	int year;
};

typedef struct Book Book;

void loadBook(Book *book, int code){
	book->code = code;
	setbuf(stdin, NULL);
	printf("Title: \n");
	scanf("%[^\n]s", book->title);
	setbuf(stdin, NULL);
	printf("Author: \n");
	scanf("%[^\n]s", book->author);
	setbuf(stdin, NULL);
	printf("ISBN: \n");
	scanf("%d", &book->isbn);
	printf("Year: \n");
	scanf("%d", &book->year);
}

void printBook(Book *book){
	printf("Title: %s\n", book->title);
	printf("Author: %s\n", book->author);
	printf("ISBN: %d\n", book->isbn);
	printf("Year: %d\n", book->year);
}

void startLibrary(Book *library){
	for(int i=0; i<SIZE; i++){
		library[i].code = -1;
	}
}

void registerBook(Book *library, int code){
	for(int i=0; i<SIZE; i++){
		if(library[i].code == -1){
			loadBook(&library[i], code);
			break;
		}
	}

}



int main(){
	int code;
	Book library[SIZE];

	startLibrary(library);

	printf("Enter book's code: \n");
	scanf("%d", &code);

	while(code != -1){
		printf("Register a book: \n");
		registerBook(library, code);
		printf("Enter book's code: \n");
		scanf("%d", &code);
	}

	for(int i=0; i<SIZE; i++){
		if(library[i].code != -1){
			printBook(&library[i]);
		}
	}


	return 0;
}