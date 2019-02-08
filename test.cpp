#include<iostream>
#include<vector>

int main(){
    std::cout<<"siema\n";
    std::vector<int> abc{1, 2, 3};

    for(const auto &i:abc){
        std::cout<<i<<" ";
    }
}