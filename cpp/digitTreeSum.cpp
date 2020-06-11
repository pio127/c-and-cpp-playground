#include <iostream>
#include <utility>
#include <vector>
using std::cout;

template <typename T> struct Tree {
  Tree(const T& v) : value(v), left(nullptr), right(nullptr) {}
  T value;
  Tree* left;
  Tree* right;
};
long long digitTreeSum(Tree<int>* t) {

  Tree<int>* pseudoHead = new Tree<int>(0);
  pseudoHead->left = t;
  long long output{getSums(pseudoHead).first};
  delete pseudoHead;
  return output;
}

std::pair<long long, long long> getSums(Tree<int>* t) {

  std::pair<long long, long long> prevSum{};
  long long totalSum{};
  long long multiplier{1};
  if (t->left == nullptr && t->right == nullptr) {
    totalSum = t->value;
    return std::make_pair(totalSum, multiplier);
  }
  if (t->left) {
    prevSum = getSums(t->left);
    multiplier = (prevSum.second + 1);
    totalSum += prevSum.first + (multiplier * t->value);
    std::cout << "left:" << totalSum << " ";
  }
  if (t->right) {
    prevSum = getSums(t->right);
    multiplier = (prevSum.second + 1);
    totalSum += prevSum.first + (multiplier * t->value);
    std::cout << "right:" << totalSum << " ";
  }

  return std::make_pair(totalSum, multiplier + 1);
}
int main(int argc, char* argv[]) {}