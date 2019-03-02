#include <iostream>
#include <string>
using std::cout;

std::string decodeString(std::string s) {

  bool repeatMode{false};
  std::string repeatCounterString{};
  int openedParanthesis{};
  int repeatCounter{};
  std::string output{};
  std::string repeatString{};

  for (const char& c : s) {
    if (repeatMode) {
      if (c == '[') {
        openedParanthesis++;
        repeatString += c;
      } else if (c == ']') {
        if (openedParanthesis == 0) {
          repeatCounter = stoi(repeatCounterString);
          while (repeatCounter != 0) {
            output += decodeString(repeatString);
            repeatCounter--;
          }
          repeatMode = false;
          repeatCounterString = "";
          repeatString = "";

        } else {
          openedParanthesis--;
          repeatString += c;
        }
      } else {
        repeatString += c;
      }
    } else {
      if (c >= '0' && c <= '9') {
        repeatCounterString += c;
      } else if (c == '[') {
        repeatMode = true;
      } else {
        output += c;
      }
    }
  }
  return output;
}

int main(int argc, char* argv[]) {
  std::string input{"2[b3[a]]"};
  std::cout << "Input: " << input << "\n";
  std::cout << "Output: " << decodeString(input);
}