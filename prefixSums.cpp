#include<iostream>
using std::cout;

int main(){
	std::vector<int> prefixSums[inputArray.size()]{};
    int sum{};
    for(int i=0; i<inputArray.size(); i++){
        sum+=inputArray.At(i);
        prefixSums.At(i) = sum;
    }
    int maxSum{prefixSums[0]};
    for(int i=0; i<prefixSums.size(); i++){
        if(prefixSums[i]>maxSum)
            maxSum
}