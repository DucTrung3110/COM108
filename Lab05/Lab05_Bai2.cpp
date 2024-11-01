#include <stdio.h>
int main(){
	int namNhuan;
	printf("\n Nhap vao so nam: ");
	scanf("%d", &namNhuan);
	namNhuan = (namNhuan%4==0 && namNhuan%100!=0) || (namNhuan%400==0);
	if(namNhuan){
		printf("\n Nam nhuan\n");
	}else{
		printf("\n Nam khong nhuan\n");
	}
	return 0;
}
