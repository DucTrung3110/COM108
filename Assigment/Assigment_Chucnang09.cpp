#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
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

    return 0;
}

