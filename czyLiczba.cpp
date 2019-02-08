#include<bits/stdc++.h>
using namespace std;

int main(){
	double x;
    stringstream ss; // strumień łańcuchowy
    string s;        // łańcuch;

    cin >> s;        // czytamy łańcuch znaków
    ss << s;         // odczytany łańcuch umieszczamy w strumieniu
    if(ss >> x)      // konwertujemy na liczbę i sprawdzamy, czy konwersja była poprawna
      cout << "LICZBA\n";
    else
      cout << "NIE LICZBA\n";
	return 0;
}