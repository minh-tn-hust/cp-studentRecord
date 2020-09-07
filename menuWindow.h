#include <ncurses.h>
WINDOW *create_unselectedWin(int height, int width, int starty, int startx,char *s)
{
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	mvprintw(starty+height/2,startx+(width-strlen(s))/2,"%s",s);
	wrefresh(local_win);	
	return local_win;
}
WINDOW *create_selectedWin(int height, int width, int starty, int startx,char *s)
{
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win,0,0);
	attron(A_BOLD|A_REVERSE);
	mvprintw(starty+height/2,startx+(width-strlen(s))/2,"%s",s);
	attroff(A_REVERSE|A_BOLD);
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
int selected[4][2]={
		{1,2},
		{3,4},
		{5,6},
		{7,8}
};
char buttonLabel[4][2][30]={
	{"1. Add student","2. Search Student"},
	{"3. Modify Student Record","4. Generate Marksheet"},
	{"5. Delete Student Record","6. Change Password"},
	{"7. Exit","Have a nice day"},
};
void initMenuWindow(){
	WINDOW *win;
	refresh();
	int count,count1;
	char s[]="STUDENT RECORD MENU";
	attron(A_BOLD);
	mvprintw(2,29-strlen(s)/2,"%s",s);
	attroff(A_BOLD);// in đậm dòng tiêu đề
	win = create_selectedWin(25,58,0,0,""); //tạo khung ngoài của chương trình
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
