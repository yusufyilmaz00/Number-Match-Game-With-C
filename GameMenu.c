#include <stdio.h>

/* men� sistemi

a.	Ana men�: 
i.	Rastgele Matris Olu�tur:
ii.	Dosyadan Matris Olu�tur:
iii.	Kullan�c�lar�n Skorlar�n� G�ster:
iv.	��k��
*/


/*
b.	Oyun Men�s�: Ana men�de i ya da ii se�ildi�inde, �nce kullan�c� ad� al�nmal� ve a�a��daki men�lerden birinde Ana Men�ye geri d�n�� yap�lana kadar oyun oynanmal�d�r.  
i.	Manuel Modda Oyna
ii.	Otomatik Modda Oyna
iii.	Ana Men�ye D�n
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



