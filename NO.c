#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "menuWindow.h"
//================================================================================================
typedef struct student{
	char ID[15];
	char NAME[30];
	char ADDRESS[50];
	char PHONE[30];
} stu;
void addInfo(){
	stu *node = malloc(sizeof(stu));
	FILE *f = fopen("student.txt","a+");
	echo();
	mvprintw(3,7,"");getstr(node->ID);
	mvprintw(5,9,"");getstr(node->NAME);
	mvprintw(7,12,"");getstr(node->ADDRESS);
	mvprintw(9,17,"");getstr(node->PHONE);
	fwrite(node,sizeof(stu),1,f);
	fclose(f);
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
	addInfo();
}
// ===========================================================================================================================
stu list[100];
void drawRowUnselected(stu *node,int index){
	WINDOW *win;
	refresh();
	win = create_unselectedWin(3,17,index*2+3,1,node->ID);
	win = create_unselectedWin(3,32,index*2+3,18,node->NAME);
	win = create_unselectedWin(3,52,index*2+3,50,node->ADDRESS);
	win = create_unselectedWin(3,32,index*2+3,102,node->PHONE);
	wrefresh(win);
	
}
void drawRowSelected(stu *node,int index){
	WINDOW *win;
	refresh();
	win = create_selectedWin(3,17,index*2+3,1,node->ID);
	win = create_selectedWin(3,32,index*2+3,18,node->NAME);
	win = create_selectedWin(3,52,index*2+3,50,node->ADDRESS);
	win = create_selectedWin(3,32,index*2+3,102,node->PHONE);
	wrefresh(win);
	
}
void initWindow2nd(){
	FILE *f = fopen("student.txt","r");
	int count=0;
	if (f == NULL) {
		clear();
		refresh();
		WINDOW *win;
		char warning[]="NO DATASE.TXT - PLEASE CHECK YOUR FILE";
		win = create_selectedWin(3,135,0,0,warning);
	}
	else{
	while (fread(&list[count],sizeof(stu),1,f)){
		count++;
	}
	fclose(f);
	clear();
	WINDOW *win;
	refresh();
	int numberOfStu = count;
	char _2title[]="SEARCH STUDENT";
	attron(A_BOLD|A_REVERSE);
	mvprintw(1,(135-strlen(_2title))/2,_2title);
	attroff(A_BOLD|A_REVERSE);
	mvprintw(1,135-20,"ID: ");
	win = create_selectedWin(numberOfStu*2+5,135,0,0,"");
	for (count = 0; count < numberOfStu; count++)
		drawRowUnselected(&list[count],count);
	mvprintw(1,135-15,"");
	echo();
	char ID[15];
	int checkID = 0;
	getstr(ID);
	for (count = 0; count < numberOfStu; count++)
		if (strcmp(ID,list[count].ID)==0){
			drawRowSelected(&list[count],count);			
		}
	}
}
//===========================================================================================================================
void menu(){
	WINDOW *win;
	int posy = 0,posx = 0;// posy,posx dùng làm biến để xác định trong trong mang xyOfBox, dùng để di chuyển 
	int c;
	int check=1;
	while(c = getch()){
		if (check == 0){
			clear();
			refresh();
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
					case 7:return 1;

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
