#include <stdio.h>
#include <math.h>

// Ham kiem tra xem x co phai so nguyen to hay khong
int kiemTraSoNguyenTo(int n){
if(n < 2){
return 0; // so nho hon 2 nen khong phai so nguyen to
}
for(int i = 2; i <= sqrt(n); i++){
	if(n % i == 0){
	return 0; // neu n co uoc so khac 1 va chinh no thi khong phai so nguyen to
	}
}
return 1; // n la so nguyen to
}

int kiemTraSoChinhPhuong(int n){
int canBacHai = sqrt(n);
return (canBacHai * canBacHai == n); // neu can bac 2 cua n la so nguyen thi n la so chinh phuong
}

int main(){
float x;
int soNguyen;

printf("Nhap vao so x: ");
scanf("%f", &x);

// Kiem tra xem x co phai so nguyen hay khong
if(x == (int)x){
soNguyen = (int)x;
printf("%.0f la so nguyen\n", x);

// Kiem tra so nguyen to
if(kiemTraSoNguyenTo(soNguyen)){
printf("%d la so nguyen to\n", soNguyen);
}else{
printf("%d khong phai la so nguyen to\n", soNguyen);
}

// Kiem tra so chinh phuong
if(kiemTraSoChinhPhuong(soNguyen)){
	printf("%d la so chinh phuong\n", soNguyen);
}else{
	printf("%d khong phai la so chinh phuong\n", soNguyen);
}

}else{
	printf("%.2f khong phai so nguyen to\n", x);
}
return 0;
}

