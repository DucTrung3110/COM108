#include <stdio.h>

struct DIENTHOAI{
	char maSP[50];
	char tenSP[50];
	float gia;
};

int main(){
		struct DIENTHOAI mangSP[50]; 
	int i,j, n;
	
	printf("\n Nhap so san pham moi them: ");
	scanf("%d", &n);
	getchar(); 
	
	for(i = 0; i < n; i++){
		printf("\n Nhap vao thong tin dien thoai thu %d :\n ", i + 1);
		printf("Nhap Ma san pham: ");
		fgets(mangSP[i].maSP, sizeof(mangSP[i].maSP), stdin);
		printf(" Nhap ten san pham: ");
		fgets(mangSP[i].tenSP, sizeof(mangSP[i].tenSP), stdin);
		printf(" Nhap gia san pham: ");
		scanf("%f", &mangSP[i].gia);
		getchar();
	}
	
		for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			if(mangSP[i].gia > mangSP[j].gia){
			// Hoan doi sinh vien
			struct DIENTHOAI spTemp = mangSP[i];
			mangSP[i] = mangSP[j];
			mangSP[j] = spTemp;
			}
		}
	}
	
	
	printf("\n+===============[DANH SACH DIEN THOAI]===============+ \n");
	for(i = 0; i< n; i++){
		printf("\n__________[THONG TIN DIEN THOAI THU %d]__________\n", i + 1);
		printf("|\n");
		printf("|Ma san pham: %s", mangSP[i].maSP);
		printf("|Ten san pham: %s", mangSP[i].tenSP);
		printf("|Gia mo ta: %.1f\n", mangSP[i].gia);
		printf("|_______________________________________\n");	
	}
	return 0;
}


