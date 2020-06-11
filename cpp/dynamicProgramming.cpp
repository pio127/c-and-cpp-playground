#include <iostream>
#include <string>
#include <vector>
using std::cout;

size_t fibonacci(int, std::vector<size_t>&);
size_t dynamicFib(int n) {

  std::vector<size_t> memoized{0, 1};
  return fibonacci(n, memoized);
}
size_t fibonacci(int n, std::vector<size_t>& memoized) {

  if (memoized.size() > (size_t)n) {
    return memoized.at(n);
  } else {
    if (n < 2) {
      return n;
    } else {
      memoized.emplace_back(fibonacci(n - 1, memoized) +
                            fibonacci(n - 2, memoized));
    }
  }
  return memoized.back();
}

int main() { cout << dynamicFib(50) << '\n'; }
