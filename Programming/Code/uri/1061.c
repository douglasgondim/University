#include <stdio.h>
#include <string.h>
int main(){
	char line[50], trash[50]; 
	int startDay, startHr, startMin, startSec, endDay, endHr, endMin, endSec, seconds;
	scanf("%[^\n]s", line);
	sscanf(line, "%s %d", trash, &startDay);
	scanf("%[^\n]s", line);
	sscanf(line, "%d %s %d %s %d", startHr, trash, startMin, trash, startSec);
	scanf("%[^\n]s", line);
	sscanf(line, "%s %d", trash, &endDay);
	scanf("%[^\n]s", line);
	scanf(line, "%d %s %d %s %d", endHr, trash, endMin, trash, endSec);

	seconds = (endDay-startDay)*86400 - 




	return 0;
}