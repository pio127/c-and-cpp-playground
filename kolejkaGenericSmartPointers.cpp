#include <iostream>
#include <memory>
#include <string>
using std::cout;

template <typename T> struct Node {
  T value;
  std::shared_ptr<Node<T>> next;
};

template <typename T> class Queue {
private:
  std::shared_ptr<Node<T>> head;
  std::shared_ptr<Node<T>> temp;
  std::shared_ptr<Node<T>> tail;
  int numOfElements{};

public:
  Queue() : numOfElements(0) {}
  Queue(T element_val) { addLast(element_val); }

  void print();
  void addLast(T);
  void removeFirst();
  void size();
};

int main() {
  Queue<int> kolejka;
  int num{10};
  // std::cin>>num;
  // if(num>100)
  // return 0;

  kolejka.print();

  for (int x = 0; x < num; x++) {
    kolejka.addLast(x);
    kolejka.print();
  }
  for (int x = 0; x < num; x++) {
    kolejka.removeFirst();
    kolejka.print();
  }
}

template <typename T> void Queue<T>::print() {
  if (head != nullptr) {
    temp = head;
    while (temp != nullptr) {
      std::cout << temp->value << " ";
      temp = temp->next;
    }
    cout << "\n";
  } else
    std::cout << "Queue has no elements\n";
}
template <typename T> void Queue<T>::addLast(T new_value) {
  if (tail != nullptr) {
    temp = std::make_shared<Node<T>>();
    temp->value = new_value;
    tail->next = temp;
    temp.swap(tail);
    numOfElements++;
  } else {
    head = std::make_shared<Node<T>>();
    tail = head;
    numOfElements++;
  }
}
template <typename T> void Queue<T>::removeFirst() {
  if (head != nullptr) {
    head = head->next;
  } else {
    cout << "Queue is empty\n";
  }
}
template <typename T> void Queue<T>::size() {
  std::cout << "Queue size: " << numOfElements << "\n";
}
