#include <chrono>
#include <iostream>
#include <memory>
#include <string>

using std::cout;

class Object {
  private:
    std::string name;
    int number;
    int* ptr;

  public:
    explicit Object(std::string m_name = "object1`", int m_number = 20)
        : name{m_name}, number{m_number} {
        ptr = new int{20};
        cout << "Constructor call\n";
    }

    ~Object() { cout << "Destructor call\n"; }

    Object(const Object& source) : name{source.name}, number{source.number} {
        cout << "Copy contructor call\n";
    }
};

int main(int argc, char* argv[]) {
    std::unique_ptr<Object> ptr1{new Object{}};
    std::unique_ptr<Object> ptr2{new Object{*ptr1}};
    ptr1 = std::move(ptr2);
    ptr1 = std::move(nullptr);

    cout << "Koniec\n";
}