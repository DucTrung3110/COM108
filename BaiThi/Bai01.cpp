#include <stdio.h>

int main() {
    int n, i;
    
    // Nhap so luong phan tu trong mang
    printf("\n Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Nhap cac phan tu cua mang
    printf("\n Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        printf("\n Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Xuat ra cac so le trong mang
    printf("\n Cac so le trong mang: ");
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    
    // Tinh tong cac so chia het cho 5
    int tong = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] % 5 == 0) {
            tong += arr[i];
        }
    }
    
    // Xuat ket qua tong
    printf("\n Tong cac so chia het cho 5: %d\n", tong);
    
    return 0;
}

