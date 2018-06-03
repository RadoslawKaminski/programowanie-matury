#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//matura rozszerzona 2018 w starej formule
int main()
{
	int liczby[99999];
	ifstream liczbyP;
	liczbyP.open("liczby.txt");
	if(liczbyP.is_open())
	{
		int i=-1;
		while(liczbyP>>liczby[++i]);
		
		ofstream wynik5;
		wynik5.open("wynik5.txt");
		if(wynik5.is_open())
		{
			//5.1
			cout<<"5.1:\n";
			int max;
			int j=0;
			do
			{
				max = liczby[j];
				j++;
			}while(liczby[j]%2 == 0 && j<i);
			for(int k=0; k<i; k++)
				if(liczby[k] > max && liczby[k]%2 == 0)
					max = liczby[k];
			cout<<"Najwieksza liczba parzysta to: "<<max;
					
			wynik5.close();
		}
		liczbyP.close();
	}
}
