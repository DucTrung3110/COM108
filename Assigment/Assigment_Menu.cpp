#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SINH_VIEN 100  // So luong sinh vien toi da (bai 8)

// Bài 1: Kiem tra so nguyen va so chinh phuong

// Ham kiem tra xem x co phai so nguyen to hay khong
int kiemTraSoNguyenTo(int n){
if(n < 2){
return 0; // so nho hon 2 nen khong phai so nguyen to
}
for(int i = 2; i <= sqrt(n); i++){
	if(n % i == 0){
	return 0; // neu n co uoc so khac 1 va chinh no thi khong phai so nguyen to
	}
}
return 1; // n la so nguyen to
}

int kiemTraSoChinhPhuong(int n){
int canBacHai = sqrt(n);
return (canBacHai * canBacHai == n); // neu can bac 2 cua n la so nguyen thi n la so chinh phuong
}

void Bai1(){
	
float x;
int soNguyen;

printf("Nhap vao so x: ");
scanf("%f", &x);

// Kiem tra xem x co phai so nguyen hay khong
if(x == (int)x){
soNguyen = (int)x;
printf("%.0f la so nguyen\n", x);

// Kiem tra so nguyen to
if(kiemTraSoNguyenTo(soNguyen)){
printf("%d la so nguyen to\n", soNguyen);
}else{
printf("%d khong phai la so nguyen to\n", soNguyen);
}

// Kiem tra so chinh phuong
if(kiemTraSoChinhPhuong(soNguyen)){
	printf("%d la so chinh phuong\n", soNguyen);
}else{
	printf("%d khong phai la so chinh phuong\n", soNguyen);
}

}else{
	printf("%.1f khong phai so nguyen to\n", x);
}
}


// Bai 2: Tinh uoc chung lon nhat va boi chung nho nhat

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

void Bai2(){
	
	int x, y;
	printf("Nhap vao so nguyen x: ");
	scanf("%d", &x);
	printf("Nhap vao so nguyen y: ");
	scanf("%d", &y);
	
	// Tinh uocSoChung va boiUocChung
	int ucln = uocSoChung(x, y);
	int bcnn = boiSoChung(x, y);
	
	printf("\n+=======================KET QUA======================+\n");
	printf("| Uoc so chung lon nhat cua %d va %d la: %d              \n", x, y, ucln);
	printf("| Boi so chung nho nhat cua %d va %d la: %d             \n", x, y, bcnn);
	printf("+====================================================+\n");
}


// Bai 3: Tinh tien karaoke

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
    printf("+=======================================+\n");
    printf("| Tong so tien: %.0lf VND              \n", tongTien);
    printf("+=======================================+\n");
}

