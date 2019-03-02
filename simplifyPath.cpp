#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using std::cout;

std::string simplifyPath(std::string path) {

  std::stack<char> stack{};
  int dotCounter{};
  int elementCounter{};
  bool typingMode{false};
  stack.push('/');

  for (int x = 0; x < path.size(); x++) {
    if (path.at(x) == '.' && typingMode == false) {
      dotCounter++;
      elementCounter++;

      if (dotCounter == 2 && stack.size() > 1) {
        stack.pop();
        while (stack.top() != '/')
          stack.pop();
        if (stack.empty()) {
          stack.push('/');
        }
        dotCounter = 0;
        elementCounter = 0;
      }
    } else if (path.at(x) == '/') {
      if (dotCounter == 0 && elementCounter > 0) {
        stack.push('/');
        typingMode = false;
      }
      dotCounter = 0;
      elementCounter = 0;
    } else {
      stack.push(path.at(x));
      elementCounter++;
      typingMode = true;
    }
  }

  if (stack.size() > 1 && stack.top() == '/')
    stack.pop();

  std::string output{};
  while (stack.empty() != true) {
    output += stack.top();
    stack.pop();
  }
  std::reverse(output.begin(), output.end());
  return output;
}

int main(int argc, char* argv[]) {

  cout << simplifyPath("/mpJN/..///../../ubYgf/tFM/");
}