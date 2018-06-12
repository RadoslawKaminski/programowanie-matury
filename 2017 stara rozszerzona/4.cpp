#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//matura rozszerzona 2018 w starej formule
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
						{
							dwucykliczne[ilosc++] = binarne[j];
						}
					}
					else 
						break;
				}
			}
			cout<<"Napisow dwucyklicznych jest "<<ilosc<<endl;
			int maxdwi=0;
			for(int j=0; j<i; j++)
				if(dwucykliczne[maxdwi].length() < dwucykliczne[j].length())
					maxdwi = j;
			cout<<"Najdlozszy dwucykliczny w pliku to: "<<dwucykliczne[maxdwi]<<endl;
			cout<<"Jego dlugosc to: "<<dwucykliczne[maxdwi].length()<<endl;
			
			zadanie4.close();
		}
		binarneP.close();
	}
}
