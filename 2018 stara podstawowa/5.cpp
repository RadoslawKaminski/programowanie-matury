#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
//matura podstawowa 2018 w starej formule
string toString(int liczba)
{
	ostringstream ss;
	ss << liczba;
	return ss.str();
}
int main()
{
	int liczby[99999];
	ifstream liczbyP;
	liczbyP.open("test.txt");
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
			cout<<"Najwieksza liczba parzysta to: "<<max<<endl;
			
			//5.2
			cout<<"5.2:\n";
			for(int k=0; k<i; k++)
			{
				string liczba = toString(liczby[k]);
				for(int l=0; l<liczba.length()/2; l++)
				{
					if(liczba[l] == liczba[liczba.length()-l-1])
					{
						if(l == liczba.length()/2-1)
							cout<<liczba<<endl;
					}
					else
						break;
				}
			}
			
			wynik5.close();
		}
		liczbyP.close();
	}
}
