#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;

void print(const std::vector<int> &vec){

	for(const auto &v:vec){
		cout<<v<<" ";
	}
	cout<<"\n";
}

int main(int argc, char *argv[]){
	
	std::vector<int> vec1{10, 3, 7, 1, 12, 15, 4};
	int kthElement = 5;
	std::make_heap(vec1.begin(), vec1.end());

	// heap pop
	for(int x=1; x<kthElement; x++){
		std::pop_heap(vec1.begin(), vec1.end());
		vec1.pop_back();
		print(vec1);
	}
}
