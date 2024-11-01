#include <stdio.h>

int main(){
int n, i, count = 0;
float tong = 0, trungBinh;

	// Nhap so phan tu cua mang
	printf("\n Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	
	// Tao mang voi n phan tu
	int mang[n];
	
	// Nhap cac phan tu vao mang
	for(i = 0; i < n; i++){
	printf("\n Nhap phan tu thu %d : ", i + 1);
	scanf("%d", &mang[i]);
	} 
	
	// Duyet mang va tinh tong cac so chia het cho 3
	for(i = 0; i < n; i++){
		if(mang[i] % 3 == 0){
			tong += mang[i]; // cong vao tong
			count++; // Tang bien dem va luu tru so so luong cac phan tu chia het cho 3
		}
	}
	
	// Tinh va xuat gia tri trung binh
	if(count > 0){
		trungBinh = tong / count;
		printf("\n Trung binh tong cac so chia het cho 3 la: %.2f\n", trungBinh);
	}else {
	printf(" Khong co so nao chia het cho 3 trong mang\n");
	}
	return 0;
}
