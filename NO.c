#include <ncurses.h>
#include <string.h>

// Vẽ cửa sổ khi chưa được chọn
WINDOW *create_unselectedWin(int height, int width, int starty, int startx,char *s)
{
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	mvprintw(starty+height/2,startx+(width-strlen(s))/2,"%s",s);
	wrefresh(local_win);	
	return local_win;
}
//Vẽ cửa sổ khi đã được chọn
WINDOW *create_selectedWin(int height, int width, int starty, int startx,char *s)
{
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win,0,0);
	attron(A_BLINK);
	attron(A_REVERSE);
	mvprintw(starty+height/2,startx+(width-strlen(s))/2,"%s",s);
	attroff(A_REVERSE);
	attroff(A_BLINK);
	wrefresh(local_win);	
	return local_win;
}
int xyOfBox[4][2][2]={
	{{4,2},{4,29}},
	{{9,2},{9,29}},
	{{14,2},{14,29}},
	{{19,2},{19,29}},
};
char buttonLabel[4][2][30]={
	{"1. Add student","2. Search Student"},
	{"3. Modify Student Record","4. Generate Marksheet"},
	{"5. Delete Student Record","6. Change Password"},
	{"7. Exit","Have a nice day"},
};
void initWindow(){
	WINDOW *win;
	initscr();
	cbreak();
	refresh();
	int count,count1;
	char s[]="STUDENT RECORD";
	attron(A_BOLD);
	mvprintw(2,29-strlen(s)/2,"%s",s);
	attroff(A_BOLD);
	win = create_selectedWin(25,58,0,0,"");
	for (count = 0; count < 4; count++)
		for (count1 = 0; count1 < 2;count1++){
			if (count==0&&count1==0) { 
				win = create_selectedWin(5,27,xyOfBox[count][count1][0],xyOfBox[count][count1][1],buttonLabel[count][count1]); 
				wrefresh(win);
				continue;
			}
			win = create_unselectedWin(5,27,xyOfBox[count][count1][0],xyOfBox[count][count1][1],buttonLabel[count][count1]);
			wrefresh(win);
		}
}
void menu(){
	WINDOW *win;
	int posy = 0,posx = 0;// posy,posx dùng làm biến để xác định trong trong mang xyOfBox, dùng để di chuyển 
	int selected = 1;
	int c;
	while(c = getch()){
		switch(c){
			case '1':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 0;posx=0;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				selected = 1;
				break;
			case '2':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 0;posx=1;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				selected = 1;
				break;
			case '3':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 1;posx=0;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				selected = 1;
				break;
			case '4':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 1;posx=1;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				selected = 1;
				break;
			case '5':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 2;posx=0;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				selected = 1;
				break;
			case '6':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 2;posx=1;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				selected = 1;
				break;
			case '7':
				win = create_unselectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				posy= 3;posx=0;
				win = create_selectedWin(5,27,xyOfBox[posy][posx][0],xyOfBox[posy][posx][1],buttonLabel[posy][posx]); 
				selected = 1;
				break;
		}	
	}

}
int main(){
	initscr();
	cbreak();
	keypad(stdscr,TRUE);
	noecho();
	initWindow();
	menu();
	getch();
	endwin();

}
