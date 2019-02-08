#include <iostream>
#include <vector>
#include <unordered_map> 
using std::cout;

int makeArrayConsecutive2(std::vector<int> statues) {
    int min{statues[0]}, 
			 max{statues[0]};
    size_t i{};
    
    while(i<statues.size()){
        if(statues.at(i)>max)
            max = statues.at(i);
        if(statues.at(i)<min)
            min = statues.at(i);
		i++;
    }
    cout<<min<<" "<<max<<"\n";
    std::unordered_map<int, bool> map{};
    for(unsigned int key=min; key<=max; key++){
        map.insert(std::make_pair(key, true));
    }
    
    i = 0;
    unsigned int exists{0};
    while(i<statues.size()){
        if(map.find(statues.at(i)) != map.end())
            exists++;
		i++;
    }

    return map.size()-exists;
}

int main(){
	std::vector<int> stat{1, 2, 4, 5};
	cout<<makeArrayConsecutive2(stat);
}