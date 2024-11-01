#include <stdio.h>
int main(){
float toan, ly, hoa, diemTrungBinh;
printf("Nhap vao diem toan: ", toan);
scanf("%f", &toan);
printf("Nhap vao diem ly: ", ly);
scanf("%f", &ly);
printf("Nhap vao diem hoa: ", hoa);
scanf("%f", &hoa);
diemTrungBinh = (toan * 3 + ly * 2 + hoa * 1) / (3 + 2 + 1);
printf("Diem trung binh cua hoc sinh la: %d\n", (int)diemTrungBinh);
return 0; 
}

