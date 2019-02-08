#include<iostream>
#include<vector>
using std::cout;

void printBinary(int n){
	
}
int main(int argc, char *argv[]){
	std::vector<int> vec{1, 1, 2, 3 ,4 , 3, 5, 2, 4};
	std::vector<int> vec2{1, 2, 3, 4, 6};
	std::vector<int> vec3{1, 2, 3, 4, 5, 6};
	int val{0};
	for(const auto &v:vec){
		val^=v;
		cout<<v<<": "<<val<<" \n";
	}
	cout<<" \n";
	int val1{};
	for(const auto &v:vec2){
		val1^=v;
		cout<<v<<": "<<val1<<" \n";
	}
	cout<<" \n";
	int val2{};
	for(const auto &v:vec3){
		val2^=v;
		cout<<v<<": "<<val2<<" \n";
	}
	
	cout<<"val2 xor val1 = "<<(val2^val1)<<"\n";
}