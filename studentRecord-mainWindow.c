#include <stdio.h>
#include <stdlib.h>
#include "drawFrame.h"
int load(){
	FILE *f;
	f = fopen(f,"student.txt");
	if (f == NULL)
		printf("Can't note connect to Database");
	else printf("Connect success");
}
int menu(){
	while(1){
		mainWindow();	
		drawWindowFrame();
		int  choose;
		scanf("%d",&choose);
		switch(choose){
			case 1: // Add student
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7: break;
		}
		
	}
}
int main(void){
	system("clear");
	menu();
	load();
}
