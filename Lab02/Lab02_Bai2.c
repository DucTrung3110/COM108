#include <stdio.h>
// Cong thuc tinh dien tich = dai*rong
// Cong thuc tinh chu vi = 2*(dai + rong)
int main(){
float dienTich, chuVi, dai, rong;
printf("Nhap vao chieu dai hinh chu nhat:\n ");
scanf("%f", &dai);

printf("Nhap vao chieu rong hinh chu nhat:\n");
scanf("%f", &rong);

chuVi = 2*(dai+rong);
dienTich = dai*rong;

printf("Chu vi hinh chu nhat la: %.2f\n", chuVi);
printf("Dien tich hinh chu nhat la: %.2f\n", dienTich);
return 0;
}
