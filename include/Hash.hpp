/**
* @file Hash.hpp
* @description  Bilgi.txt dosyasından okunan degerleri huffman yapısıyla kodlayıp hash tablosuna ekleme
* @course 1. öğretim B grubu
* @assignment 5. Ödev
* @date 18.12.2014
* @author Ahmet Münip Şitoğlu - ahmetmsitoglu@hotmail.com
*/
#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include "Kisi.hpp"
using namespace std;
#define MAX 100

struct HashDugum{
	Kisi *kisi;
	HashDugum *ileri;
	HashDugum(Kisi *girdi,HashDugum *ilr=NULL){
		kisi=girdi;
		ileri=ilr;
	}
};

class Hash{
	private:
		HashDugum* Dizi[MAX];
	public:
		Hash();
		int HashCode(int);
		void Ekle(Kisi[]);
		bool Cikar(int);
		void Temizle();
		bool Bul(int);
		bool Bosmu() const;
		void Yaz() const;
		~Hash();
};
#endif