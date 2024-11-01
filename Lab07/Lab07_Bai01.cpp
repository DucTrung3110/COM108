#include <stdio.h>
#include <ctype.h> // Khai bao de dung ham tolower()

int main(){

char s[100];
int i = 0; 
int n = 0; // Bien dem so nguyen am 
int p = 0; // Bien dem so phu am 

	printf("Xin moi nhap vao chuoi: ");
	gets(s);
	
	while(s[i] != '\0'){
		char ch = tolower(s[i]);
		
		if(ch == 'a' || ch == 'i' || ch == 'e' || ch == 'u' || ch == 'o'){
		n++;
		}else if((ch >= 'a' && ch <= 'z')){
		p++;
		}
		i++;
	}
	printf("Chuoi '%s' co chua: %d nguyen am va %d phu am", s, n, p);
	return 0;
}
