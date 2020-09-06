#include <ncurses.h>
#include <string.h>

// Vẽ cửa sổ khi chưa được chọn
WINDOW *create_unselectedWin(int height, int width, int starty, int startx,char *s)
{
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
	mvprintw(starty+height/2,(startx+width-strlen(s))/2,"%s",s);
	wrefresh(local_win);	
	return local_win;
}
//Vẽ cửa sổ khi đã được chọn
WINDOW *create_selectedWin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;
	local_win = newwin(height, width, starty, startx);
	box(local_win,0,0);
	wrefresh(local_win);	
	return local_win;
}






int main(){
	WINDOW *win;
	int width,height,startx,starty;
	initscr();
	cbreak();
	height = 3;
	width = 5;
	startx = 1;
	starty = 1;
	refresh();
	win = create_unselectedWin(5,25,10,10,"Hello");
	wrefresh(win);
	getch();
	endwin();

}
