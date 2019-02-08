#include<iostream>
#include<vector>

void wypisz(std::vector<std::vector<int>> arr);
std::vector<std::vector<int>> rot90(std::vector<std::vector<int>> arr);

int main(){
	std::vector<std::vector<int>> a{ {10,9,6,3,7}, 
									 {6,10,2,9,7},				
	                                 {7,6,3,8,2 },
	                                 {8,9,7,9,9 },
	                                 {6,8,6,8,2 }};
	std::vector<std::vector<int>> b;  
	wypisz(a);                        
	b=rot90(a);
	wypisz(b);
	return 0;
}

void wypisz(std::vector<std::vector<int>> arr){
	for(int x=0;x<arr.size();x++){
		for(int y = 0;y<arr[x].size();y++){
			std::cout<< arr[x][y]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

std::vector<std::vector<int>> rot90(std::vector<std::vector<int>> arr){
	int lenght = arr.size();
	int min = 0;
	int max = lenght-1;
	std::vector<std::vector<int>> arrNew = arr;
	while(min<max){
		std::cout<<"max = "<<max<<"min = "<< min<<std::endl;
			for(int r = 0; r<max-min+1; r++){
				arrNew[min+r][max] = arr[min][min+r];
				arrNew[max][max-r] = arr[min+r][max];
				arrNew[max-r][min] = arr[max][max-r];
				arrNew[min][min+r] = arr[max-r][min];
			}
		wypisz(arrNew);
		min++;
		max--;
	}
	return arrNew;
}