void Bai3(){

    int gioBatDau, phutBatDau, gioKetThuc, phutKetThuc, ngay;
    char voucher[20];  // Tang kich thuoc cho chuoi voucher
    double tongTien, giamGia;
    int WeeKend, soGio;


do{
// Hien thi bang nhap lieu
 // Hien thi bang nhap lieu
        printf("\n======================== NHAP THONG TIN =========================\n");
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
}


// Bài 4: Tinh tien dien tieu thu theo so kwh

void Bai4(){

int kWh;
double soTien;
	
	printf("Nhap vao so dien tieu thu hang thang: ");
    scanf("%d", &kWh);
 	printf("\n+===============[HOA DON]================+\n");
    // Kiem tra gia tri kWh hop le
    while (kWh <= 0) {
        printf("Ban nhap sai. Vui long nhap lai: ");
        scanf("%d", &kWh);
    }

    // Khai bao gia tang bac
    double giaBac1 = 1.678;
    double giaBac2 = 1.734;
    double giaBac3 = 2.014;
    double giaBac4 = 2.536;
    double giaBac5 = 2.834;
    double giaBac6 = 2.927;

    // Tinh tong tien theo bac tieu thu
    if (kWh <= 50) {
        soTien = kWh * giaBac1;
        printf("| So dien tieu thu: %d kWh              |\n", kWh);
        printf("| Gia: %.3lf dong/kWh|\n", giaBac1);
    } else if (kWh <= 100) {
        soTien = 50 * giaBac1 + (kWh - 50) * giaBac2;
        printf("| So dien tieu thu: %d kWh              |\n", kWh);
        printf("| Bac 1: 50 kWh * %.3lf dong/kWh         |\n", giaBac1);
        printf("| Bac 2: %d kWh * %.3lf dong/kWh         |\n", kWh - 50, giaBac2);
    } else if (kWh < 200) {
        soTien = 50 * giaBac1 + 50 * giaBac2 + (kWh - 100) * giaBac3;
        printf("| So dien tieu thu: %d kWh              |\n", kWh);
        printf("| Bac 1: 50 kWh * %.3lf dong/kWh         |\n", giaBac1);
        printf("| Bac 2: 50 kWh * %.3lf dong/kWh         |\n", giaBac2);
        printf("| Bac 3: %d kWh * %.3lf dong/kWh        |\n", kWh - 100, giaBac3);
    } else if (kWh <= 300) {
        soTien = 50 * giaBac1 + 50 * giaBac2 + 100 * giaBac3 + (kWh - 200) * giaBac4;
        printf("| So dien tieu thu: %d kWh              |\n", kWh);
        printf("| Bac 1: 50 kWh * %.3lf dong/kWh         |\n", giaBac1);
        printf("| Bac 2: 50 kWh * %.3lf dong/kWh         |\n", giaBac2);
        printf("| Bac 3: 100 kWh * %.3lf dong/kWh        |\n", giaBac3);
        printf("| Bac 4: %d kWh * %.3lf dong/kWh        |\n", kWh - 200, giaBac4);
    } else if (kWh <= 400) {
        soTien = 50 * giaBac1 + 50 * giaBac2 + 100 * giaBac3 + 100 * giaBac4 + (kWh - 300) * giaBac5;
        printf("| So dien tieu thu: %d kWh              |\n", kWh);
        printf("| Bac 1: 50 kWh * %.3lf dong/kWh         |\n", giaBac1);
        printf("| Bac 2: 50 kWh * %.3lf dong/kWh         |\n", giaBac2);
        printf("| Bac 3: 100 kWh * %.3lf dong/kWh        |\n", giaBac3);
        printf("| Bac 4: 100 kWh * %.3lf dong/kWh        |\n", giaBac4);
        printf("| Bac 5: %d kWh * %.3lf dong/kWh        |\n", kWh - 300, giaBac5);
    } else {
        soTien = 50 * giaBac1 + 50 * giaBac2 + 100 * giaBac3 + 100 * giaBac4 + 100 * giaBac5 + (kWh - 400) * giaBac6;
        printf("| So dien tieu thu: %d kWh              |\n", kWh);
        printf("| Bac 1: 50 kWh * %.3lf dong/kWh         |\n", giaBac1);
        printf("| Bac 2: 50 kWh * %.3lf dong/kWh         |\n", giaBac2);
        printf("| Bac 3: 100 kWh * %.3lf dong/kWh        |\n", giaBac3);
        printf("| Bac 4: 100 kWh * %.3lf dong/kWh        |\n", giaBac4);
        printf("| Bac 5: 100 kWh * %.3lf dong/kWh        |\n", giaBac5);
        printf("| Bac 6: %d kWh * %.3lf dong/kWh        |\n", kWh - 400, giaBac6);
    }
	printf("|________________________________________|\n");
    printf("      Tong so tien la: %.3lf dong\n", soTien);
    printf("|________________________________________|\n");
}


// Bai 5: Chuong trinh doi tien

void doiTien(int soTien) {
    int menhGia[] = {500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000}; // Cac menh gia tien
    int soTo;

    printf("So tien can doi: %d VND\n", soTien);
    printf("Cac menh gia tien duoc doi ra:\n");

    // Su dung vong lap de doi tien
    for (int i = 0; i < sizeof(menhGia) / sizeof(menhGia[0]); i++) {
        // Neu soTien bang voi mot trong cac menh gia, bo qua menh gia do
        if (soTien == menhGia[i]) {
            continue;
        }

        soTo = soTien / menhGia[i]; // Tinh so to can doi
        if (soTo > 0) {
            printf("%d to %d VND\n", soTo, menhGia[i]);
            soTien -= soTo * menhGia[i]; // Cap nhat so tien con lai
        }

        // Neu soTien da het, dung lai
        if (soTien == 0) {
            break;
        }
    }

    // Neu soTien con lai khong the doi duoc thi bao loi
    if (soTien > 0) {
        printf("So tien con lai khong the doi: %d VND\n", soTien);
    }
}


void Bai5(){

	int soTien;
    // Nhap so tien can doi
    printf("Nhap so tien can doi (VD: 2000000 cho 2 trieu): ");
    scanf("%d", &soTien);

    // Kiem tra so tien hop le
    if (soTien <= 0) {
        printf("So tien khong hop le. Phai la so duong\n");
        return; // Ket thuc chuong trinh voi ma loi
    }

    // Goi ham doi tien
    doiTien(soTien);
}


// Bai 6: Chuong trinh tinh lai suat ngan hang vay tra gop

void tinhLaiSuatVay(double soTienVay, double laiSuatNam, int thoiGian) {
    double tienLai, gocPhaiTra, tongTienTra, EMI;
    double soDuConLai = soTienVay;  // So du con lai ban dau la so tien vay

    // Tinh lai suat hang thang
    double laiSuatThang = laiSuatNam / 12 / 100;  

    // Tinh so tien tra deu moi thang (EMI) theo cong thuc chuan
    EMI = soTienVay * laiSuatThang * pow(1 + laiSuatThang, thoiGian) / (pow(1 + laiSuatThang, thoiGian) - 1);

    // Hien thi bang thong tin
    printf("\n+=======+=====================+=========================+=====================+===============+\n");
    printf("| %-6s| %-16s | %-16s | %-16s | %-14s|\n", "Thang", "Tien lai hang thang", "Goc phai tra hang thang", "Tong tra hang thang", "Du no con lai");
    printf("+=======+=====================+=========================+=====================+===============+\n");

    // Tinh toan lai va so tien phai tra hang thang
    for (int thang = 1; thang <= thoiGian; thang++) {
        // Tinh lai thang hien tai dua tren so du con lai
        tienLai = soDuConLai * laiSuatThang;  
        
        // Tinh tien goc tra moi thang
        gocPhaiTra = EMI - tienLai;  
        
        // Tong so tien phai tra trong thang nay (lai + goc)
        tongTienTra = tienLai + gocPhaiTra;  
        
        // Cap nhat so du con lai sau khi tra goc
        soDuConLai -= gocPhaiTra;

        // Neu so du con lai qua nho, ep thanh 0 de tranh hien thi sai
        if (soDuConLai < 0.000001 && soDuConLai > -0.000001) {
            soDuConLai = 0;
        }

        // In thong tin chi tiet tung thang theo bang
        printf("| %-6d| %-20.0f| %-24.0f| %-20.0f| %-14.0f|\n", thang, tienLai, gocPhaiTra, tongTienTra, soDuConLai);
    }

    // Tinh so tien can tra neu muon tat toan khoan vay som (them 3% phi tat toan)
    double soTienTatToan = soTienVay * 1.03; // Tinh 3% cua so tien vay

    // Cap nhat thong tin vao bang
    printf("|=============================================================================================|\n");
    printf("| %-6s | %-9.0f %-16s %-16s %-25s|\n", "So tien tat toan som", soTienTatToan, "VND", " ", " ");
    printf("|=============================================================================================|\n");

    // Hien thi tong so tien da tra sau khi het so thang da vay
    printf("| %-6s  | %-9.0f %-16s %-16s %-25s|\n", "Tong so tien da tra", EMI * thoiGian, "VND", " ", " ");
    printf("|_____________________________________________________________________________________________|\n");
}

void Bai6(){
double soTienVay;    // So tien vay
    double laiSuatNam;   // Lai suat theo nam
    int thoiGian;        // Thoi gian vay (so thang)

    // Nhap du lieu tu nguoi dung
    printf("\nNhap so tien muon vay (VD: 12000000): ");
    scanf("%lf", &soTienVay);

    printf("Nhap lai suat hang nam (VD: 5 cho 5%%): ");
    scanf("%lf", &laiSuatNam);

    printf("Nhap thoi gian vay (so thang, VD: 12): ");
    scanf("%d", &thoiGian);

    // Goi ham tinh toan va in ket qua
    tinhLaiSuatVay(soTienVay, laiSuatNam, thoiGian);
    
}


// Bai 7: Chuong trinh vay tien mua xe

void tinhLaiSuatVay(double giaXe, double phanTramVay, double laiSuatNam, int thoiGian) {
    double soTienVay, tienLai, gocPhaiTra, tongTienTra, EMI;
    double soDuConLai;

    // Tinh so tien vay dua tren gia xe va ty le vay
    soTienVay = giaXe * (phanTramVay / 100);
    soDuConLai = soTienVay;  // So du con lai ban dau la so tien vay

    // Tinh lai suat hang thang
    double laiSuatThang = laiSuatNam / 12 / 100;  

    // Tinh so tien tra deu moi thang (EMI) theo cong thuc chuan
    EMI = soTienVay * laiSuatThang * pow(1 + laiSuatThang, thoiGian) / (pow(1 + laiSuatThang, thoiGian) - 1);

    // Hien thi bang thong tin
    printf("\n+=======+=====================+=========================+=====================+===============+\n");
    printf("| %-6s| %-16s | %-16s | %-16s | %-14s|\n", "Thang", "Tien lai hang thang", "Goc phai tra hang thang", "Tong tra hang thang", "Du no con lai");
    printf("+=======+=====================+=========================+=====================+===============+\n");

    // Tinh toan lai va so tien phai tra hang thang
    for (int thang = 1; thang <= thoiGian; thang++) {
        // Tinh lai thang hien tai dua tren so du con lai
        tienLai = soDuConLai * laiSuatThang;  
        
        // Tinh tien goc tra moi thang
        gocPhaiTra = EMI - tienLai;  
        
        // Tong so tien phai tra trong thang nay (lai + goc)
        tongTienTra = tienLai + gocPhaiTra;  
        
        // Cap nhat so du con lai sau khi tra goc
        soDuConLai -= gocPhaiTra;

        // Neu so du con lai qua nho, ep thanh 0 de tranh hien thi sai
        if (soDuConLai < 0.000001 && soDuConLai > -0.000001) {
            soDuConLai = 0;
        }

        // In thong tin chi tiet tung thang theo bang
        printf("| %-6d| %-20.0f| %-24.0f| %-20.0f| %-14.0f|\n", thang, tienLai, gocPhaiTra, tongTienTra, soDuConLai);
    }

    // Tinh so tien can tra neu muon tat toan khoan vay som (them 3% phi tat toan)
    double soTienTatToan = soTienVay * 1.03; // Tinh 3% cua so tien vay

    // Cap nhat thong tin vao bang
    printf("|=============================================================================================|\n");
    printf("| %-6s | %-9.0f %-16s %-16s %-25s|\n", "So tien tat toan som", soTienTatToan, "VND", " ", " ");
    printf("|=============================================================================================|\n");

    // Hien thi tong so tien da tra sau khi het so thang da vay
    printf("| %-6s  | %-9.0f %-16s %-16s %-25s|\n", "Tong so tien da tra", EMI * thoiGian, "VND", " ", " ");
    printf("|_____________________________________________________________________________________________|\n");
}

void Bai7(){
 double giaXe;          // Gia xe
    double phanTramVay;   // Phan tram vay toi da
    double laiSuatNam;    // Lai suat theo nam
    int thoiGian;         // Thoi gian vay (so thang)

    // Nhap du lieu tu nguoi dung
    printf("\nNhap gia xe (VD: 500000000): ");
    scanf("%lf", &giaXe);

    printf("Nhap phan tram vay toi da (VD: 80 cho 80%%): ");
    scanf("%lf", &phanTramVay);

    printf("Nhap lai suat hang nam (VD: 7.2 cho 7.2%%): ");
    scanf("%lf", &laiSuatNam);

    printf("Nhap thoi gian vay (so thang, VD: 24): ");
    scanf("%d", &thoiGian);

    // Goi ham tinh toan va in ket qua
    tinhLaiSuatVay(giaXe, phanTramVay, laiSuatNam, thoiGian);
    
}


// Bai 8: Chuong trinh sap xep thong tin sinh vien theo diem so

// Cau truc de luu thong tin sinh vien
typedef struct {
    char hoTen[50];
    float diem;
    char hocLuc[20];
} SinhVien;

// Ham phan loai hoc luc dua tren diem
void phanLoaiHocLuc(SinhVien* sv) {
    if (sv->diem >= 9.0) {
        strcpy(sv->hocLuc, "Xuat sac");
    } else if (sv->diem >= 8.0) {
        strcpy(sv->hocLuc, "Gioi");
    } else if (sv->diem >= 6.5) {
        strcpy(sv->hocLuc, "Kha");
    } else if (sv->diem >= 5.0) {
        strcpy(sv->hocLuc, "Trung binh");
    } else {
        strcpy(sv->hocLuc, "Yeu");
    }
}

// Ham sap xep theo diem giam dan
void sapXepSinhVien(SinhVien* sv, int n) {
for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

void Bai8(){
SinhVien dsSinhVien[MAX_SINH_VIEN];  // Mang luu thong tin sinh vien
    int n;

    printf("\n +==========[NHAP THONG TIN]==========+");
    printf("\n Nhap so luong sinh vien: ");
    scanf("%d", &n);

    // Nhap thong tin sinh vien
    for (int i = 0; i < n; i++) {
        printf(" Nhap ho ten sinh vien %d: ", i + 1);
        getchar();  // Xoa bo dem
        fgets(dsSinhVien[i].hoTen, sizeof(dsSinhVien[i].hoTen), stdin);
        dsSinhVien[i].hoTen[strcspn(dsSinhVien[i].hoTen, "\n")] = '\0';  // Xoa ky tu newline

        printf(" Nhap diem sinh vien %d: ", i + 1);
        scanf("%f", &dsSinhVien[i].diem);

        // Kiem tra diem hop le
        while (dsSinhVien[i].diem < 0 || dsSinhVien[i].diem > 10) {
            printf(" Ban nhap sai. Vui long nhap lai: ");
            scanf("%f", &dsSinhVien[i].diem);
        }

        // Phan loai hoc luc
        phanLoaiHocLuc(&dsSinhVien[i]);
    }

    // Sap xep sinh vien theo diem giam dan
    sapXepSinhVien(dsSinhVien, n);

    // Hien thi thong tin sinh vien
    printf("\n |---------------------[BANG THONG TIN]-------------------|");
    printf("\n +==================+==================+==================+\n");
    printf(" | Ho ten           | Diem             | Hoc luc          |\n");
    printf(" +==================+==================+==================+\n");
    for (int i = 0; i < n; i++) {
        printf(" | %-16s | %-16.1f | %-16s |\n", dsSinhVien[i].hoTen, dsSinhVien[i].diem, dsSinhVien[i].hocLuc);
    }
    printf(" +==================+==================+==================+\n");

}


// Bai 9: Chuong Game FPOLY_LOTT(2/15)

void Bai9(){
 int soNgauNhien[2]; // Mang luu 2 so ngau nhien
    int soUser[2];      // Mang luu 2 so nguoi dung
    int trungSo = 0;    // Bien dem so trung

    // Khoi tao bo sinh so ngau nhien
    srand(time(NULL));

    // Sinh 2 so ngau nhien khac nhau tu 1 den 15
    while (trungSo < 2) {
        int num = (rand() % 15) + 1; // Sinh so tu 1 den 15
        int exists = 0;

        // Kiem tra so da duoc sinh ra chua
        for (int i = 0; i < trungSo; i++) {
            if (soNgauNhien[i] == num) {
                exists = 1; // So da ton tai
                break;
            }
        }

        // Neu so chua ton tai, them vao mang
        if (!exists) {
            soNgauNhien[trungSo] = num;
            trungSo++;
        }
    }

    // Nhap 2 so tu nguoi dung
    printf("\n Nhap vao 2 so (tu 01 - 15): \n");
    for (int i = 0; i < 2; i++) {
        printf(" So thu %d: ", i + 1);
        scanf("%d", &soUser[i]);
        
        // Kiem tra so nhap vao hop le
        while (soUser[i] < 1 || soUser[i] > 15) {
            printf(" So phai tu 01 - 15. Vui long nhap lai: ");
            scanf("%d", &soUser[i]);
        }
    }

    // So sanh so trung
    int soTrung = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (soUser[i] == soNgauNhien[j]) {
                soTrung++;
            }
        }
    }

    // Hien thi ket qua
    printf(" So ngau nhien: %02d, %02d\n", soNgauNhien[0], soNgauNhien[1]);
    if (soTrung == 0) {
        printf(" Chuc ban may man lan sau!\n");
    } else if (soTrung == 1) {
        printf(" Chuc mung ban da trung giai nhi!\n");
    } else if (soTrung == 2) {
        printf(" Chuc mung ban da trung giai nhat!\n");
    }
}


