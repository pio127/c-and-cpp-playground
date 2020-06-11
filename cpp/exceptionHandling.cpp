#include <iostream>
using std::cout;

class DivisionError {};

double divide(double a, double b) {
  if (b == 0)
    throw DivisionError();
  return a / b;
}

int main() {
  // zero division
  int x{};
  // Dla Clanga musi byc dodana flaga /GX
  try {
    divide(1, 0);
  } catch (...) {
    std::cerr << "Zero division error\n";
  }
}