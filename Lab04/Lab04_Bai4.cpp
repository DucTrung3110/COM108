#include <stdio.h>
#include <stdbool.h>
void Bai1(){
int min, max;
int i;
float tong = 0, bienDem = 0, trungBinh = 0;

printf("Nhap gia tri min: ");
scanf("%d", &min);
printf("Nhap gia tri max: ");
scanf("%d", &max);

if(min>max){
printf("Min phai nho hon max\n");
return;
}
i=min;

while(i<=max){
if(i%2==0){
tong += i;
bienDem++;
}
i++;
}
if(bienDem==0){
printf("Khong co so nao chia het cho 2 khoang tu %d den %d\n", min, max);
}else{
trungBinh = tong/bienDem;
printf("trung binh tong cac so chia het cho 2 tu %d den %d la: %d\n",min, max, (int)trungBinh);
 }
 return;
}

void Bai2(){
	int x, i, count = 0;
	printf("Nhap vao so nguyen: ");
	scanf("%d", &x);
	
	if(x<2){
		printf("%d khong phai la so nguyen to\n", x);
		return;
	}
	
	for(i=2; i<x; i++){
		if(x%i==0){
			count++;
			break;
		}
	}if(count==0){
		printf("%d la so nguyen to\n", x);
	}else{
		printf("%d khong phai la so nguyen to\n", x);
	}
	return;
}

void Bai3(){
	int x, i, count = 0;
	printf("Nhap vao so x: ");
	scanf("%d", &x);

	for(i=1; i<x; i++){
		if(i*i==x){
			count++;
			break;
		}
	}
		if(count==1){
			printf("%d la so chinh phuong\n", x);
		}
		else {
			printf("%d khong phai la so chinh phuong\n", x);
		}

	return;
}

int main(){
	int choice;
	
	do{
		printf("\n++------------[Menu]-------------++\n");
		printf("|Chuc nang 1: Tinh trung binh tong|\n");
		printf("|Chuc nang 2: Tim so nguyen to    |\n");
		printf("|Chuc nang 3: Tim so chinh phuong |\n");
		printf("|Chuc nang 4: Thoat               |\n");
		printf("++-------------------------------++\n");
		printf("Xin moi lua chon chuc nang (1,2,3,4): ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
			Bai1();
				break;
			case 2:
			Bai2();
				break;
			case 3: 
			Bai3();
				break;
			case 4:
				printf("Thoat chuong trinh\n");
				break;
			default:
				printf("Ban nhap sai. Vui long nhap lai");
				break;
			
	}
	}
	while(choice!=4);
	return 0;
	}