// Bai 10: Chuong trinh tinh toan phan so

// Cau truc de luu thong tin phan so
typedef struct {
    int tuSo;   // Tu so
    int mauSo;  // Mau so
} PhanSo;

// Ham de tinh GCD (Greatest Common Divisor) dung de rut gon phan so
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Ham de rut gon phan so
PhanSo rutGon(PhanSo ps) {
    int ucln = gcd(ps.tuSo, ps.mauSo);
    ps.tuSo /= ucln;
    ps.mauSo /= ucln;
    return ps;
}

// Ham de cong 2 phan so
PhanSo cong(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return rutGon(ketQua);
}

// Ham de tru 2 phan so
PhanSo tru(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return rutGon(ketQua);
}

// Ham de nhan 2 phan so
PhanSo nhan(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.tuSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return rutGon(ketQua);
}

// Ham de chia 2 phan so
PhanSo chia(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.tuSo;
    return rutGon(ketQua);
}

void Bai10(){
	 PhanSo ps1, ps2;

    // Nhap phan so thu nhat
    printf("\n Nhap phan so 1 (tu so mau so):\n");
    printf(" Tu so: ");
    scanf("%d", &ps1.tuSo);
    printf(" Mau so: ");
    scanf("%d", &ps1.mauSo);

    // Nhap phan so thu hai
    printf("\n Nhap phan so 2 (tu so mau so):\n");
    printf(" Tu so: ");
    scanf("%d", &ps2.tuSo);
    printf(" Mau so: ");
    scanf("%d", &ps2.mauSo);

    // Tinh toan va hien thi ket qua
    PhanSo tong = cong(ps1, ps2);
    PhanSo hieu = tru(ps1, ps2);
    PhanSo tich = nhan(ps1, ps2);
    PhanSo thuong = chia(ps1, ps2);
    
	printf("\n |==========[KET QUA]==========|\n");
	printf(" |                             \n");
    printf(" | Tong: %d/%d                 \n", tong.tuSo, tong.mauSo);
    printf(" | Hieu: %d/%d                 \n", hieu.tuSo, hieu.mauSo);
    printf(" | Tich: %d/%d                 \n", tich.tuSo, tich.mauSo);
    printf(" | Thuong: %d/%d               \n", thuong.tuSo, thuong.mauSo);
    printf(" |_____________________________|\n");
}


