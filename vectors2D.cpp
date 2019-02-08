#include<bits/stdc++.h>
using std::cout;
using std::endl;

int main(){
	std::vector<char> vecChar{'a', 'b', 'c'};
	std::vector<int> vecInt{'a', 'b', 'c'};
	std::vector<std::string> vecString{"adafasgxbc", "bafszfszfbc", "cbsfsfscbx"};
	
	std::vector<std::vector<int>>vec2D
	{{1 , 2, 3}, 
	  {4 , 5, 6},
	  {7 , 8, 9}};
	
	// Rozmiar wektora jest tego typu
	unsigned long long int x;
	unsigned long long int y;

	cout<<"Rozmiar zmiennej unsigned long long int : "<<sizeof(x)<<" bajtow\n";
	cout<<"Rozmiar wektora 3 charow: "<<sizeof(vecChar)<<" bajtow\n";
	cout<<"Rozmiar wektora 3 intow: "<<sizeof(vecInt)<<" bajtow\n";
	cout<<"Rozmiar wektora 3 stringow: "<<sizeof(vecString)<<" bajtow\n";
	cout<<"Rozmiar wektora "<<vec2D.size()<<" intow: "<<sizeof(vec2D)<<" bajtow\n";
	
	
	// Lepiej uzywac vec.at(x) niz vec[x], poniewaz przy wyjsciue poza zakres
	// wylapie blad.
	for(x=0;x<vecChar.size();x++){
		cout<<vecChar.at(x)<<" -> ";
		vecChar.at(x)+=1;
		cout<<vecChar.at(x)<<endl;
	}
	
	for(x=0;x<vecInt.size();x++){
		cout<<vecInt.at(x)<<" -> ";
		vecInt.at(x)+=1;
		cout<<vecInt.at(x)<<endl;
	}
	
	for(x=0;x<vecString.size();x++){
		cout<<vecString.at(x)<<" -> ";
		vecString.at(x)+=100;
		cout<<vecString.at(x)<<endl;
	}
	
	cout<<"\n Wektor 2D \n";
	
	for(x=0;x<vec2D.size();x++){
		for(y=0;y<vec2D.at(x).size();y++){
				cout<<vec2D.at(x).at(y)<<" ";
		}
		cout<<"\n";
	}	
}