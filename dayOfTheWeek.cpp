#include<bits/stdc++.h>
using std::cout;

int main(){
	//auto now = std::chrono::system_clock::now();
	
   // zwraca ile sekund minelo od 1 stycznia 1970 
   time_t now = time(0);
   tm *ltm = localtime(&now);
   auto dayOfWeek =  ltm->tm_wday;
	
	switch(dayOfWeek){
		case 0: cout<<"niedziela \n";  break;
		case 1: cout<<"poniedzialek \n"; break;
		case 2: cout<<"wtorek \n"; break;
		case 3: cout<<"sroda \n"; break;
		case 4: cout<<"czwartek \n"; break;
		case 5: cout<<"piatek \n"; break;
		case 6: cout<<"sobota \n"; break;
	}
	
	if(dayOfWeek==0 ? true:false)
		std::cout<<"Dzisiaj jest niedziela\n";
	else 
		std::cout<<"Dzisiaj nie jest niedziela\n";
}
