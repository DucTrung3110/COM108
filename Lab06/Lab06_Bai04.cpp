#include <stdio.h>

int main(){
	
	int n, m, i, j;
	
	// Nhap vao so hang va cot cua ma tran
	printf("\n Nhap vao so hang n: ");
	scanf("%d", &n);
	printf(" Nhap vao so cot m: ");
	scanf("%d", &m);
	
	// Tao mang 2 chieu voi kich thuoc n hang va m cot
	int mang[n][m];
	
	// Nhap du lieu vao mang 2 chieu
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf(" Nhap gia tri cua mang[%d][%d]: ", i, j);
			scanf("%d", &mang[i][j]);
		}
	}
	
	// Xuat mang binh phuong cua cac phan tu 3
	printf("\n+==========[KET QUA]==========+\n"); 
	printf(" Ma tran binh phuong la: \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			// Tinh binh phuong cua tung phan tu roi in ra
			printf(" %d ", mang[i][j] * mang[i][j]); 
		} 
		printf("\n"); 
	} 
	
	return 0; 
}
