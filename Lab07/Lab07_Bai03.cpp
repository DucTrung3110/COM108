#include <stdio.h>
#include <string.h>

int main(){
	char s[5][20]; // 5 mang voi 20 ky tu theo cot trong mang VD: mang 1 nhap apple thi 20 ky tu se dem lan luot la mang[0]: a, mang[1]: p,......
	char temp[20];
	int i, j;
	
	printf("\n Moi nhap vao 5 chuoi bat ky:\n");
	for(i = 0; i < 5; i++){
		printf(" Nhap vao chuoi thu %d: ", i + 1);
		gets(s[i]);
	}
	
	// Chay giai thuat sap xep
	for(i = 0; i < 4; i++){
		for(j = i + 1; j < 5; j++){
		// Su dung strcmp() de so sanh 2 chuoi
		if(strcmp(s[i], s[j]) > 0){
			// Neu chuoi thu i lon hon chuoi thu j (theo thu tu bang chu cai) => hoan doi chung
			strcpy(temp, s[i]); // Sao chep chuoi thu i vao bien tam temp
			strcpy(s[i], s[j]); // Sao chep chuoi thu j vao chuoi i
			strcpy(s[j], temp); // Sao chep chuoi tu bien tam vao chuoi thu j
		}
		}
	}
	printf("\n Cac chuoi sau khi sap xep theo thu tu bang chu cai la:\n");
	for(i = 0; i < 5; i++){
		printf(" %s\n", s[i]);
	}
	return 0;
}
