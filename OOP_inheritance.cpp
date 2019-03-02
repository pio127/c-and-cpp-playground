#include <iostream>

class Base {
  private:
    int m_a;
    double m_b;

  public:
    Base() : m_a{0}, m_b{0} {
        std::cout << "Base (no arguments) constructor called\n";
    }
    Base(int a, double b) : m_a{a}, m_b{b} {
        std::cout << "Base (2 values provided) constructor called\n";
    }
    ~Base() { std::cout << "Base destructor called\n"; }
};
class Derived : public Base {
  private:
    int m_a;
    double m_b;

  public:
    Derived() : m_a{0}, m_b{0} {
        std::cout << "Derived (no argument) constructor called\n";
    }
    Derived(int a, double b) : m_a{a}, m_b{b} {
        std::cout << "Derived (2 values provided) constructor called\n";
    }
    ~Derived() { std::cout << "Derived destructor called\n"; }
};

int main(int argc, char* argv[]) { Derived derived{1, 2.0};  }