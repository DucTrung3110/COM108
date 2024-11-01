#include <stdio.h>
#include <string.h>

#define MAX_SINH_VIEN 100  // So luong sinh vien toi da

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

int main() {
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

    return 0;
}

