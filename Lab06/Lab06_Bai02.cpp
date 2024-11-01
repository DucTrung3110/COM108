#include <stdio.h>

int main(){
int n, i;

	// Nhap vao so han tu n
	printf("\n Nhap vao so phan tu n: ");
	scanf("%d", &n);

	int mang[n];
	
	// Nhap vao so phan tu n trong mang
	for(i = 0; i < n; i++){
	printf(" Nhap vao phan tu thu %d : ", i + 1);
	scanf("%d", &mang[i]);
}

	int max = mang[0],
	 min = mang[0];
	 
	
	// Duyet mang và tim gia tri lon nhat, nho nhat
	for(i = 0; i < n; i++){
		if(mang[i] > max){
		max = mang[i];
		}
		
		if(mang[i] < min){
		min = mang[i];
		}
		
	}
	printf("\n Gia tri lon nhat trong mang la: %d\n", max);
	printf(" Gia tri nho nhat trong mang la: %d\n", min);
	
	return 0;
}
