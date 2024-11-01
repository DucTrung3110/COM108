#include <stdio.h>
int main(){
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
printf("Tong so tien la: %.3lf dong\n", soTien);
return 0;
}
