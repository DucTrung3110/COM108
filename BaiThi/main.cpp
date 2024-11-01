#include <stdio.h>
#include <string.h>

// Bai 1
void bai1(){
	
 int n, i;
    
    // Nhap so luong phan tu trong mang
    printf("\n Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    
    int mang[n];
    
    // Nhap cac phan tu cua mang
    printf("\n Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        printf("\n Phan tu thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
    
    // Xuat ra cac so le trong mang
    printf("\n Cac so le trong mang: ");
    for (i = 0; i < n; i++) {
        if (mang[i] % 2 != 0) {
            printf("%d ", mang[i]);
        }
    }
    
    // Tinh tong cac so chia het cho 5
    int tong = 0;
    for (i = 0; i < n; i++) {
        if (mang[i] % 5 == 0) {
            tong += mang[i];
        }
    }
    
    // Xuat ket qua tong
    printf("\n Tong cac so chia het cho 5: %d\n", tong);
    
}




// Bai 2
struct DIENTHOAI{
	char maSP[50];
	char tenSP[50];
	float gia;
};

void bai2(){

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
		printf("|_______________________________________________\n");	
	}

}



int main(){

	int choice;
	
	do{
		printf("\n +==========[MENU]==========+\n");
		printf(" | 1. Bai 1                 |\n");
		printf(" | 2. Bai 2                 |\n");
		printf(" | 0. Thoat chuong trinh    |\n");
		printf(" +==========================+\n");
		printf(" Moi ban chon chuong trinh: ");
		scanf("%d", &choice);
		
		switch(choice)
		{	
			case 1: bai1(); break;
			case 2: bai2(); break;
			case 0: printf("\n Cam on ban da su dung chuong trinh. Tam biet va hen gap lai!\n"); break;
			default: printf("\n Ban nhap sai. Vui long nhap lai\n");
		}
		
	
	}	while(choice != 0);
	
	return 0;
}
