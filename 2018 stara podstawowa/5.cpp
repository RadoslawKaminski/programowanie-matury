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
	int liczby[1001];
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
			wynik5<<"5.1:\n";
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
			wynik5<<"Najwieksza liczba parzysta to: "<<max<<endl;
			
			//5.2
			cout<<"\n5.2:\n";
			wynik5<<"\n5.2:\n";
			for(int k=0; k<i; k++)
			{
				string liczba = toString(liczby[k]);
				for(int l=0; l<liczba.length()/2; l++)
				{
					if(liczba[l] == liczba[liczba.length()-l-1])
					{
						if(l == liczba.length()/2-1)
							cout<<liczba<<endl;
							wynik5<<liczba<<endl;
					}
					else
						break;
				}
			}
			
			//5.3
			cout<<"\n5.3:\n";
			wynik5<<"\n5.3:\n";
			int suma[1001]={};
			int sumaS=0;
			cout<<"Liczby, ktorych suma cyfr jest wieksza od 30:\n";
			wynik5<<"Liczby, ktorych suma cyfr jest wieksza od 30:\n";
			for(int k=0; k<i; k++)
			{
				int liczba = liczby[k];
				while(liczba > 0)
				{
					suma[k] += liczba%10;
					liczba /= 10;
				}
				if(suma[k] > 30)
				{
					cout<<liczby[k]<<endl;
					wynik5<<liczby[k]<<endl;
				}
				sumaS += suma[k];
			}
			cout<<"Wszystkie cyfry, ktore zostaly wykorzystane do zapisu wszystkich liczb w pliku to: ";
			cout<<"1,2,3,4,5,6,7,8 oraz 9, ich suma wynosi 45\n";
			cout<<"... Chyba, ze chodzi o sume wszystkich cyfr w pliku, wynosi ona "<<sumaS;
			wynik5<<"Suma wszystkich cyfr w pliku wynosi "<<sumaS;
			
			wynik5.close();
		}
		liczbyP.close();
	}
}
