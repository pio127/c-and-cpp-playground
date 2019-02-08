#include<bits/stdc++.h>

	// Zmienia z wypisisywania 0,1 na false, true
	std::cout<<std::boolalpha;
	bool a{true};
	bool b{false};
	int liczba1{10}, liczba2{5};
	
	std::cout<<"(a i b)";
	if(a and b)
		std::cout<<true;
	else
		std::cout<<false;
	
	std::cout<<"\n";
	std::cout<<"(a lub b):";
	
	if(a or b)
		std::cout<<true;
	else
		std::cout<<false;
	std::cout<<"\n";
	
	if(a>b)
		std::cout<<liczba1<<">"<<liczba2;
		
}