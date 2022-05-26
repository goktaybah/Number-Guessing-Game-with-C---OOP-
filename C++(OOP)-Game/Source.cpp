/*
* Göktay
Bahçekapýlý
210757043
Bilgisayar mühendisliði ikinci öðretim
Nesneye yönelik programlama / BM104
BAHAR 2022
BM104
DENÝZ DAL
*/

#include <iostream>
#include "BM104_210757043_Proje1_Bahar.h"
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
void BM104_210757043_Proje1_Bahar::RastgeleElemanAta()
{
	//Bu fonksiyonu bir defa kullanýcagýmýz icin bazi degiskenlerimize varsayýlan degerlerini atiyoruz
	sayiDahaOnceBulunduMu = false;
	kazandiMi = false;
	bulunanSayilar = "";
	kacSayiBulundu = 0;
	//for dongusunde sayilar dizisine alt ve üst limit arasinda degerler atiyoruz
	for (int i = 0; i < kacEleman; i++)
	{
		sayilar[i] = (rand() % (ustLimit + 1 - altLimit)) + altLimit;
	}
	//for dongusunde sayilarString dizisine alt ve üst limit arasinda degerler atiyoruz

	for (int i = 0; i < kacEleman; i++)
	{
		sayilarString[i] = to_string(sayilar[i]);
	}
}

bool BM104_210757043_Proje1_Bahar::DiziAramaKaydirma(int arananSayi)
{
	//yedek diziler bulunan degerlerin yerini degistirirken lazim oluyor
	int yedekDizi[20];
	std::string yedekString[20];
	//yedek dizileri esitliyoruz
	for (int i = 0; i < kacEleman; i++)
	{
		yedekDizi[i] = sayilar[i];
		yedekString[i] = sayilarString[i];
	}
	//bu bool degiskenimiz sayi bulunup bulunmadigini kontrol ediyor.
	bool donecekDeger = false;
	for (int i = 0; i < kacEleman; i++)
	{
		if (sayilar[i] == arananSayi) {
			//bulunan sayilari kontrol ediyoruz tekrar olmamasi icin
			if (bulunanSayilar.find(to_string(arananSayi)) != std::string::npos) {
				cout << "Bu sayiyi daha once bulmussunuz." << endl;
			}
			else
			{
				cout << " Bulundu:" + to_string(arananSayi) << endl;
				kacSayiBulundu++;
				//siramalari degistiriyoruz sona atiyoruz bulunanlari
				Reorder(yedekDizi, kacEleman, arananSayi);
				ReorderString(yedekString, kacEleman, to_string(arananSayi));
				donecekDeger = true;
				//kazandi mi oyuncu kontrol
				if (kacSayiBulundu == kacEleman) {
					cout << "Kazandiniz." << endl;
					kazandiMi = true;
					kacTahmin = 0;
					break;
				}
			}
		}
	}
	//sayi bulunmadiysa giriyoruz bu for dongusune giremezsek bulunmus demektir ve bulunanlara ekliyoruz
	if (!donecekDeger)
	{
		cout << "Bulunamadi:" + to_string(arananSayi) << endl;
	}
	else
	{
		bulunanSayilar += to_string(arananSayi);
	}
	for (int i = 0; i < kacEleman; i++)
	{
		sayilar[i] = yedekDizi[i];
		sayilarString[i] = yedekString[i];
	}
	return donecekDeger;
}

void BM104_210757043_Proje1_Bahar::OyunDongu()
{
	//tahmin sayisi kadar donuyoruz
	for (int i = 0; i < kacTahmin; i++)
	{
		int tahmin;
		cout << "Tahmininizi girin:" << endl;
		cin >> tahmin;
		DiziAramaKaydirma(tahmin);
		OyunBastir(sayilarString);
	}
	//eger oyunu kazanmamissa otamatik kaybediyor dongu bitince
	if (!kazandiMi)
	{
		cout << "Kaybettiniz." << endl;
	}
}

void BM104_210757043_Proje1_Bahar::Reorder(int A[], int n, int arananSayi)
{
	// k degiskeni bir sonra ki musait indexi tutuyor
	int k = 0;

	// do for each element
	for (int i = 0; i < n; i++)
	{
		// eger eleman arananSayi degilse
		// bir sonra ki musait yere koyuyoruz
		if (A[i] != arananSayi) {
			A[k++] = A[i];
		}
	}

	//aranansayilari sona atiyoruz
	for (int i = k; i < n; i++) {
		A[i] = arananSayi;
	}
}
//int reorderin aynisi
void BM104_210757043_Proje1_Bahar::ReorderString(string A[], int n, string arananString)
{
	// `k` stores the index of the next available position
	int k = 0;

	// do for each element
	for (int i = 0; i < n; i++)
	{
		// if the current element is non-zero, put the element at the
		// next free position in the array
		if (A[i] != arananString) {
			A[k++] = A[i];
		}
	}

	// move all 0's to the end of the array (remaining indices)
	for (int i = k; i < n; i++) {
		A[i] = arananString;
	}
}

void BM104_210757043_Proje1_Bahar::OyunBastir(std::string basilacak[])
{
	//yedek stringi X leri degistirirken lazim olacak
	string yedekString[20];
	// yedek stringi sayilarString'e esitliyoruz
	for (int i = 0; i < kacEleman; i++)
	{
		yedekString[i] = basilacak[i];
	}
	//mesela 2 eleman bulunduysa 6-2=4 ilk 4 elemaný X yapýyoruz
	for (int i = 0; i < kacEleman - kacSayiBulundu; i++)
	{
		yedekString[i] = "X";
	}
	//ekrana yazdiriyoruz
	for (int i = 0; i < kacEleman; i++)
	{
		cout << yedekString[i] + " ";
	}
	cout << endl;
}
//Yapicimizda oyuncudan aldigimiz verileri esitliyoruz
BM104_210757043_Proje1_Bahar::BM104_210757043_Proje1_Bahar(int x, int y, int z)
{
	kacEleman = x;
	altLimit = y;
	ustLimit = z;
	kacTahmin = x * 2;
}

void BM104_210757043_Proje1_Bahar::OyunOyna()
{
	RastgeleElemanAta();
	OyunDongu();
}