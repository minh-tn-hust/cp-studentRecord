#include <stdio.h>
#include <stdlib.h>
#include "drawFrame.h"
#include <ncurses.h>
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
		int choose;
		char c;
		int check=0;
		c = getchar();
		if (c == '\033'){
			c = getchar();
			c = getchar();
			check = 1;
		}
		endwin();
		gotoxy(12,22);
		if (check == 1||(c>='1'&& c<='9')){
		switch(c){
			case '1':printf("Case 1: ok");break;
			case '2':printf("Case 2: ok");break;
			case '3':printf("Case 3: ok");break;
			case '4':printf("Case 4: ok");break;
			case '5':printf("Case 5: ok");break;
			case '6':printf("Case 6: ok");break;
			case 65: printf("Up ok");break;
		    case 66: printf("DOwn ok");break;
			case 67: printf("Right ok");break;
			case 68: printf("Left ok");break;
		}
		}
	}
}
int main(void){
	initscr();
	cbreak();
	system("clear");
	menu();
	load();
}
