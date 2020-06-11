#include <array>
#include <iostream>
using std::cout;

const int arraySize = 5;

void print(std::array<int, arraySize> arr) {
  auto it{arr.begin()};
  while (it != arr.end()) {
    cout << *it << " ";
    it++;
  }
  cout << "\n";
}

int main(int argc, char* argv[]) {

  std::array<int, arraySize> arr{1, 2, 3, 4};
  print(arr);
}