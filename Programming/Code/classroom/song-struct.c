#include <stdio.h>
#include <string.h>

struct Song{
		char title[100];
		char artist[100];
		char album[50];
		int length;
		int year;
	};


int main(){
	struct Song song_1, song_2;
	strcpy(song_1.title, "Stressed Out");
	strcpy(song_1.artist, "twenty one pilots");
	strcpy(song_1.album, "Blurryface");
	song_1.length = 200;
	song_1.year = 2015;

	printf("Title: %s\n", song_1.title);
	printf("Artist: %s\n", song_1.artist);
	printf("Album: %s\n", song_1.album);
	printf("Length: %d\n", song_1.length);
	printf("Year: %d\n", song_1.year);

	printf("\n---------------------\n");
	printf("Title: \n");
	scanf("%[^\n]s", song_2.title);
	printf("Artist: \n");
	scanf(" %[^\n]s", song_2.artist);
	printf("Album: \n");
	scanf(" %[^\n]s", song_2.album);
	printf("Length: \n");
	scanf("%d", &song_2.length);
	printf("Year: \n");
	scanf("%d", &song_2.year);


	printf("Title: %s\n", song_2.title);
	printf("Artist: %s\n", song_2.artist);
	printf("Album: %s\n", song_2.album);
	printf("Length: %d\n", song_2.length);
	printf("Year: %d\n", song_2.year);


	return 0;
}