/**
* @file Hash.cpp
* @description  Bilgi.txt dosyasından okunan degerleri huffman yapısıyla kodlayıp hash tablosuna ekleme
* @course 1. öğretim B grubu
* @assignment 5. Ödev
* @date 18.12.2014
* @author Ahmet Münip Şitoğlu - ahmetmsitoglu@hotmail.com
*/
#include "Hash.hpp"


Hash::Hash(){
	for(int i=0;i<MAX;i++)
		Dizi[i] = NULL;
}

void Hash::Ekle(Kisi *kisi){
	if(Bul(kisi->adDecimalGetir())) return;
	int indeks = HashCode(kisi->adDecimalGetir());
	Dizi[indeks] = new HashDugum(kisi,Dizi[indeks]);
}
bool Hash::Bul(int sayi) {
	int indeks = HashCode(sayi);
	HashDugum *tmp = Dizi[indeks];
	while(tmp != NULL){
		if(tmp->kisi->adDecimalGetir() == sayi)return true;
		tmp=tmp->ileri;
	}
	return false;
}
bool Hash::Cikar(int sayi){
	int indeks = HashCode(sayi);
	if(Dizi[indeks] == NULL) return false;
	if(Dizi[indeks]->kisi->adDecimalGetir() == sayi){
		HashDugum *sil = Dizi[indeks];
		Dizi[indeks] = Dizi[indeks]->ileri;
		delete sil;
		return true;
	}
	HashDugum *onceki = Dizi[indeks];
	while(onceki->ileri != NULL){
		if(onceki->ileri->kisi->adDecimalGetir() == sayi){
			HashDugum *sil = onceki->ileri;
			onceki->ileri = sil->ileri;
			delete sil;
			return true;
		}
		onceki = onceki->ileri;
	}
	return false;
}

bool Hash::Bosmu() const{
	for(int i=0;i<MAX;i++){
		if(Dizi[i] != NULL) return false;
	}
	return true;
}

int Hash::HashCode(int sayi){
	return sayi%MAX;
}

void Hash::Temizle(){
	for(int i=0;i<MAX;i++){
		HashDugum *tmp = Dizi[i];
		while(tmp != NULL){
			HashDugum* sil = tmp;
			tmp=tmp->ileri;
			delete sil;
		}
		Dizi[i] = NULL;
	}
}
Hash::~Hash(){
	Temizle();
}

void Hash::Yaz() const{
	cout<<"Hash Tablosu:"<<endl;
	for(int i=0;i<MAX;i++){
		if(Dizi[i] != NULL){
			cout<<"Hash["<<i<<"]->";
			for(HashDugum *tmp = Dizi[i];tmp != NULL;tmp=tmp->ileri){
				cout<<tmp->kisi->kisiAdGetir()<<"->";
			}
			cout<<"NULL"<<endl;
		}
	}
}