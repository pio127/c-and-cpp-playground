#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;

int maxSubArray(std::vector<int> arr){
	int maxCurrent{arr.at(0)};
	int maxGlobal{arr.at(0)};

	for(auto x{arr.begin()+1}; x!=arr.end(); ++x){
		maxCurrent=std::max(*x, maxCurrent+*x);
		if(maxCurrent > maxGlobal){
			maxGlobal = maxCurrent;
		}
	}
	return maxGlobal;
}

int main(int argc, char *argv[]){
	cout<<maxSubArray({1, 2, -3, 4})<<'\n';
	cout<<maxSubArray({1, 2, 3, 4})<<'\n';
	cout<<maxSubArray({4, -3, -2, 2, 3, 1, -2, -3, 
						4, 2, -6, -3, -1, 3, 1 ,2})<<'\n';
}
