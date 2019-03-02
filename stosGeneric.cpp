#include <iostream>
#include <string>
using std::cout;

template <typename T> struct Node {
  T value;
  Node* prev;
};

template <typename T> class Stack {
private:
  Node<T>* current{nullptr};
  Node<T>* temp{nullptr};
  int numOfElements{};

public:
  Stack() : numOfElements(0) {}
  Stack(T element_val) {
    current = new Node<T>;
    current->value = element_val;
    current->prev = nullptr;
    numOfElements++;
  }

  void show();
  void push(T);
  void pop();
  void size();
};

int main() {
  Stack<std::string> stos{};
  stos.show();
  stos.size();
  stos.push("Drugi");
  stos.show();
  stos.push("Trzeci");
  stos.show();
  stos.size();
  stos.pop();
  stos.pop();
  stos.pop();
  stos.show();
  stos.size();
  stos.push("Czwarty");
  stos.show();
}
template <typename T> void Stack<T>::show() {
  if (current != nullptr)
    std::cout << "->" << current->value << "\n";
  else
    std::cout << "Stack has no elements\n";
}
template <typename T> void Stack<T>::push(T new_value) {
  temp = current;
  current = new Node<T>;
  current->value = new_value;
  current->prev = temp;
  numOfElements++;
}
template <typename T> void Stack<T>::pop() {
  if (current != nullptr) {
    temp = current;
    current = current->prev;
    delete temp;
    numOfElements--;
  } else {
    cout << "Unable to pop because stack has no elements\n";
  }
}
template <typename T> void Stack<T>::size() {
  std::cout << "Stack size: " << numOfElements << "\n";
}
