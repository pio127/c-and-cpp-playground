#include<iostream>
const int size=1000;
int count=0;
double *ptr;
void stackOverflow();
void memoryLeak();
void goingOutOfBound();

int main(){

	//memoryLeak();

}

void goingOutOfBound(){
	int tab[10]{0};
	tab[10]=5;
	std::cout<<tab+10<<" = "<<*(tab+10);
}
void stackOverflow(){
	count++;
	stackOverflow();
}
void memoryLeak(){
	while(true){
		if(count%5000==0)
			new double[size];
		count++;
	}
}
