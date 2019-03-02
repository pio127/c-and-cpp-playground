#include <iostream>
#include <vector>
using std::cout;

int main(int argc, char* argv[]) {

  std::vector<int> vec{};

  size_t currentSize{vec.size()}, capacity{vec.capacity()},
      maxSize{vec.max_size()};

  for (int x = 0; x < 1000000; x++) {
    vec.emplace_back(x);
    currentSize = vec.size();
    capacity = vec.capacity();

    if (currentSize == capacity) {
      vec.emplace_back();
      currentSize = vec.size();
      capacity = vec.capacity();
      // cout<<"Size: "<<currentSize<<"\n";
      cout << "Capacity: " << capacity << "\n";
    }
  }
  cout << "Max size: " << maxSize << "\n";
}