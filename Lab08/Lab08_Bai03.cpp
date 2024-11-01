#include <stdio.h>
#include <string.h>

// Tao kieu du lieu sinh vien
struct sinhVien{
	char mssv[50];
	char tenSV[50];
	char nganhHoc[50];
	float diemTB;
};

int main(){
	struct sinhVien mangSV[50]; // Khai bao mang sinh vien
	int i, j, n;
	
	// Nhap so luong sinh vien
	printf("\n Nhap so sinh vien moi them: ");
	scanf("%d", &n);
	getchar(); // tu nhan ky tu xuong dong con lai sau khi nhap so
	
	// Nhap thong tin cho tung sinh vien
	for(i = 0; i < n; i++){
		printf("\n Nhap vao thong tin sinh vien thu %d :\n ", i + 1);
		printf("Nhap MSSV: ");
		fgets(mangSV[i].mssv, sizeof(mangSV[i].mssv), stdin);
		printf(" Nhap ten sinh vien: ");
		fgets(mangSV[i].tenSV, sizeof(mangSV[i].tenSV), stdin);
		printf(" Nhap nganh hoc: ");
		fgets(mangSV[i].nganhHoc, sizeof(mangSV[i].nganhHoc), stdin);
		printf(" Nhap diem trung binh: ");
		scanf("%f", &mangSV[i].diemTB);
		getchar(); //  Nhan ky tu con lai sau khi nhap diem
	}
	
	// Giat thuat sap xep sinh vien theo diem trung binh tang dan
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			if(mangSV[i].diemTB > mangSV[j].diemTB){
			// Hoan doi sinh vien
			struct sinhVien svTemp = mangSV[i];
			mangSV[i] = mangSV[j];
			mangSV[j] = svTemp;
			}
		}
	}
	
	
	// Xuat thong tin tat ca cac sinh vien
	printf("\n+===============[DANH SACH SINH VIEN]===============+ \n");
	for(i = 0; i< n; i++){
		printf("\n__________[THONG TIN SV THU %d]__________\n", i + 1);
		printf("|\n");
		printf("|MSSV: %s", mangSV[i].mssv);
		printf("|Ten sinh vien: %s", mangSV[i].tenSV);
		printf("|Nganh hoc: %s", mangSV[i].nganhHoc);
		printf("|Diem trung binh: %.1f\n", mangSV[i].diemTB);
		printf("|_______________________________________\n");	
	}
	
	// Tim kiem sinh vien 
	char mssvTimKiem[50];
		printf("\n|-_-_-_-_-_[TIM KIEM SINH VIEN]_-_-_-_-_-|\n");
		printf("\n");
		printf(" Nhap vao MSSV can tim: ");
		fgets(mssvTimKiem, sizeof(mssvTimKiem), stdin);
	
	// Duyet qua mang sinh vien de tim kiem
	int found = 0;
	for(i = 0; i < n; i++){
	// So sanh MSSV can tim voi tung sinh vien trong mang
	if(strcmp(mssvTimKiem, mangSV[i].mssv) == 0){
		found = 1;
		printf("\n+==========[THONG TIN SINH VIEN DUOC TIM THAY]==========+\n");
			printf("|\n");
            printf("|MSSV: %s", mangSV[i].mssv);
            printf("|Ten sinh vien: %s", mangSV[i].tenSV);
            printf("|Nganh hoc: %s", mangSV[i].nganhHoc);
            printf("|Diem trung binh: %.1f\n", mangSV[i].diemTB);
            printf("|_______________________________________\n");    
            break; // Dung vong lap khi tim thay sinh vien
	}
	}
	if(!found){
		printf("\n Khong tim thay sinh vien voi MSSV: %s\n", mssvTimKiem);
	}
	
	
	return 0;
}
