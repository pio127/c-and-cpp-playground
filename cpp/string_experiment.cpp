#include <iostream>
#include <string>

class ByteString : public std::string {
  //const char* c_str() const = delete;
};

int main() {
  ByteString byteString{};  
  byteString.push_back('\0');
  byteString.push_back('\0');
  byteString.push_back('\0');
  byteString.push_back('a');
  byteString.push_back('\0');
  byteString.push_back('b');

  std::cout << "String [" << byteString.size() << "] = " << byteString << "\n";
  std::cout << "String [" << byteString.size() << "] = " << byteString.c_str() << "\n";
  std::cout << "String [" << byteString.size() << "] = " << byteString.data() << "\n";
}
