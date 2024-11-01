#include <stdio.h>

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

// Ham chinh
int main() {
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
    printf(" |_____________________________|");

    return 0;
}

