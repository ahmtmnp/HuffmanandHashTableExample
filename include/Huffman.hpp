/**
* @file Huffman.cpp
* @description  Bilgi.txt dosyasından okunan degerleri huffman yapısıyla kodlayıp hash tablosuna ekleme
* @course 1. öğretim B grubu
* @assignment 5. Ödev
* @date 18.12.2014
* @author Ahmet Münip Şitoğlu - ahmetmsitoglu@hotmail.com
*/
#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

class HuffmanDugum{
	public:
		char karakter;
		int frekans;	// Dosyada kaç kez tekrarlandığı
		string kod; 	// 01 kod karşılığı
		HuffmanDugum* sol;
		HuffmanDugum* sag;
		HuffmanDugum(char kr,int frek, HuffmanDugum* sl=NULL,HuffmanDugum *sg=NULL){
			karakter=kr;
			frekans=frek;
			sol=sl;
			sag=sg;
			kod="";
		}
		bool Yaprakmi() const{
			if(sol == NULL && sag == NULL) return true;
			return false;
		}
		bool operator==(HuffmanDugum& sag){
			if(this->karakter == sag.karakter) return true;
			else return false;
		}
		bool operator!=(HuffmanDugum& sag){
			if(this->karakter != sag.karakter) return true;
			else return false;
		}
		bool operator>(HuffmanDugum& sag){
			if(this->frekans > sag.frekans) return true;
			else return false;
		}
};
class Huffman{
	private:
		int harfler;  			// harflerin ASCII karşılıkları
		string girdi;			// dosyadan okunan girdi
		HuffmanDugum *root;
				
		HuffmanDugum* AgacOlustur(int frek[]);
		void KodOlustur(HuffmanDugum*,string);
		int MinDugumIndeks(HuffmanDugum* dugumler[]);
		void DosyaOku(string)throw(string);
		HuffmanDugum* Kok();
		void inorder(HuffmanDugum*);
		void SilSolDugum(HuffmanDugum*);
		void SilSagDugum(HuffmanDugum*);
		string KarakterleKodAra(char,HuffmanDugum*);
	public:
		string KodBul (char,Huffman&);
		Huffman(string)throw(string);
		void Kodla();
		friend ostream& operator<<(ostream&,Huffman&);
		~Huffman();
};


#endif