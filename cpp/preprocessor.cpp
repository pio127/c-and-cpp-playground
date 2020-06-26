#include <iostream>

#define WIADOMOSC "release"
#ifdef DEBUG
#define WIADOMOSC "debug"
#endif

int main() {
  std::cout << WIADOMOSC << std::endl;
}
