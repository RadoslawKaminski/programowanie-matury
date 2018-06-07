#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//matura rozszerzona 2018 w starej formule
//wersja uproszczona
int main()
{
	string wyrazy[9999];
	int anakoncu = 0;
	int zawiera = 0;
	int anagram = 0;
	fstream plik_wyrazy;
	plik_wyrazy.open("slowa.txt", ios::in);
	if(plik_wyrazy.is_open())
	{
		//zapisuje wszystkie wyrazy do tablicy
		int ilosc = 0;
		while(plik_wyrazy>>wyrazy[ilosc]) //dop�ki nie dojdzie do ko�ca pliku
		{
			ilosc++;
		}
		
		for(int i=0; i<ilosc; i++) //petla przez ca�� tablic�
		{
			if(wyrazy[i][ wyrazy[i].length()-1 ] == 'A') //sprawdza czy ostatna litera to A
			{
				anakoncu++; //zwi�ksza ilosc wytaz�w, gdzie na ko�cu jest A
			}
		}	
		for(int i=0; i<ilosc; i+=2) //petla przez ca�� tablic�, co drugi wyraz
		{
			if(wyrazy[i+1].find(wyrazy[i]) != string::npos) //je�eli wyrazy[i+1] zawiera wyrazy[i]
			{										//czyli je�eli drugie zawiera pierwsze
				zawiera++;
			}
		}
				
		for(int i=0; i<ilosc; i+=2) //petla przez ca�� tablic�, co drugi wyraz
		{
			if(wyrazy[i].length() == wyrazy[i+1].length()) //je�eli pierwsze s�owo jest tej samej d�ugo�ci co drugie
			{
				for(int j=0; j<wyrazy[i+1].length(); j++) //p�tla przez drugi wyraz
				{
					if(wyrazy[i+1].find(wyrazy[i][j]) != string::npos) //je�eli drugi wyraz zawiera aktualn� litere
					{
						if(j == wyrazy[i+1].length()-1) //je�eli jeste�my ju� na ostatniej literze wyrazu
						{
							anagram++;
						}
					}
					else //je�eli nie
					{
						break; //mo�emy wyj�� z tego wyrazu
					}
				}
			}
		}
				
		fstream plik;
		plik.open("wynik6.txt", ios::out);
		if(plik.is_open())
		{
			plik<<"6.1: Na 'A' konczy sie "<<anakoncu<<" slow."<<endl;
			plik<<"6.2: Wierszy, w ktorych pierwsze slowo zawiera sie w drugim, jest "<<zawiera<<endl;
			plik<<"6.3: Wierszy, w ktorych pierwsze slowo jest anagramem drugiego, jest "<<anagram<<endl;
		}
	}
}
