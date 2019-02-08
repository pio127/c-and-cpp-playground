#include<iostream>
#include<chrono>
using std::cout;

int main(){
	auto start = std::chrono::steady_clock::now();
	for(unsigned long long int x =0; x<6103515625;x++)
		int a =2;
	auto end = std::chrono::steady_clock::now();
		cout << "Elapsed time in seconds : " 
		<< std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
		<< " sec";
}