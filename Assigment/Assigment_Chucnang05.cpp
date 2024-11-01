#include <stdio.h>

void doiTien(int soTien) {
    int menhGia[] = {500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000}; // Cac menh gia tien
    int soTo;

    printf("So tien can doi: %d VND\n", soTien);
    printf("Cac menh gia tien duoc doi ra:\n");

    // Su dung vong lap de doi tien
    for (int i = 0; i < sizeof(menhGia) / sizeof(menhGia[0]); i++) {
        soTo = soTien / menhGia[i]; // Tinh so to can doi
        if (soTo > 0) {
            printf("%d to %d VND\n", soTo, menhGia[i]);
            soTien -= soTo * menhGia[i]; // Cap nhat so tien con lai
        }
        // In ra gia tri cua soTien sau khi tru di so tien da doi
        printf("So tien con lai sau khi doi menh gia %d: %d VND\n", menhGia[i], soTien);
    }
}

int main() {
    int soTien;

    // Nhap so tien can doi
    printf("Nhap so tien can doi (VD: 2000000 cho 2 trieu): ");
    scanf("%d", &soTien);

    // Kiem tra so tien hop le
    if (soTien <= 0) {
        printf("So tien khong hop le. Phai la so duong\n");
        return 1; // Ket thuc chuong trinh voi ma loi
    }

    // Goi ham doi tien
    doiTien(soTien);

    return 0;
}

