#include<iostream>
using std::cout;

int main(){
	cout<<"STACK ALLOCATION\n";
	
	int var1{0}, var2{0}, var3{0};
	int var4{0};
	int var5{0};
	int var6{0};
	cout<<"	Adress of var1: "<< &var1<<"\n";
	cout<<"	Adress of var2: "<< &var2<<"\n";
	cout<<"	Adress of var3: "<< &var3<<"\n";
	cout<<"	Adress of var4: "<< &var4<<"\n";
	cout<<"	Adress of var5: "<< &var5<<"\n";
	cout<<"	Adress of var6: "<< &var6<<"\n";
	
	cout<<"HEAP ALLOCATION\n";
	int *var7{new int{0}};
	int *var8{new int{0}};
	int *var9{new int{0}};
	cout<<"	Adress of var7: "<< var7<<"\n";
	cout<<"	Adress of var8: "<< var8<<"\n";
	cout<<"	Adress of var9: "<< var9<<"\n";
}