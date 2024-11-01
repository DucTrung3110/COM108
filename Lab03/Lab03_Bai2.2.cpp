#include <stdio.h>
#include <math.h>
int main(){
float a,b,c;
printf("Nhap vao so a: ");
scanf("%f", &a);
printf("Nhap vao so b: ");
scanf("%f", &b);
printf("Nhap vao so c: ");
scanf("%f", &c);

if(a==0){
	if(b==0){
	if(c==0){
	printf("Phuong trinh co vo so nghiem\n");
	}else{
	printf("Phuong trinh vo nghiem\n");
	}
	}else{
	float x = -c / b;
	printf("Phuong trinh co nghiem x = %.2f\n", x);
	}
	
	
}else{
	float delta = pow(b,2)-4*a*c;
	
	if(delta<0){
	printf("Phuong trinh vo nghiem\n");
	}else if(delta==0){
	float x = -b/(2*a);
	printf("Phuong trinh co nghiem kep x = %.2f\n", x);
	}
	else {
	float sqrtDelta = sqrt(delta);
	float x1 = (-b + sqrtDelta)/(2*a);
	float x2 = (-b - sqrtDelta)/(2*a);
	printf("Phuong trinh co 2 nghiem phan biet:\n");
	printf("x1 = %.2f\n", x1);
	printf("x2 = %.2f\n", x2);
	}
	return 0;
	}
		
}
