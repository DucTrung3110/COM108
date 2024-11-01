#include <stdio.h>

// Ham nhap thong tin ca nhan va in ra man hinh
void nhapThongTin() {
    char ten[50], diaChi[100], chuyenNganh[50];
    int tuoi, kyHoc;
    
    printf("Nhap ten: ");
    fgets(ten, sizeof(ten), stdin);
    printf("Nhap tuoi: ");
    scanf("%d", &tuoi);
    getchar(); // Doc ky tu newline sau khi nhap tuoi
    printf("Nhap dia chi: ");
    fgets(diaChi, sizeof(diaChi), stdin);
    printf("Nhap ky hoc: ");
    scanf("%d", &kyHoc);
    getchar(); // Doc ky tu newline sau khi nhap ky hoc
    printf("Nhap chuyen nganh: ");
    fgets(chuyenNganh, sizeof(chuyenNganh), stdin);

    // In ra thong tin
    printf("\nThong tin vua nhap:\n");
    printf("Ten: %s", ten);
    printf("Tuoi: %d\n", tuoi);
    printf("Dia chi: %s", diaChi);
    printf("Ky hoc: %d\n", kyHoc);
    printf("Chuyen nganh: %s", chuyenNganh);
}

// Ham tinh tong tu 1 den n
void tinhTong() {
    int n, S = 0;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        S += i;
    }

    printf("Tong S = 1 + 2 + ... + %d = %d\n", n, S);
}

// Ham nhap thong tin sinh vien cac lop
void thongTinSinhVien() {
    int tongLop, viTriMin = 0;
    
    printf("Moi nhap tong so lop: ");
    scanf("%d", &tongLop);
    
    int soLuongSV[tongLop];

    printf("Nhap so luong sinh vien cac lop:\n");
    for(int i = 0; i < tongLop; i++) {
        printf("Lop %d: ", i + 1);
        scanf("%d", &soLuongSV[i]);
    }

    // In so luong cac lop
    printf("\nSo luong cac lop la: %d\n", tongLop);
    
    // Liet ke vi tri cac lop co so SV < 30
    printf("Cac lop co so luong sinh vien nho hon 30: ");
    for(int i = 0; i < tongLop; i++) {
        if(soLuongSV[i] < 30) {
            printf("Lop %d ", i + 1);
        }
    }
    printf("\n");

    // Tim vi tri lop co so luong SV nho nhat
    for(int i = 1; i < tongLop; i++) {
        if(soLuongSV[i] < soLuongSV[viTriMin]) {
            viTriMin = i;
        }
    }
    printf("Lop co so sinh vien nho nhat la: Lop %d\n", viTriMin + 1);
}

int quayLai() {
    char luaChon;
    printf("Ban co muon quay lai chuc nang nay? (y/n): ");
    scanf(" %c", &luaChon);
    getchar(); // Ð?c ký t? newline

    if (luaChon == 'y' || luaChon == 'Y') {
        return 1; // Quay l?i ch?c nang
    } else if (luaChon == 'n' || luaChon == 'N') {
        return 0; // Không quay l?i, thoát ra menu
    } else {
        printf("Lua chon khong hop le! Vui long nhap 'y' hoac 'n'.\n");
        return quayLai(); // G?i l?i hàm d? nh?p l?i
    }
}


int main() {
    int luaChon;

    do {
        printf("\n+--------------------------Menu------------------------+\n");
        printf("1. Nhap thong tin ca nhan\n");
        printf("2. Tinh tong\n");
        printf("3. Thong tin sinh vien cac lop\n");
        printf("0. Thoat\n");
        printf("+--------------------------------------------------------+\n");
        printf("Moi chon: ");
        scanf("%d", &luaChon);
        getchar(); // Ð?c ký t? newline sau khi nh?p l?a ch?n

        switch(luaChon) {
            case 1:
                do {
                    nhapThongTin();
                } while (quayLai()); // Ti?p t?c n?u ngu?i dùng nh?p 'y'
                break;
            case 2:
                do {
                    tinhTong();
                } while (quayLai()); // Ti?p t?c n?u ngu?i dùng nh?p 'y'
                break;
            case 3:
                do {
                    thongTinSinhVien();
                } while (quayLai()); // Ti?p t?c n?u ngu?i dùng nh?p 'y'
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Moi chon lai.\n");
        }
    } while (luaChon != 0);

    return 0;
}


