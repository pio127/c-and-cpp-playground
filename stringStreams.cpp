#include<iostream>
#include<sstream>
#include<string>
using std::cout;

int main(int argc, char *argv[])
{
	// Check if integer was input
	int number{};
	std::string input{};
	
	bool isDone{};
	while(isDone == false){
		std::cin>>input;
		std::istringstream validate{input};
		if(validate>>number){
		cout<<number<<"\n";
		isDone=true;
		}
	else
		cout<<input<<" is not an integer\n";
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}