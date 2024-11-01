#include <stdio.h>
#include <math.h>  // Them thu vien math.h de tinh luy thua

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

int main() {
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
    
    return 0;
}

