#include <stdio.h>
#include <string.h>

// Ham tinh tien
double tinhTien(int gioBatDau, int phutBatDau, int gioKetThuc, int phutKetThuc, int weeKend){
int soGio = gioKetThuc - gioBatDau;
int soPhut = phutKetThuc - phutBatDau;
double tongTien = 0;

// Dieu chinh so phut neu phutKetThuc < phutBatDau
if(soPhut < 0){
	soPhut += 60; // cong them 1 tieng
	soGio--; // tru di 1 tieng
}

// Xu ly truong hop hat qua ngay
if(gioKetThuc < gioBatDau){
soGio = (24 - gioBatDau) + gioKetThuc; // cong them so gio tu 24 gio
}
// Neu duoi 1 tieng van tinh tien la 1 tieng
if(soGio < 1){
	tongTien = 150000;
}else{
// Tinh tien cho 3 gio dau tien
if(soGio <= 3){
	tongTien = soGio * 150000;
}else{
	tongTien = 3 * 150000 + (soGio - 3) * 150000 *0.7;
}
// Tinh tien cho so phut, so le(neu co, va phai tren 1 tieng)
if(soGio >= 1 && soPhut > 0){
	tongTien += (soPhut/60.0) * 150000;
}
}

// Neu nam trong khung gio tu 14h den 17h thi giam 10%
if((gioBatDau >= 14 && gioBatDau < 17) || (gioKetThuc > 14 && gioKetThuc <= 17)){
	tongTien *= 0.9;
}
// Tang gia vao 2 ngay cuoi tuan 20% (thu 7, chu nhat)
if(weeKend){
	tongTien *= 1.2; // nhan voi 1.2 tuc la dang nhan 100% gia goc + them 20% 
}
return tongTien;
}

// Ham ap dung ma voucher tu dong
double apDungVoucher(double tongTien, char *voucher, double *giamGia, int soGio){
if(soGio > 8){
	strcpy(voucher, "MaGiam15");
	*giamGia = tongTien * 0.15;
	return tongTien * 0.85; // giam gia 15% neu hat tren 8 tieng
}else if(soGio > 5){
	strcpy(voucher, "MaGiam10");
	*giamGia = tongTien * 0.10;
	return tongTien * 0.9; // giam gia 10% neu hat tren 5 tieng
}else if(soGio > 3){
	strcpy(voucher, "MaGiam05");
	*giamGia = tongTien * 0.05;
	return tongTien * 0.95; // giam gia 5% neu hat tren 3 tieng
}else {
	strcpy(voucher, "Khong co");
	*giamGia = 0;
	return tongTien; // khong giam
}
}

// Kiem tra ngay cuoi tuan
int cuoiTuan(int ngay){
	return(ngay == 7 || ngay == 8); // 7 = thu 7, 8 = chu nhat
}

// Ham xuat hoa don tinh tien 
void hienThiBill(int gioBatDau, int phutBatDau, int gioKetThuc, int phutKetThuc, int WeeKend, char *voucher, double tongTien, double giamGia) {
    printf("\n+=============== HOA DON ===============+\n");
    printf("| Gio bat dau: %02d:%02d               \n", gioBatDau, phutBatDau);
    printf("| Gio ket thuc: %02d:%02d              \n", gioKetThuc, phutKetThuc);
    printf("| Cuoi tuan: %s                        \n", WeeKend ? "Co" : "Khong");
    printf("| Ma voucher: %s                       \n", voucher);
    printf("| Giam gia: %.0lf VND                  \n", giamGia);
    printf("| Tong so tien: %.0lf VND              \n", tongTien);
    printf("+=======================================+\n");
}


int main() {
    int gioBatDau, phutBatDau, gioKetThuc, phutKetThuc, ngay;
    char voucher[20];  // Tang kich thuoc cho chuoi voucher
    double tongTien, giamGia;
    int WeeKend, soGio;


do{
// Hien thi bang nhap lieu
 // Hien thi bang nhap lieu
        printf("\n====================== NHAP THONG TIN =======================\n");
        printf("Nhap ngay trong tuan (1-6: Ngay Thuong, 7: Thu 7, 8: Chu nhat): ");
        scanf("%d", &ngay);
        
        printf("Nhap gio bat dau (0-24h): ");
        scanf("%d", &gioBatDau);
        printf("Nhap phut bat dau (0-59): ");
        scanf("%d", &phutBatDau);
        
        printf("Nhap gio ket thuc (0-24h): ");
        scanf("%d", &gioKetThuc);
        printf("Nhap phut ket thuc (0-59): ");
        scanf("%d", &phutKetThuc);

 // Kiem tra dieu kien nhap lieu hop le
if (ngay < 1 || ngay > 8 || gioBatDau < 0 || gioBatDau >= 24 || phutBatDau < 0 || phutBatDau > 59 ||
	gioKetThuc < 0 || gioKetThuc >= 24 || phutKetThuc < 0 || phutKetThuc > 59 || 
     (gioKetThuc == gioBatDau && phutKetThuc <= phutBatDau)) {
    	printf("\nThong tin nhap khong hop le. Vui long nhap lai!\n");
        }
    }while (ngay < 1 || ngay > 8 || gioBatDau < 0 || gioBatDau >= 24 || phutBatDau < 0 || phutBatDau > 59 ||
             gioKetThuc < 0 || gioKetThuc >= 24 || phutKetThuc < 0 || phutKetThuc > 59 || 
              (gioKetThuc == gioBatDau && phutKetThuc <= phutBatDau));

    WeeKend = cuoiTuan(ngay);

    // Tinh so gio hat
    if (gioKetThuc < gioBatDau || (gioKetThuc == gioBatDau && phutKetThuc < phutBatDau)){
        soGio = (gioKetThuc + 24) - gioBatDau;
    }else{
        soGio = gioKetThuc - gioBatDau;
    }

    // Tinh tong tien
    tongTien = tinhTien(gioBatDau, phutBatDau, gioKetThuc, phutKetThuc, WeeKend);

    // Ap dung ma voucher neu hat tren so gio quy dinh
    tongTien = apDungVoucher(tongTien, voucher, &giamGia, soGio);

    // Hien thi bill
    hienThiBill(gioBatDau, phutBatDau, gioKetThuc, phutKetThuc, WeeKend, voucher, tongTien, giamGia);

    return 0;
}
