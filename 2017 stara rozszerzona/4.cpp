#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
using namespace std;
//matura rozszerzona 2017 w starej formule
int main()
{
	string binarne[501];
	ifstream binarneP;
	binarneP.open("binarne.txt");
	
	if(binarneP.is_open())
	{
		int i=0;
		while(binarneP>>binarne[i++]);
		
		ofstream zadanie4;
		zadanie4.open("zadanie4.txt");
		if(zadanie4.is_open())
		{
			//4.1
			cout<<"4.1:\n";
			string dwucykliczne[501]={};
			int ilosc=0;
			for(int j=0; j<i; j++)
			{
				for(int k=0; k<binarne[j].length()/2; k++)
				{
					if(binarne[j][k] == binarne[j][k+binarne[j].length()/2])
					{
						if(k == binarne[j].length()/2-1)
							dwucykliczne[ilosc++] = binarne[j];
					}
					else 
						break;
				}
			}
			cout<<"Napisow dwucyklicznych jest "<<ilosc<<endl;
			int maxdwi=0;
			for(int j=0; j<ilosc; j++)
				if(dwucykliczne[maxdwi].length() < dwucykliczne[j].length())
					maxdwi = j;
			cout<<"Najdlozszy dwucykliczny w pliku to: "<<dwucykliczne[maxdwi]<<endl;
			cout<<"Jego dlugosc to: "<<dwucykliczne[maxdwi].length()<<endl;
			
			
			//4.2
			cout<<"\n4.2:\n";
			string niepoprawne[501]={};
			int liczban=0;
			int mindlugoscn=binarne[0].length();
			for(int j=0; j<i; j++)
			{
				for(int k=0; k<binarne[j].length(); k+=4)
				{
					string segment = binarne[j].substr(k, 4); //bierzemy segment sk³adaj¹cy siê z 4 znaków
					int number = bitset<4>(segment).to_ulong(); //zamieniamy segment na liczbê decymaln¹
					if(number>9)
					{
						niepoprawne[liczban++] = binarne[j];
						
						//bez zbêdnych pêtli od razu szukamy najkrótrzego, niepoprawnego napisu
						if(mindlugoscn>binarne[j].length())
							mindlugoscn = binarne[j].length();
							
						break; //wychodzimy z napisu, bo ju¿ conajmniej jeden segment jest niepoprawny
					}
				}
			}
			cout<<"Liczba niepoprawnych napisow: "<<liczban<<endl;
			cout<<"Najmniejsza dlugosc niepoprawnego napisu to "<<mindlugoscn<<endl;
			zadanie4.close();
		}
		binarneP.close();
	}
}
