#include <iostream>
#include <new>
#include <string>
using std::cout;

template <typename T> struct Node {
  T value;
  Node* next;
};

template <typename T> class Queue {
private:
  Node<T>* head{nullptr};
  Node<T>* temp{nullptr};
  Node<T>* tail{nullptr};
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
  int num{0};
  std::cin >> num;
  if (num > 100000)
    return 0;
  for (int x = 0; x < num; x++) {
    kolejka.addLast(x);
  }
  kolejka.print();
  for (int x = 0.0; x < num; x++) {
    kolejka.removeFirst();
  }
  kolejka.print();
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
    temp = tail;
    tail = new Node<T>;
    tail->value = new_value;
    tail->next = nullptr;
    temp->next = tail;
    numOfElements++;
  } else {
    temp = new Node<T>;
    temp->value = new_value;
    temp->next = nullptr;
    head = temp;
    tail = temp;
    numOfElements++;
  }
}
template <typename T> void Queue<T>::removeFirst() {
  if (head != nullptr) {
    temp = head->next;
    delete head;
    head = temp;
  } else {
    cout << "Queue is empty\n";
  }
}
template <typename T> void Queue<T>::size() {
  std::cout << "Queue size: " << numOfElements << "\n";
}
