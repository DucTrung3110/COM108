#include <stdio.h>
#include <math.h>
#include <stdbool.h>
void bai1(){   

	
float diemSinhVien;

printf("Nhap vao diem sinh vien: ");
scanf("%f", &diemSinhVien);

while(diemSinhVien < 0 || diemSinhVien >10){
printf("Ban nhap sai. Vui long nhap lai: ");
scanf("%f", &diemSinhVien);
}
if(diemSinhVien>=9){
printf("Hoc sinh xuat sac");
}
else if(diemSinhVien < 9 && diemSinhVien >= 8){
printf("Hoc sinh gioi");
}
else if(diemSinhVien < 8 && diemSinhVien >=6.5){
printf("Hoc sinh kha");
}
else if(diemSinhVien < 6.5 && diemSinhVien >= 5){
printf("Hoc sinh trung binh");
}
else if(diemSinhVien  <5 && diemSinhVien >= 3.5){
printf("Hoc sinh yeu");
}
else{
printf("Hoc sinh kem");
}
}

void bai2_1(){
	
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

void bai2_2(){
float a,b,c;
printf("Nhap vao so a: ");
scanf("%f", &a);
printf("Nhap vao so b: ");
scanf("%f", &b);
printf("Nhap vao so c: ");
scanf("%f", &c);

if(a==0){
	if(b==0){
	if(c==0){
	printf("Phuong trinh co vo so nghiem\n");
	}else{
	printf("Phuong trinh vo nghiem\n");
	}
	}else{
	float x = -c / b;
	printf("Phuong trinh co nghiem x = %.2f\n", x);
	}
	
}else{
	float delta = pow(b,2)-4*a*c;
	
	if(delta<0){
	printf("Phuong trinh vo nghiem\n");
	}else if(delta==0){
	float x = -b/(2*a);
	printf("Phuong trinh co nghiem kep x = %.2f\n", x);
	}
	else {
	float sqrtDelta = sqrt(delta);
	float x1 = (-b + sqrtDelta)/(2*a);
	float x2 = (-b - sqrtDelta)/(2*a);
	printf("Phuong trinh co 2 nghiem phan biet:\n");
	printf("x1 = %.2f\n", x1);
	printf("x2 = %.2f\n", x2);
	}
	}
}

void bai3(){
int kWh;
double soTien;

printf("Nhap vao so dien tieu thu hang thang: ");
scanf("%d", &kWh);

while(kWh <= 0 ){
printf("Ban nhap sai. Vui long nhap lai: ");
scanf("%d", &kWh);
}

if(kWh <= 50){
 soTien = kWh*1.678;
}
else if(kWh >= 51 && kWh <= 100){
 soTien = 50*1.678 + (kWh-50)*1.734;
}
else if(kWh >= 101 && kWh < 200){
 soTien = 50*1.678 + 50*1.734 + (kWh-100)*2.014;
}
else if(kWh >= 201 && kWh <= 300){
 soTien = 50*1.678 + 50*1.734 + 100*2.014 + (kWh - 200)*2.536;
}
else if(kWh >= 301 && kWh <= 400){
 soTien = 50*1.678 + 50*1.734 + 100*2.014 + 100*2.536 + (kWh - 300)*2.834;
}
else{
 soTien = 50*1.678 + 50*1.734 + 100*2.014 + 100*2.536 + 100*2.834 + (kWh - 400)*2.927;
}
printf("So tien la: %.3lf dong\n", soTien);
}

int main(){
int choice;
do{
printf("\n^__________[Menu]__________^\n");
printf("|                          |\n");
printf("|1. Bai tap 1              |\n");
printf("|2. Bai tap 2.1            |\n");
printf("|3. Bai tap 2.2            |\n");
printf("|4. Bai tap 3              |\n");
printf("|0. Thoat                  |\n");
printf("|__________________________|\n");
printf(" Nhap lua chon cua ban: ");
scanf("%d", &choice);

switch(choice){
	case 1:
		bai1();
		break;
	case 2:
		bai2_1();
		break;
	case 3:
		bai2_2();
		break;
	case 4:
		bai3();
		break;
	case 0:
		printf("Thoat chuong trinh\n");
		break;
	default:
		printf("Ban nhap sai lua chon. Vui long nhap lai\n");
		break;
		
}
}
while(choice!=0);

return 0;
}
