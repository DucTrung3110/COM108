#include <stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int x,y;
	printf("\n Nhap vao so x: ");
	scanf("%d", &x);
	printf("\n Nhap vao so y: ");
	scanf("%d", &y);
	
	printf("\n Truoc khi hoan doi: x = %d, y = %d\n", x,y);
	swap(&x,&y);
	printf(" Sau khi hoan doi: x = %d, y = %d\n", x,y);
	return 0;
} 
