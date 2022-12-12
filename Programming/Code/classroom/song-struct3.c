#include <stdio.h>
#include <string.h>

struct Song{
	char title[100];
	char artist[100];
	int year;
};

typedef struct Song Song;

// void createSong(Song song){
// 	Song song;
// 	printf("Title: \n");
// 	scanf("%[^\n]s", &song.title);
// 	printf("Artist: \n");
// 	scanf(" %[^\n]s", &song.artist);
// 	printf("Year: \n");
// 	scanf("%d", &song.year);
// }

void updateSong(Song *song){
	printf("Title: \n");
	scanf("%[^\n]s", song->title);
	printf("Artist: \n");
	scanf(" %[^\n]s", song->artist);
	printf("Year: \n");
	scanf("%d", &song->year);
}

void printSong(Song song){
	printf("Title: %s\n", song.title);
	printf("Artist: %s\n", song.artist);
	printf("Year: %d\n", song.year);
}
int main(){
	Song song_1 = {.title = "Love Song", .artist = "Sara Bareiles", .year = 2009};
	Song song_2;

	song_2 = song_1;
	printSong(song_2);
	updateSong(&song_2);
	printSong(song_2);
	// createSong(song_3);
	return 0;
}