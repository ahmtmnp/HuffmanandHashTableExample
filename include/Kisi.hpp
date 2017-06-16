/**
* @file Kisi.hpp
* @description  Bilgi.txt dosyasından okunan degerleri huffman yapısıyla kodlayıp hash tablosuna ekleme
* @course 1. öğretim B grubu
* @assignment 5. Ödev
* @date 18.12.2014
* @author Ahmet Münip Şitoğlu - ahmetmsitoglu@hotmail.com
*/
#ifndef KISI_HPP
#define KISI_HPP


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Kisi{
	private:
		string kisiAd;
		int adDecimal;
	public:
		
		Kisi();
		void kisiAdAta(string isim);
		void adDecimalAta(string);
		int ustAl(int);
		int adDecimalGetir();
		string kisiAdGetir();
		~Kisi();
};
#endif