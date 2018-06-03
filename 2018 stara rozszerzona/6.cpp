#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//matura rozszerzona 2018 w starej formule
int main()
{
	string slowa[99999];
	ifstream slowaP;
	slowaP.open("slowa.txt");
	if(slowaP.is_open())
	{
		int i=-1;
		while(slowaP>>slowa[++i]);
		
		ofstream wynik6;
		wynik6.open("wynik6.txt");
		if(wynik6.is_open())
		{
			//6.1
			cout<<"6.1:\n";
			wynik6<<"6.1:\n";
			int konczyA=0;
			for(int j=0; j<i; j++)
				if(slowa[j][ slowa[j].length()-1 ] == 'A')
					konczyA++;
			cout<<"Na 'A' konczy sie "<<konczyA<<" slow.\n";
			wynik6<<"Na 'A' konczy sie "<<konczyA<<" slow.\n";
			
			//6.2
			cout<<"\n6.2:\n";
			wynik6<<"\n6.2:\n";
			int zawiera=0;
			for(int j=0; j<i; j+=2)
				if(slowa[j+1].find(slowa[j]) != string::npos)
				{
					cout<<slowa[j]<<" zawiera sie w "<<slowa[j+1]<<endl;
					zawiera++;
				}
			cout<<"Wierszy, w ktorych pierwsze slowo zawiera sie w drugim, jest "<<zawiera<<endl;
			wynik6<<"Wierszy, w ktorych pierwsze slowo zawiera sie w drugim, jest "<<zawiera<<endl;
			
			//6.3
			cout<<"\n6.3:\n";
			wynik6<<"\n6.3:\n";
			int anagram=0;
			for(int j=0; j<i; j+=2)
				if(slowa[j].length() == slowa[j+1].length())
				{
					for(int k=0; k<slowa[j+1].length(); k++)
					{
						if(slowa[j+1].find(slowa[j][k]) != string::npos)
						{
							if(k == slowa[j+1].length()-1)
							{
								cout<<slowa[j]<<" jest anagramem "<<slowa[j+1]<<endl;
								anagram++;
							}
						}
						else
							break;
					}
				}
			cout<<"Wierszy, w ktorych pierwsze slowo jest anagramem drugiego, jest "<<anagram<<endl;
			wynik6<<"Wierszy, w ktorych pierwsze slowo jest anagramem drugiego, jest "<<anagram<<endl;
			
			wynik6.close();
		}
		slowaP.close();
	}
}
