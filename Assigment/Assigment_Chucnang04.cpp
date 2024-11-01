#include <stdio.h>
int main() {
int kWh;
double soTien;
	
	printf("Nhap vao so dien tieu thu hang thang: ");
    scanf("%d", &kWh);
 	printf("\n+===============[HOA DON]===============+\n");
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
        printf("|So dien tieu thu: %d kWh              |\n", kWh);
        printf("|Gia: %.3lf dong/kWh|\n", giaBac1);
    } else if (kWh <= 100) {
        soTien = 50 * giaBac1 + (kWh - 50) * giaBac2;
        printf("|So dien tieu thu: %d kWh              |\n", kWh);
        printf("|Bac 1: 50 kWh * %.3lf dong/kWh         |\n", giaBac1);
        printf("|Bac 2: %d kWh * %.3lf dong/kWh         |\n", kWh - 50, giaBac2);
    } else if (kWh < 200) {
        soTien = 50 * giaBac1 + 50 * giaBac2 + (kWh - 100) * giaBac3;
        printf("|So dien tieu thu: %d kWh              |\n", kWh);
        printf("|Bac 1: 50 kWh * %.3lf dong/kWh         |\n", giaBac1);
        printf("|Bac 2: 50 kWh * %.3lf dong/kWh         |\n", giaBac2);
        printf("|Bac 3: %d kWh * %.3lf dong/kWh        |\n", kWh - 100, giaBac3);
    } else if (kWh <= 300) {
        soTien = 50 * giaBac1 + 50 * giaBac2 + 100 * giaBac3 + (kWh - 200) * giaBac4;
        printf("|So dien tieu thu: %d kWh              |\n", kWh);
        printf("|Bac 1: 50 kWh * %.3lf dong/kWh         |\n", giaBac1);
        printf("|Bac 2: 50 kWh * %.3lf dong/kWh         |\n", giaBac2);
        printf("|Bac 3: 100 kWh * %.3lf dong/kWh        |\n", giaBac3);
        printf("|Bac 4: %d kWh * %.3lf dong/kWh        |\n", kWh - 200, giaBac4);
    } else if (kWh <= 400) {
        soTien = 50 * giaBac1 + 50 * giaBac2 + 100 * giaBac3 + 100 * giaBac4 + (kWh - 300) * giaBac5;
        printf("|So dien tieu thu: %d kWh              |\n", kWh);
        printf("|Bac 1: 50 kWh * %.3lf dong/kWh         |\n", giaBac1);
        printf("|Bac 2: 50 kWh * %.3lf dong/kWh         |\n", giaBac2);
        printf("|Bac 3: 100 kWh * %.3lf dong/kWh        |\n", giaBac3);
        printf("|Bac 4: 100 kWh * %.3lf dong/kWh        |\n", giaBac4);
        printf("|Bac 5: %d kWh * %.3lf dong/kWh        |\n", kWh - 300, giaBac5);
    } else {
        soTien = 50 * giaBac1 + 50 * giaBac2 + 100 * giaBac3 + 100 * giaBac4 + 100 * giaBac5 + (kWh - 400) * giaBac6;
        printf("|So dien tieu thu: %d kWh              |\n", kWh);
        printf("|Bac 1: 50 kWh * %.3lf dong/kWh         |\n", giaBac1);
        printf("|Bac 2: 50 kWh * %.3lf dong/kWh         |\n", giaBac2);
        printf("|Bac 3: 100 kWh * %.3lf dong/kWh        |\n", giaBac3);
        printf("|Bac 4: 100 kWh * %.3lf dong/kWh        |\n", giaBac4);
        printf("|Bac 5: 100 kWh * %.3lf dong/kWh        |\n", giaBac5);
        printf("|Bac 6: %d kWh * %.3lf dong/kWh        |\n", kWh - 400, giaBac6);
    }
	printf("|_______________________________________|\n");
    printf("      Tong so tien la: %.3lf dong\n", soTien);
    printf("|_______________________________________|\n");
    return 0;
}



