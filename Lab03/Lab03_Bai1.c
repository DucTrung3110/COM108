#include <stdio.h>
int main(){
float diemSinhVien;

printf("Nhap vao diem sinh vien: ", diemSinhVien);
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