// Menu goi chuc nang

int main(){
	int choice;
do{

printf("\n++==========================[MENU]===========================++\n");
		printf("| Chuc nang 1: Kiem tra so nguyen			      |\n");
		printf("| Chuc nang 2: Tim uoc so chung va boi chung cua hai so       |\n");
		printf("| Chuc nang 3: Chuong trinh tinh tien cho quan karaoke        |\n");
		printf("| Chuc nang 4: Tinh tien dien                                 |\n");
		printf("| Chuc nang 5: Chuc nang doi tien                             |\n");
		printf("| Chuc nang 6: Chuc nang tinh lai xuat ngan hang vay tra gop  |\n");
		printf("| Chuc nang 7: Chuong trinh vay tien mua xe                   |\n");
		printf("| Chuc nang 8: Sap xep thong tin sinh vien                    |\n");
		printf("| Chuc nang 9: Game FPOLY_LOTT(2/15)                          |\n");
		printf("| Chuc nang 10: Tinh toan phan so                             |\n");
		printf("| Chuc nang 0: Thoat chuong trinh                             |\n");
        printf("++===========================================================++\n");
        printf(" Xin moi lua chon chuc nang: ");
		scanf("%d",&choice);
		printf("\n");
		
		
		switch(choice){
		case 1:
			Bai1();
			break;
		case 2:
			Bai2();
			break;
		case 3:
			Bai3();
			break;
		case 4:
			Bai4();
			break;
		case 5:
			Bai5();
			break;
		case 6:
			Bai6();
			break;
		case 7:
			Bai7();
			break;
		case 8:
			Bai8();
			break;
		case 9:
			Bai9();
			break;
		case 10:
			Bai10();
			break;
		case 0:
			printf("Thoat chuong trinh\n");
			break;
		default:
			printf("Ban nhap sai. Vui long nhap lai\n");
			break;
		}
}
while(choice!=0);
return 0;
}
