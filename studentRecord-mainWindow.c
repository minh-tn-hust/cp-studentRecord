#include <stdio.h>
int gotoxy(int y, int x){
	printf("\033[%d;%dH",y,x);
}
char buttonLabel[8][60]={
	{"1. Add student"},
	{"2. Search Student"},
	{"3. Modify Student Record"},
	{"4. Generate Marksheet"},
	{"5. Delete Student Record"},
	{"6. Change Password"},
	{"7. Exit"},
	{"What do you want:"}
};
int mapButton[8][2]={ // [0] is y and [1] is x
	{3,4}, //1. Add Student
	{3,35},//2. Search Student
	{6,4}, //3. Modify Student Record
	{6,35},//4. Generate Marksheet
	{9,4}, //5. Delete Student Record
	{9,35},//6. Change Student Record
	{12,4},// 7. Exit
	{12,4}
};
int drawColumn(){
	int count;
	for (count = 1; count < 13; count++) printf("|\033[D\033[B");
}
int drawRow(int n){
	int count;
	for (count = 0; count < n; count++) printf("%c",((count==28&&n!=59)||(n==58&&count == 57))?'|':'_');
}
int drawWindowFrame(){
	gotoxy(1,1);
	int count;
	drawRow(59);// Top Edge
	gotoxy(2,1);
	drawColumn();
	gotoxy(2,59);
	drawColumn();
	gotoxy(2,30);
	drawColumn();
	gotoxy(13,2);
	drawRow(58);// Bottom Edge
	gotoxy(4,2);
	drawRow(57);// Normal Edge
	gotoxy(20,20);
	gotoxy(7,2);
	drawRow(57);// Normal Edge
	gotoxy(10,2);
	drawRow(57);// Normal Edge
	gotoxy(20,20);
}
int mainWindow(){
	int count;
	for (count = 0; count<8; count++){
		gotoxy(mapButton[count][0],mapButton[count][1]);
		printf("%s",buttonLabel[count]);
	}
}
int main(void){
	mainWindow();
	drawWindowFrame();

}

