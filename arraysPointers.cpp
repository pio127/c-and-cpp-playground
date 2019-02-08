#include<bits/stdc++.h>
//using namespace std;

int main(){
	
	int arr[10]{};
    arr[0]=100;
    arr[10-1]=1000;
	const int rows{3};
	const int cols{5};
	int arr2D[rows][cols]{
		{1 ,  2 ,  3 , 4  , 5},
		{6 ,  7 ,  8 , 9  , 10},
		{11, 12, 13, 14, 16}
	};
	

	// 2D array printf

	for(int x{0};x<rows;x++){
		for(int y{0};y<cols;y++){
			std::cout<< std::setw(2) <<arr2D[x][y]<<" ";
		}
		std::cout<<"\n";
	}
	
	
	std::cout<<"\n";
	std::cout<<"arr size is:"<<sizeof arr;
	std::cout<<"\n";
	std::cout<<"arr adress is from: "<<arr<<" to "<<arr+9;
	// std::cout<<"\n";
	// std::cout<<typeid(arr).name();
	std::cout<<"\n";
	std::cout<<"last element is = : "<<*(arr+9);
	//std::cout<<"arr adress is from: "<<arr<<" to "<<arr+10;

	std::cout<<"\n\n";
	std::cout<<"arr2D size is:"<<sizeof arr2D;
	std::cout<<"\n";
	std::cout<<"arr2D adress is from: "<<arr2D<<" to "<<*(arr2D+3) ;
	// std::cout<<"\n";
	// std::cout<<typeid(arr2D).name();
	std::cout<<"\n";
	std::cout<<"first element is = : "<<*(*(arr2D))<<"\n";
	std::cout<<"last element is = : "<<*(*(arr2D)+(rows*cols-1));
	return 0;
}
