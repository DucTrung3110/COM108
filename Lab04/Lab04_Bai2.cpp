#include <stdio.h>
int main(){
	int x, i, count = 0;
	printf("Nhap vao so nguyen: ");
	scanf("%d", &x);
	
	if(x<2){
		printf("%d khong phai la so nguyen to\n", x);
		return 0;
	}
	
	for(i=2; i<x; i++){
		if(x%i==0){
			count++;
			break;
		}
	}if(count==0){
		printf("%d la so nguyen to\n", x);
	}else{
		printf("%d khong phai la so nguyen to\n", x);
	}
	return 0;
}
