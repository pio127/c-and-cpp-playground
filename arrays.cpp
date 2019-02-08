#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;


int main(){
	int array[]={10, 2, 3, 1, 5, 7, 6, 9, 8, 4};
    int arrayLength=10;
	// Dereference for second adress
	std::cout<<*(array+1)<<endl;

	int b;
	int a=2;
	cout<<&a<<endl;
	cout<<a<<endl;

	return 0;
}
