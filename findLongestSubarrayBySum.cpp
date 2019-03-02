#include <iostream>
#include <unordered_map>
#include <vector>
using std::cout;

std::vector<int> findLongestSubarrayBySum(int s, std::vector<int> arr) {
  std::unordered_map<int, int> prefixSums{std::pair<int, int>(0, 0)};
  std::vector<int> prefixSumsDifference{-s};
  int currentSum{0};
  int left, right, foundLeft, foundRight;
  int subarrayLength{-1};
  int subarrayLengthMax{-1};
  bool success{false};

  // Prefix sums generation
  for (size_t x{0}; x < arr.size(); ++x) {
    currentSum += arr.at(x);
    prefixSums.insert(std::pair<int, int>(currentSum, x + 1));
    prefixSumsDifference.emplace_back(currentSum - s);
  }
  // Searching if there is a value of (prefix sum - sum) in hash table
  for (size_t x{0}; x < prefixSumsDifference.size(); ++x) {
    int value = prefixSumsDifference.at(x);
    auto found = prefixSums.find(value);
    if (found != prefixSums.end()) {
      left = found->second;
      right = static_cast<int>(x);
      subarrayLength = right - left;
      if (subarrayLength > subarrayLengthMax) {
        foundLeft = left + 1;
        foundRight = right;
        success = true;
        subarrayLengthMax = subarrayLength;
      }
    }
  }
  // If there was at least one subarray of sum
  if (success) {
    return std::vector<int>{foundLeft, foundRight};
  } else {
    return std::vector<int>{-1};
  }
}

void printVector(const std::vector<int>& vec) {
  for (auto o : vec) {
    std::cout << o << " ";
  }
  std::cout << '\n';
}

int main(int argc, char* argv[]) {
  std::vector<int> output1 =
      findLongestSubarrayBySum(12, std::vector<int>{1, 2, 3, 7, 5});
  printVector(output1);

  std::vector<int> output2 = findLongestSubarrayBySum(
      1562, std::vector<int>{28,  68,  142, 130, 41,  14,  175, 2,   78,  16,
                             84,  14,  193, 25,  2,   193, 160, 71,  29,  28,
                             85,  76,  187, 99,  171, 88,  48,  5,   104, 22,
                             64,  107, 164, 11,  172, 90,  41,  165, 143, 20,
                             114, 192, 105, 19,  33,  151, 6,   176, 140, 104,
                             23,  99,  48,  185, 49,  172, 65});
  printVector(output2);
  
  std::vector<int> output3 = findLongestSubarrayBySum(3, std::vector<int>{3});
  printVector(output3);
}