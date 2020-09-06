#include <stdio.h>
#include <string.h>
FILE *f;
char s; 
struct student{
	char  ID[15];
	char name[50];
	char address[50];
	char phoneNumber[20];
};
int numberOfStudent;
struct student stuList[100];
// Hàm in ra thông tin thí sinh, cần bỏ vào trong thư viện để dễ dàng gọi ===========================================
int printStu(struct student *s){
	printf("%20s%50s%50s%20s\n",s->ID,s->name,s->address,s->phoneNumber);
}
//==================================================================================================================

int load(){ // Đã chạy ổn định
	f = fopen("student.txt","r+");
	int count = 0;
	if (f == NULL) printf("Loading that bai, file student.txt chua ton tai\n");
	else {
		printf("Succes loading\n");
		s = getc(f);
		fseek(f,0,SEEK_SET);
		while(fread(&stuList[count],sizeof(struct student),1,f)){
			count++;
		}
	return count;
	}
}
int deleteRecord(){// Phần này đã chạy ổn định==============================================================  
	if (s == EOF) {
	printf("Empty Database\n");
	return 1;
	}
	else{
		int count;
		for (count =0; count < numberOfStudent; count++){
			printStu(&stuList[count]);
		}
		char c;
		scanf("%*c");
		char ID[15];
		printf("Nhap ID ban muon xong");gets(ID);
		fclose(f);
		f = fopen("student.txt","w");
		fseek(f,0,SEEK_SET);
		for (count = 0; count < numberOfStudent; count++){
			if ( strcmp(ID,stuList[count].ID) == 0)
				continue;
			else
				fwrite(&stuList[count],sizeof(struct student),1,f);
		}
		fclose(f);
		numberOfStudent = load();
	}
}


int modStudent(){// chạy ổn định, chưa thấy lỗi nào cả==========================================================
	system("clear");
	if (s == EOF) {
	printf("Empty Database\n");
	return 1;
	}
	else{
		int count;
		for (count =0; count < numberOfStudent; count++){
			printStu(&stuList[count]);
		}
		char c;
		scanf("%*c");
		char ID[15];
		printf("Nhap ID ban muon chinh sua");gets(ID);
		for (count = 0; count < numberOfStudent; count++){
			if (strcmp(ID,stuList[count].ID) == 0 ) {
				system("clear");
				char name[50];
				printf("Name: ");gets(stuList[count].name);
				// Ở đây cần có một hàm để check ID
				char address[50];
				printf("Address: ");gets(stuList[count].address);
				char phoneNumber[20];
				printf("Phone number: ");gets(stuList[count].phoneNumber);
				break;
			}
		}
		fseek(f,0,SEEK_SET);
		fseek(f,(count)*sizeof(struct student),SEEK_SET);
		fwrite(&stuList[count],sizeof(struct student),1,f);
		fclose(f);
		numberOfStudent = load();
	}
}
//=================================================================================================



int searchStudent(){// chạy thành công -- chờ nâng cấp ==============================================
	char c;
	scanf("%c",&c);
	if (s == EOF) {
	printf("Empty Database\n");
	return 1;
	}
	else{
		system("clear");
		int count;
   		for (count =0; count < numberOfStudent; count++){
			printStu(&stuList[count]);
		}
	char	ID[15];
	int check = 0;
	printf("Nhap ID:");gets(ID);
	for (count = 0; count < numberOfStudent; count++)
		if (strcmp(ID,stuList[count].ID) == 0){
			printStu(&stuList[count]);
			check = 1;
		}
	if (check == 0) printf("Not found\n");
	}
}
//==================================================================================================



int addStudent(){// add thì mình thêm vào mảng listStudent và thêm vào cả trong student.txt
	scanf("%*c");
	struct student stu;
	system("clear");
	char name[50];
	printf("Name: ");gets(stu.name);
	char id[30];
	printf("ID: ");gets(stu.ID);
	// Ở đây cần có một hàm để check ID
	char address[50];
	printf("Address: ");gets(stu.address);
	char phoneNumber[20];
	printf("Phone number: ");gets(stu.phoneNumber);
	fwrite(&stu,sizeof(stu),1,f);
	printf("Add success!");
	fclose(f);
	numberOfStudent = load();

}
int markSheet(){

}
int changePassword(){

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
			case 5:deleteRecord();break;
			case 6:changePassword();break;
			case 7: return 1;
		}
	}
}
int main(void){
	numberOfStudent = load();
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
