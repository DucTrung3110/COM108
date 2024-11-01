#include <stdio.h>

float timGiaTriLonNhat(float so1, float so2, float so3){
	float max = so1;
	if(so2>max){
		max=so2;
	}
	if(so3>max){
		max=so3;
	}
	return max;
}

int main(){
	float so1, so2, so3;
	printf("\n Nhap so thu nhat: ");
	scanf("%f", &so1);
	printf(" Nhap so thu hai: ");
	scanf("%f", &so2);
	printf(" Nhap so thu ba: ");
	scanf("%f", &so3);
	
	float soMax = timGiaTriLonNhat(so1, so2, so3);
	printf("\n So lon nhat la: %.1f\n", soMax);
	return 0;
}
