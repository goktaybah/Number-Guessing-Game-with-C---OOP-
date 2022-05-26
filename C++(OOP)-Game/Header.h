
#include <string>
#ifndef BM104__Proje1_Bahar_H
#define BM104__Proje1_Bahar_H
class BM104__Proje1_Bahar {
public:
	//Yapıcımız
	BM104__Proje1_Bahar(int kacEleman, int altLimit, int ustLimit);
	//Tek public fonksiyonuzmuz
	void OyunOyna();

private:
	//Gerekli int degerlerimiz
	int sayilar[20], kacEleman, kacTahmin, altLimit, ustLimit, kacSayiBulundu;
	//Bu diziyi her döngüde çıkardıgımız X X X X'ler icin olusturuyoruz
	std::string sayilarString[20];
	//Bulunan sayilarin kaydini tutup tekrarin onlenmesi icin
	std::string bulunanSayilar;
	//Oyunu kazandi mi kontrol etmek için kontrol degiskeni
	bool kazandiMi;
	bool sayiDahaOnceBulunduMu;
	//Elemanları atama fonksiyonu
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
