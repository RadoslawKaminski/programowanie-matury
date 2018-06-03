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
		while(liczbyP>>slowa[++i]);
		
		ofstream wynik5;
		wynik5.open("wynik5.txt");
		if(wynik5.is_open())
		{
			
			wynik5.close();
		}
		liczbyP.close();
	}
}
