#include<iostream>
#include<string>
using std::cout;

template<typename T>
T sum(T a, T b);
template<typename T2>
T2 dif(T2 a, T2 b);

template<typename A1, typename A2, typename A3>
class Triple
{
	private:
		A1 first;
		A2 second;
		A3 third;
	public:
		Triple(A1 f, A2 s, A3 t)
			:first{f}, second{s}, third{t}{}
			
		void printElem(){
			std::cout<<first<<"\n";
			std::cout<<second<<"\n";
			std::cout<<third<<"\n";
		}
};
int main(){
	
	cout<<sum(1, 2)<<"\n";
	cout<<dif(1, 2)<<"\n";
	cout<<sum(1.0, 2.0)<<"\n";
	cout<<dif(1.5, 2.0)<<"\n";
	cout<<sum('a', 'b')<<"\n";
	cout<<dif('z', 'a')<<"\n";
	cout<<sum(std::string{"aaa"}, std::string{"bb"})<<"\n";
	
	Triple<int, char, std::string> three(1, '1', "jeden");
	three.printElem();
}

template<typename T>
T sum(T a, T b){
	return a+b;
}

template<typename T2>
T2 dif(T2 a, T2 b){
	return a-b;
}