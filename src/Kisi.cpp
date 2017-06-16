/**
* @file Kisi.cpp
* @description  Bilgi.txt dosyas�ndan okunan degerleri huffman yap�s�yla kodlay�p hash tablosuna ekleme
* @course 1. ��retim B grubu
* @assignment 5. �dev
* @date 18.12.2014
* @author Ahmet M�nip �ito�lu - ahmetmsitoglu@hotmail.com
*/
#include "Kisi.hpp"
Kisi::Kisi(){
	kisiAd="Ad Yok";
	adDecimal=0;
}

void Kisi::kisiAdAta(string isim){
	kisiAd = isim;
}

void Kisi::adDecimalAta(string binary)
{
	int tempDec =0;
	int ust=0;
	for(int i=binary.length();i>=0;i--,ust++)
	{	
		int sayi;
		if(binary[i-1]=='1')
			sayi=1;
		else
			sayi=0;
			
		tempDec+=(sayi*ustAl(ust));
		
	}
	adDecimal=tempDec;
}

int Kisi::adDecimalGetir(){
	int deger = adDecimal;
	return deger;
}

string Kisi::kisiAdGetir(){
	string ad = kisiAd;
	return ad;
}

Kisi::~Kisi(){

}

int Kisi::ustAl(int kuvvet)
{
	int sonuc=1;
	if(kuvvet==0)
		return sonuc;
	else
		for(int i=1;i<=kuvvet;i++)
		{
			sonuc*=2;
		}
		return sonuc;	
}

