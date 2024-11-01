#include <stdio.h>
int main(){
	float a,b;
	printf("Nhap vao so a: ");
	scanf("%f", &a);
	printf("Nhap vao so b: ");
	scanf("%f", &b);
	if(a==0 && b==0){
		printf("Phuong trinh co vo so nghiem\n");
	}else if(a==0 && b!=0){
		printf("Phuong trinh vo nghiem\n");
	}else{
		float x = -b/a;
		printf("Phuong trinh co nghiem x = %.2f", x);
	}
}
