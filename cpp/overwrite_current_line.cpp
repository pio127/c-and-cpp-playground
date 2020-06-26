#include <iostream>
#include <chrono>
#include <thread>

int main() {
   for (const auto& number:{"one", "two", "tree"}) {
       std::cout << number << '\r';
       std::cout << std::flush;
       std::this_thread::sleep_for(std::chrono::seconds(2));
   }
}
