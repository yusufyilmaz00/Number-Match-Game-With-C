#include <stdio.h>

/* menü sistemi

a.	Ana menü: 
i.	Rastgele Matris Oluþtur:
ii.	Dosyadan Matris Oluþtur:
iii.	Kullanýcýlarýn Skorlarýný Göster:
iv.	Çýkýþ
*/


/*
b.	Oyun Menüsü: Ana menüde i ya da ii seçildiðinde, önce kullanýcý adý alýnmalý ve aþaðýdaki menülerden birinde Ana Menüye geri dönüþ yapýlana kadar oyun oynanmalýdýr.  
i.	Manuel Modda Oyna
ii.	Otomatik Modda Oyna
iii.	Ana Menüye Dön
*/
void mainMenu(){
	printf("1) Rastgele Matris Olustur:\n2) Dosyadan Matris Olustur:\n3) Kullanicilarin Skorlarini Goster:\n4) Exit\n");
	gameMenu();
}

void gameMenu(){
	printf("a) Manuel Modda Oyna\nb) Otomatik Modda Oyna\nc) Ana Menuye Don\n");
	return;
}

char getPlayerName(){
	char name;
	scanf(" %s\n",name);
	return name;
}

int main(){
	char isim;
	mainMenu();
	isim = getPlayerName();
	printf("%c",isim);
	
	return 1;
}



