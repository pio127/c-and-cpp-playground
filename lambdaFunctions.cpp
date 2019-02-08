#include<iostream>
using std::cout;

int main(){
	
	auto pow2 = [](int x){
		return x*2;
	};
	
	
	int a =0;
	int b=5;
	auto f1 = [&](){
		a = 2;
		b = 1;
		cout<<"tutej\n";
		return true;
	};

	// Parametr "=" w capture list oznacza działanie na kopiach
	auto f2 = [=](){
		cout<<a<<" "<<b<<"\n";;
		cout<<"tutej\n";
		return true;
	};
	
	cout<<a<<" "<<b<<"\n";
	f1();
	cout<<a<<" "<<b<<"\n";
	
	cout<<a<<" "<<b<<"\n";
	f2();
	cout<<a<<" "<<b<<"\n";
	
	
	cout<<pow2(10)<<"\n";
}
