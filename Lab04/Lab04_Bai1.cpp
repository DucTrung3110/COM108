#include <stdio.h>
int main(){
int min, max;
int i;
float tong = 0, bienDem = 0, trungBinh = 0;

printf("Nhap gia tri min: ");
scanf("%d", &min);
printf("Nhap gia tri max: ");
scanf("%d", &max);

if(min>max){
printf("Min phai nho hon max\n");
return 1;
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
 return 0;
}
