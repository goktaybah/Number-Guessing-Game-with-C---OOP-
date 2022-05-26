
#include <iostream>
#include "BM104_210757043_Proje1_Bahar.h"

using namespace std;
int main()
{
	//Degerlerimizi aliyoruz
	int kacEleman, altLimit, ustLimit;
	cout << "Kac eleman olsun:(2-20 arasi):";
	cin >> kacEleman;
	//2den kucuk veya buyuk bir deger girildiginde tekrar istiyoruz
	while (kacEleman < 2 || kacEleman >20) {
		cout << "Lutfen 2 ile 20 arasi bir sayi giriniz.";
		cin >> kacEleman;
	}
	cout << "Alt limit:";
	cin >> altLimit;
	cout << "Ust Limit:";
	cin >> ustLimit;
	//classımızı olusturuyoruz
	BM104_210757043_Proje1_Bahar nsn(kacEleman, altLimit, ustLimit);
	nsn.OyunOyna();
}
