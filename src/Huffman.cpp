/**
* @file Huffman.cpp
* @description  Bilgi.txt dosyasýndan okunan degerleri huffman yapýsýyla kodlayýp hash tablosuna ekleme
* @course 1. öðretim B grubu
* @assignment 5. Ödev
* @date 18.12.2014
* @author Ahmet Münip Þitoðlu - ahmetmsitoglu@hotmail.com
*/
#include "Huffman.hpp"

Huffman::Huffman(string dosyaYolu)throw(string){
			harfler = 256;
			girdi="";
			try{
				DosyaOku(dosyaYolu);
			}
			catch(string ex){
				throw ex;
			}
			root=NULL;
		}
void Huffman::DosyaOku(string dosyaYolu)throw(string){
	string satir;
	ifstream dosya(dosyaYolu.c_str());
	if (dosya.is_open())
	{
		while (getline(dosya,satir))
		{
			girdi+=satir;
			girdi+='\n';
		}
		dosya.close();
	}
	else throw "Dosya acilamadi"; 
}
void Huffman::Kodla(){
	char karakterler[girdi.size()-1];
	
	strcpy(karakterler, girdi.c_str());
	
	//Frekanslarý say
	int frek[harfler]; 
	// frekanslarý sýfýrla
	for(int i=0;i<harfler;i++)frek[i] = 0;
	
	for (int i = 0; i < girdi.size()-1; i++)
		frek[karakterler[i]]++;
	
	// Huffman aðacýný oluþtur
	root = AgacOlustur(frek);
	
	// 01 kodlar oluþturuluyor
	KodOlustur(root, "");
}	
HuffmanDugum* Huffman::AgacOlustur(int frek[]){
	// dosyada var olan karakterler için düðüm oluþtur.
	HuffmanDugum* dugumler[harfler];
	for(int i=0;i<harfler;i++){
		if(frek[i]>0){
			dugumler[i] = new HuffmanDugum((char)i,frek[i]);
		}
		else{
			dugumler[i] = NULL;
		}
	}
	while(true){
		int ilkIndeks = MinDugumIndeks(dugumler);				
		HuffmanDugum *min1 = dugumler[ilkIndeks];
		dugumler[ilkIndeks] = NULL;
		int ikinciIndeks = MinDugumIndeks(dugumler);
		if(ikinciIndeks == -1){
			return min1;
		}
		HuffmanDugum *min2 = dugumler[ikinciIndeks];
		dugumler[ikinciIndeks] = NULL;
		dugumler[ilkIndeks] = new HuffmanDugum(0,min1->frekans+min2->frekans,min1,min2);
	}
	
}
int Huffman::MinDugumIndeks(HuffmanDugum* dugumler[]){
	HuffmanDugum* min;
	int minIndeks=-1;
	
	// ilk null olmayan düðümü min al
	for(int i=0;i<harfler;i++){
		if(dugumler[i] != NULL){
			min = dugumler[i];
			minIndeks = i;
			break;
		}
	}
	
	for(int i=0;i<harfler;i++)
	{
		if(dugumler[i] == NULL) continue;
		
		if(*min > *(dugumler[i])) {
			min = dugumler[i];
			minIndeks = i;
		}
	}
	return minIndeks;
}

string Huffman::KodBul (char aKarakter,Huffman& huff){
	return huff.KarakterleKodAra(aKarakter,huff.Kok());
}


string Huffman::KarakterleKodAra(char aKarakter,HuffmanDugum* alt_dugum){
	string tempKod="";
	if(alt_dugum != NULL){
		KarakterleKodAra(aKarakter,alt_dugum->sol);
		if(alt_dugum->Yaprakmi()) 
			if(alt_dugum->karakter == aKarakter) 
			{
				tempKod=alt_dugum->kod;
				return tempKod;
				
			}	
		KarakterleKodAra(aKarakter,alt_dugum->sag);
	}
	
	return tempKod;
}

void Huffman::KodOlustur(HuffmanDugum* alt_dugum,string kod){
	if(!alt_dugum->Yaprakmi()){
		KodOlustur(alt_dugum->sol,kod+'0');
		KodOlustur(alt_dugum->sag,kod+'1');
	}
	else{
		alt_dugum->kod = kod;
	}
}
HuffmanDugum* Huffman::Kok(){
	return root;
}
ostream& operator<<(ostream& ekran,Huffman& sag){
	ekran<<"Huffman Agacindaki Karakterler ve Kodlari:"<<endl;
	sag.inorder(sag.Kok());
	return ekran;
}
void Huffman::inorder(HuffmanDugum* alt_dugum){
	if(alt_dugum != NULL){
		inorder(alt_dugum->sol);
		if(alt_dugum->Yaprakmi()) cout<<alt_dugum->karakter<<":"<<alt_dugum->kod<<endl;
		inorder(alt_dugum->sag);
	}
}
void Huffman::SilSolDugum(HuffmanDugum* alt_dugum){
	if(alt_dugum == NULL) return;
	if(alt_dugum->sol == NULL) {
		delete alt_dugum;
		alt_dugum = NULL;
		return;
	}	
	SilSolDugum(alt_dugum->sol);
}
void Huffman::SilSagDugum(HuffmanDugum* alt_dugum){
	if(alt_dugum == NULL) return;
	if(alt_dugum->sag == NULL) {
		delete alt_dugum;
		alt_dugum = NULL;
		return;
	}	
	SilSolDugum(alt_dugum->sag);
}
Huffman::~Huffman(){
	// Çöp oluþmamasý için aðaç temizleniyor.
	if(root != NULL){
		SilSolDugum(root->sol);
		SilSagDugum(root->sag);
		delete root;
		root = NULL;
	}	
}