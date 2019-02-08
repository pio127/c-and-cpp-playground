#include<iostream>
#include<vector>
#include<functional>

int climbingStairs(int n){
    std::vector<int> mem{0, 1, 2};

    std::function<int (int)> stairs = [&](int n){
        if(mem.size()>static_cast<size_t>(n) || n<=2){
            return mem.at(n);
        }
        else{
            mem.emplace_back(stairs(n-1)+ stairs(n-2));
            return mem.back();
        }
        return n;
    };

    return stairs(n);
}

int main()
{
    std::cout<<climbingStairs(10)<<'\n';
}