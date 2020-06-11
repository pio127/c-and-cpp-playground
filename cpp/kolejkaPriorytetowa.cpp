#include <iostream>
using std::cout;

/* Warunkami kopca binarnego jest:
 *  - zaplenione wszystkie poziomy oporcz ostatniego,
 *  - w ostatnim poziomie nie mogą wystąpić przerwy,
 *  - zaden z synow nie moze miec wartosci wiekszej od ojca
 *  -
 */
struct Node {
  int value;
  std::shared_ptr<int> left;
  std::shared_ptr<int> right;
}

class Heap {
public:
  Node elem;

  Heap();
  push();
  recstruct();
  pop();
};

class int main(int argc, char* argv[]) {}