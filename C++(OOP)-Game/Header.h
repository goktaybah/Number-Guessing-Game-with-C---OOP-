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
#include <string>
#ifndef BM104_210757043_Proje1_Bahar_H
#define BM104_210757043_Proje1_Bahar_H
class BM104_210757043_Proje1_Bahar {
public:
	//Yapýcýmýz
	BM104_210757043_Proje1_Bahar(int kacEleman, int altLimit, int ustLimit);
	//Tek public fonksiyonuzmuz
	void OyunOyna();

private:
	//Gerekli int degerlerimiz
	int sayilar[20], kacEleman, kacTahmin, altLimit, ustLimit, kacSayiBulundu;
	//Bu diziyi her döngüde çýkardýgýmýz X X X X'ler icin olusturuyoruz
	std::string sayilarString[20];
	//Bulunan sayilarin kaydini tutup tekrarin onlenmesi icin
	std::string bulunanSayilar;
	//Oyunu kazandi mi kontrol etmek için kontrol degiskeni
	bool kazandiMi;
	bool sayiDahaOnceBulunduMu;
	//Elemanlarý atama fonksiyonu
	void RastgeleElemanAta();
	//Arama kaydirme
	bool DiziAramaKaydirma(int arananSayi);
	//Dongumuzu kontrol eden fonksiyon
	void OyunDongu();
	//int dizilerinde ki bulunan degerleri sona atan fonksiyon
	void Reorder(int A[], int n, int arananSayi);
	//string dizilerinde bulunan degerleri sona atan fonksiyon
	void ReorderString(std::string A[], int n, std::string arananString);
	//string dizisini cikarmak icin
	void OyunBastir(std::string basilacak[]);
};
#endif
