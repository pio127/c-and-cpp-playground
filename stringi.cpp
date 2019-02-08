#include<bits/stdc++.h>
using std::cout;
using std::string;

int main(){
	// Stringi  C++
	string a{"Jeden"};
	string b{"Dwa"};
	string c{"Trzy"};
	
	string wyrazenie=a+" + "+b;
	wyrazenie+=" = "+c;
	cout<<wyrazenie<<"\n";
	
	// Wypisanie  bez spacji
	for(char litera:wyrazenie)
		if(litera != ' ')
			cout<<litera;
	
	// Dodanie stringa ze standardu C ze stringiem ze standardu C++
	char stringC[] {"stary string"};
	string staryNowy = a+" i "+stringC;
	cout<<"\n"<<staryNowy<<"\n";
	
	//Generacja ciągu
	string repeated(10, '0');
	
	// size_t == unsigned long long int
	for(size_t x{0}; x<repeated.length(); x++){
		if((x+1)%2==0){
			// Uzycie klamer [] zamiast .at(),
			// nie zabezpiecza przed wyjsciem poza zakres.
			repeated.at(x)='1';
		}
	}
	
	string repeatedSubstr(repeated, 0, 5);
	
	cout<<repeated<<"\n";
	cout<<repeatedSubstr<<"\n";
	// Usuniecie 3 pierwszych elementow
	repeatedSubstr.erase(0,3);
	cout<<repeatedSubstr<<"\n";
	
	// Stringi ze standardu C muszą być zrzutowane na stringa Cpp
	string dwaStareStringi = (string)"Dodane"+(string)" stringi";
	cout<<dwaStareStringi<<"\n";
	
	// Szukanie podciagu w ciagu znakow
	string wordToFind = "str";
	size_t  position = dwaStareStringi.find(wordToFind);
	if(position != string::npos)
		cout<<"Znaleziono slowo "<<wordToFind<<
												" na pozycji: "<<position<<"\n";
	else
		cout<<"Brak slowa "<<wordToFind<<"\n";
}