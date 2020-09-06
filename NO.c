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
	{{1,0},{1,27}},
	{{6,0},{6,27}},
	{{11,0},{11,27}},
	{{16,0},{16,27}},
};
		//printf("1. Add student\n");
		//printf("2. Search Student\n");
		//printf("3. Modify Student Record\n");
		//printf("4. Generate Marksheet\n");
		//printf("5. Delete Student Record\n");
		//printf("6. Change Password\n");
		//printf("7. Exit\n");
		//printf("What do you want: ");

char buttonLabel[4][2][30]={
	{"1. Add student","2. Search Student"},
	{"3. Modify Student Record","4. Generate Marksheet"},
	{"5. Delete Student Record","6. Change Password"},
	{"7. Exit","Have a nice day"},
};
int main(){
	system("clear");
	WINDOW *win;
	int width,height,startx,starty;
	initscr();
	cbreak();
	height = 3;
	width = 5;
	startx = 1;
	starty = 1;
	refresh();
	int count,count1;
	for (count = 0; count < 4; count++)
		for (count1 = 0; count1 < 2;count1++){
			if (count==0&&count1==0) { win = create_selectedWin(5,27,xyOfBox[count][count1][0],xyOfBox[count][count1][1],buttonLabel[count][count1]); 
			wrefresh(win);
			continue;
			}
			win = create_unselectedWin(5,27,xyOfBox[count][count1][0],xyOfBox[count][count1][1],buttonLabel[count][count1]);
			wrefresh(win);
		}
	getch();
	endwin();

}
