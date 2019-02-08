#include<bits/stdc++.h>
using std::cout;
using std::cin;

int main(){
	
	size_t numOfElements{};
	
	// Wczytywanie do momentu
	while(1){
		if(cin>>numOfElements)
			break;
		cin.clear();
		cin.ignore();
	}
	
	// Zastosowanie wskaznika zwyklego(standard C)
	int *arrayRaw = new int[numOfElements];
	for(size_t x = 0; x<numOfElements; ++x){
		cout<<(arrayRaw[x]=x+1)<<" ";
	}
	cout<<"\n\n";
	
	// Zastosowanie smart pointera
	std::unique_ptr<int[]> arraySmart{new int[numOfElements]};
	for(size_t x = 0; x<numOfElements; ++x){
		cout<<(arraySmart[x]=x+1)<<" ";
	}
	cout<<"\n";
	
	delete []arrayRaw;
}