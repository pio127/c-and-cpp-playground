#include<iostream>
#include<vector>
#include<unordered_set>
using std::cout;

int main(int argc, char *argv[]){
	
	std::vector<int> a{1, 2 ,3 ,4};
	std::unordered_set<int> aSet(a.begin(), a.end()); 
	for(const auto &e:aSet) {
		cout<<e<<" ";
	
	}
		

}
