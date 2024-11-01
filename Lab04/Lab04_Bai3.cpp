#include <stdio.h>

int main(){
	int x, i, count = 0;
	printf("Nhap vao so x: ");
	scanf("%d", &x);

	for(i=1; i<x; i++){
		if(i*i==x){
			count++;
			break;
		}
	}
		if(count==1){
			printf("%d la so chinh phuong\n", x);
		}
		else {
			printf("%d khong phai la so chinh phuong\n", x);
		}

	return 0;
}
