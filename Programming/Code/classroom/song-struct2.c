#include <stdio.h>

struct Song{
	char title[100];
	char artist[100];
	char album[100];
	int year;
};

typedef struct Song Song;

int main(){
	Song song_1 = { .title = "Truce", .artist = "twenty one pilots", .album = "Vessel", .year = 2013};
	Song *song_ptr;
	printf("Title: %s\n", song_1.title);
	printf("Artist: %s\n", song_1.artist);
	printf("Album: %s\n", song_1.album);
	printf("Year: %d\n", song_1.year);

	song_ptr = &song_1;
	printf("\n---------------------\n");
	printf("Title: %s\n", (*song_ptr).title);
	printf("Artist: %s\n", (*song_ptr).artist);
	printf("Album: %s\n", (*song_ptr).album);
	printf("Year: %d\n", (*song_ptr).year);

	printf("\n-------------------------\n");

	printf("Title: %s\n", song_ptr->title);
	printf("Artist: %s\n", song_ptr->artist);
	printf("Album: %s\n", song_ptr->album);
	printf("Year: %d\n", song_ptr->year);


	return 0;
}