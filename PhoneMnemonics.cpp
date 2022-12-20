
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//tuş takımı için gerekli matrisi oluşturur
string tuslar[8] = { "ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ" };

//hangi tuşun kaç tane harf içerdiğini tutan bir dizi
int TusHarfSayisi[8] = { 3,3,3,3,3,4,3,4 };

int tur = 0, index = 0, comb = 1, kkk = 0;

//harf gruplarının yazılma sırasını tutuyor
int* sira;

void hecele(int* a) {
	
	for (int  i = 0; i < index; i++)
	{
		cout << tuslar[a[i]][sira[i]];
	}

	tur++;

	//boşluk eklemek ve bi alt satıra geçmek için
	cout << " ";
	if (tur % 3 == 0) cout << endl;

	for (int i = index - 1; i > 0 ; i--)	
	{
		if (TusHarfSayisi[a[i]] - 1 == sira[i]) {
			sira[i] = -1;

			kkk++;	//sira2 ve fazlasını arttırmak 
		}
		else break; //ilk sira uyuşmuyosa diğer siralar değişmemeli
	}
	for (int i = 1; i <= kkk; i++)	
	{
		sira[index - i - 1] ++; //sira 2 ve fazlasını arttırır sira1 aşağıda her seferinde artıyor zaten
	} 

	kkk = 0;
	sira[index - 1]++;
	

	if(tur != comb) hecele(a);
}


/*
	2	a b c
	3	d e f
	4	g h i
*/


int main()
{
	int tkrr = 0;
	do {
		string say;
		int* x;

		cout << "\n-----------------------------------------\n";

		cout << "sayi giriniz:";
		cin >> say;

		//kaç tane sayı geldiği belirleniyor
		for (int i = 0; say[i] != '\0'; i++) index++;

		//char int çevirme
		x = new int[index];
		for (int i = 0; i < index; i++) {
			x[i] = (int)say[i] - 48;

			if (x[i] <= 1) x[i] = 10; // 10 geldiğinde boş geçicek
			if (x[i] >= 2) x[i] -= 2; // sayılar 2'den başlıyo ama diziler 0'dan başlıyor

			comb *= TusHarfSayisi[x[i]]; //toplamda kaç adet kombinasyon olduğunu hesaplıyor
		}

		sira = new int[index];
		for (int i = 0; i < index; i++) sira[i] = 0;


		hecele(x);

		cout << "\nkombinasyon sayisi: " << comb;
		cout << "\n-----------------------------------------\n";

		delete[] x;
		delete[] sira;

		//global değişkenler tekrar kullanılmak için ilk haline getirilir
		tur = 0;	index = 0;	comb = 1;	kkk = 0;
		
		cout << "tekrar denemek icin 1 kapatmak icin 0 basin:";
		cin >> tkrr;
	
	}while (tkrr);

	return 0;
}

