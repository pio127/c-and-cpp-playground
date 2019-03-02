#include <iostream>
#include <memory>
#include <string>
using std::cout;

template <typename T> struct Node {
  T value;
  std::shared_ptr<Node<T>> next;
};

template <typename T> class List {
private:
  std::shared_ptr<Node<T>> head;
  std::shared_ptr<Node<T>> tail;
  
public:
  // List();
  List(T value);
  void add(T value);
  void print();
  void reverse();
};

int main() {
  List<int> list1(1);
  list1.add(2);
  list1.add(3);
  list1.add(4);
  list1.add(5);
  list1.print();
  // Reverse and add 0
  list1.reverse();
  list1.add(0);
  list1.print();
  // Another reverse     
  list1.reverse();
  list1.print();
}

template <typename T> List<T>::List(T value) {
  head = std::make_shared<Node<T>>();
  head->value = value;
  head->next = nullptr;
  tail = head;
}

template <typename T> void List<T>::add(T value) {
  auto newNode = std::make_shared<Node<T>>();
  newNode->value = value;
  newNode->next = nullptr;
  tail->next = newNode;
  tail = newNode;
}

template <typename T> void List<T>::print() {
  std::shared_ptr<Node<T>> current = head;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << '\n';
}

template <typename T> void List<T>::reverse() {
  std::shared_ptr<Node<T>> current = head;
  std::shared_ptr<Node<T>> second;
  std::shared_ptr<Node<T>> third;

  if (head == tail) {
    return;
  }

  second = current->next;
  third = current->next->next;

  while (third != nullptr) {
    second->next = current;
    current = second;
    second = third;
    third = third->next;
  }

  second->next = current;
  head->next = nullptr;
  head.swap(tail);
}