#include <stdio.h>
#include <string.h>
int main(){
	
	char userSys[] = "admin";
	char passSys[] = "Trung3110";
	char user[100];
	char pass[100];
	
	printf("\n+==========[THONG TIN DANG NHAP]==========+\n");
	printf(" Moi nhap vao username: ");
	gets(user);
	printf(" Moi nhap vao password: ");
	gets(pass);
	printf("+=========================================+\n");
	
	if(strcmp(user, userSys) == 0 && strcmp(pass, passSys) == 0){
	printf(" Dang nhap thanh cong");
	}else {
	printf( "Dang nhap khong thanh cong");
	}
	return 0;
}
