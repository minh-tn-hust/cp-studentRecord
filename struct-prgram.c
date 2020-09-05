#include <stdio.h>
FILE *f;
char s; 
struct student{
	char  ID[15];
	char name[50];
	char address[20];
	char phoneNumber[20];
};




struct student stuList[100];
int load(){
	f = fopen("student.txt","a+");
	int count = 0;
	if (f == NULL) printf("Loading fail\n");
	else {
		// load thành công sẽ load thẳng vào mảng stuList để có thể sử dụng
		// việc thêm + tìm kiếm và sắp xếp sẽ diễn ra trong mảng này
		// còn việc chỉnh sửa và xóa sẽ thao tác trực tiếp trên fil
		// e, để tối ưu số lần load thì có thể lưu lại vị trí 
		printf("Succes loading\n");
		s = getc(f);
		fseek(f,0,SEEK_SET);
		while(fread(&stuList[count],sizeof(struct student),1,f)){
			count++;
		}
	return count;
	}
}
int deleteStudent(){
	if (s == EOF) {
	printf("Empty Database\n");
	return 1;
	}
	else{
	system("rm student.txt");

	}
}
int modStudent(){
	if (s == EOF) {
	printf("Empty Database\n");
	return 1;
	}
	else{

	}
}
int searchStudent(){
	if (s == EOF) {
	printf("Empty Database\n");
	return 1;
	}
	else{

	}
}
int addStudent(){// add thì mình thêm vào mảng listStudent và thêm vào cả trong student.txt
	scanf("%*c");
	struct student stu;
	system("clear");
	char name[20];
	printf("Name: ");gets(stu.name);
	char id[20];
	printf("ID: ");gets(stu.ID);
	char address[20];
	printf("Address: ");gets(stu.address);
	char phoneNumber[20];
	printf("Phone number: ");gets(stu.phoneNumber);
	fwrite(&stu,sizeof(stu),1,f);
	printf("Add success!");

}
int markSheet(){

}
int changePassword(){

}
int printStu(struct student *s){
	printf("%20s%20s%20s%20s\n",s->ID,s->name,s->address,s->phoneNumber);
}
int menu(){
	while(1){
		printf("1. Add student\n");
		printf("2. Search Student\n");
		printf("3. Modify Student Record\n");
		printf("4. Generate Marksheet\n");
		printf("5. Delete Student Record\n");
		printf("6. Change Password\n");
		printf("7. Exit\n");
		printf("What do you want: ");
		int choose;
		scanf("%d",&choose);
		switch(choose){
			case 1:addStudent();break;
			case 2:searchStudent();break;
			case 3:modStudent();break;
			case 4:markSheet();break;
			case 5:deleteStudent();break;
			case 6:changePassword();break;
			case 7: return 1;
		}
	}
}
int main(void){
	int numberOfStudent = load();
	if (s == EOF) {
		printf("Empty Database\n");
	}
	else{
		int count;
		for (count = 0; count < numberOfStudent; count++)
			printStu(&stuList[count]);
	}
	menu();
	fclose(f);
}
