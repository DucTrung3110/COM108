#include <stdio.h>

int main(){

int n, i , j, temp;
	// Nhap so phan tu cua mang
	printf(" Nhap vao so phan tu cua mang: ");
	scanf("%d", &n);
	
	int mang[n];
	// Nhap cac phan tu cua mang
	for(i = 0; i < n; i++){
		printf(" Nhap gia tri cua mang[%d]: ", i);
		scanf("%d", &mang[i]);	
	}
	
	// Sap xep mang theo thu tu giam dan 
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			if(mang[i] < mang[j]){
			// Doi vi tri mang[i] voi mang[j] neu mang[i] < mang[j]
			temp = mang[i];
			mang[i] = mang[j];
			mang[j] = temp;
			}
		}
	}
	// Xuat mang da sap xep
	printf("\n+===============[KET QUA]===============+\n");
	printf("| Mang sau khi sap xep giam dan: \n");
	for(i = 0; i < n; i++){
		printf("| Vi tri thu mang[%d] la: %d\n", i, mang[i]);
		
	}
	printf("+=======================================+\n");
	return 0;
}
