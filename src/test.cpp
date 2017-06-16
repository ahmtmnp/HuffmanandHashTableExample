/**
* @file test.cpp
* @description  Bilgi.txt dosyasından okunan degerleri huffman yapısıyla kodlayıp hash tablosuna ekleme
* @course 1. öğretim B grubu
* @assignment 5. Ödev
* @date 18.12.2014
* @author Ahmet Münip Şitoğlu - ahmetmsitoglu@hotmail.com
*/#include "Huffman.hpp"
#include "Hash.hpp"

int main(){
	Huffman *huffman = new Huffman("bilgi.txt");
	huffman->Kodla();
	cout<<*huffman;
	string isim,binary;
	
	int kisiSayisi=0;
	
	ifstream tara("bilgi.txt");
	while (getline(tara,isim)){
			kisiSayisi++;
	}
	tara.close();
	
	Hash *hash = new Hash();
	Kisi *kisi = new Kisi[kisiSayisi];
	
	int sayac=0;
	
	ifstream dosya("bilgi.txt");
	while (getline(dosya,isim)){	
		binary="";
		for(int i=0;i<isim.length();i++)
		{	
			binary+=huffman->KodBul(isim[i],*huffman);
		}
		kisi[sayac].adDecimalAta(binary);
		kisi[sayac].kisiAdAta(isim);
		hash->Ekle(&kisi[sayac]);
		sayac++;
	}
	dosya.close();
	
	hash->Yaz();
	
	delete huffman;
	delete hash;
	delete kisi;
	return 0;
}