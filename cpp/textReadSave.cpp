#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using std::cout;

int main(int argc, char* argv[]) {

  std::string fileName{"plikiTekstowe/readOnly.cpp"};
  std::ifstream file(fileName);
  if (!file) {
    std::cerr << "Could not open file\n";
    return 1;
  }
  std::string line{};
  int lineNumber{1};
  while (std::getline(file, line)) {
    cout << std::setw(10) << std::left << lineNumber << line << "\n";
    lineNumber++;
  }

  file.close();
}