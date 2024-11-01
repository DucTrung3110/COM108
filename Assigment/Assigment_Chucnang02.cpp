#include <stdio.h>
#include <stdlib.h>

// Ham tinh uoc so chung lon nhat cua 2 so ap dung thuat toan Euclid
int uocSoChung(int a, int b){
	a = abs(a); 
	b = abs(b);
while(b != 0){
	int temp = b;
	b = a % b;
	a = temp;
}
return a;
}

// Ham tinh boi uoc chung nho nhat cua 2 so dua vao uocSoChung
int boiSoChung(int a, int b){
	return (abs(a) * abs(b))/uocSoChung(a, b); // su dung cong thuc boi uoc chung
}

int main(){
	int x, y;
	printf("Nhap vao so nguyen x: ");
	scanf("%d", &x);
	printf("Nhap vao so nguyen y: ");
	scanf("%d", &y);
	
	// Tinh uocSoChung va boiUocChung
	int ucln = uocSoChung(x, y);
	int bcnn = boiSoChung(x, y);
	
	printf("\n+==================KET QUA=================+\n");
	printf("|Uoc so chung lon nhat cua %d va %d la: %d |\n", x, y, ucln);
	printf("|Boi so chung nho nhat cua %d va %d la: %d |\n", x, y, bcnn);
	printf("+==========================================+\n");
return 0;
}

