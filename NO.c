#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "menuWindow.h"
//================================================================================================
typedef struct student{
	char ID[15];
	char NAME[30];
	char ADDRESS[30];
	char PHONE[30];
} stu;
stu* addInfo(stu* info){
	echo();
	mvprintw(3,7,"");getstr(info->ID);
	mvprintw(5,9,"");getstr(info->NAME);
	mvprintw(7,12,"");getstr(info->ADDRESS);
	mvprintw(9,17,"");getstr(info->PHONE);
	return info;
}
void initWindow1st(){
	WINDOW *win;
	refresh();
	char title[] = "ADD STUDENT";
	win = create_selectedWin(12,58,0,0,"");
	attron(A_BOLD|A_REVERSE);
	mvprintw(1,(58-strlen(title))/2,title);
	attroff(A_REVERSE);
	mvprintw(3,3,"ID: ");
	mvprintw(5,3,"NAME:");
	mvprintw(7,3,"ADDRESS:");
	mvprintw(9,3,"PHONE NUMBER:");
	attroff(A_BOLD|A_REVERSE);
	stu *node = malloc(sizeof(stu));
	addInfo(node);
	FILE *f = fopen("student.txt","a");
	fwrite(&node,sizeof(stu),1,f);
	fclose(f);
}
// ===========================================================================================================================
stu list[100];
void initWindow2nd(){
	FILE *f = fopen("student.txt","r");
	int count=0;
	while (fread(&list[count],sizeof(stu),1,f)){
		count++;
	}
	fclose(f);
	clear();
	WINDOW *win;
	refresh();
	int numberOfStu = count;
	for (count =0; count < numberOfStu;count++)	
		printw("==%20s==%20s==%20s==%20s\n",list[count].ID,list[count].NAME,list[count].ADDRESS,list[count].PHONE);
}
//===========================================================================================================================
void menu(){
	WINDOW *win;
	int posy = 0,posx = 0;// posy,posx dùng làm biến để xác định trong trong mang xyOfBox, dùng để di chuyển 
	int c;
	int check=1;
	while(c = getch()){
		if (check == 0){
			initMenuWindow();
			check = 1;
		}
		switch(c){
			case '1':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 0;posx=0;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case '2':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 0;posx=1;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case '3':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 1;posx=0;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case '4':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 1;posx=1;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case '5':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 2;posx=0;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case '6':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 2;posx=1;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case '7':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 3;posx=0;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case KEY_LEFT:
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				if (posx >0) posx--; 
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case KEY_RIGHT:
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				if (posx <1)
				   if (posy != 3) posx++;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case KEY_UP:
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				if (posy >0) posy--;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case KEY_DOWN:
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				if (posy <3){
					if (posx == 0)
						posy++;
					else
						if (posy<2)
							posy++;
				}	
				
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				break;
			case '\n':
				switch(selected[posy][posx]){
					case 1:mvprintw(30,60,"Case 1: OK");clear();initWindow1st();check = 0;break;
					case 2:mvprintw(30,60,"Case 2: OK");initWindow2nd();check = 0;break;
					case 3:mvprintw(30,60,"Case 3: OK");break;
					case 4:mvprintw(30,60,"Case 4: OK");break;
					case 5:mvprintw(30,60,"Case 5: OK");break;
					case 6:mvprintw(30,60,"Case 6: OK");break;
					case 7:mvprintw(30,60,"Case 7: OK");break;

				}
				

		}	
	}

}
int main(){
	initscr();
	cbreak();
	keypad(stdscr,TRUE);
	noecho();
	initMenuWindow();
	menu();
	getch();
	endwin();

}
