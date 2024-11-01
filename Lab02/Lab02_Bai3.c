#include <stdio.h>
#define PI 3.1416
int main(){
float banKinh, chuVi, dienTich;
printf("Nhap vao ban kinh cua hinh tron: ", banKinh);
scanf("%f", &banKinh);
chuVi = 2*PI*banKinh;
dienTich = PI*banKinh*banKinh;
printf("Chu vi cua hinh tron la: %.2f\n", chuVi);
printf("Dien tich cua hinh tron la: %.2f\n", dienTich);
return 0;
}
