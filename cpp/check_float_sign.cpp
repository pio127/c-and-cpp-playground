#include<iostream>

int main() {

  float negativeValue{-1}, positiveValue{1};
  
  unsigned int *castedNegativeValue = reinterpret_cast<unsigned int*>(&negativeValue);
  unsigned int *castedPositiveValue = reinterpret_cast<unsigned int*>(&positiveValue);

  std::cout << "Negative float sign: " << ((*castedNegativeValue>>31)&1) << '\n';
  std::cout << "Positive float sign: " << ((*castedPositiveValue>>31)&1) << '\n';

}
