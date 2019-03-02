#include <iostream>
#include <memory>

using std::cout;
using std::shared_ptr;

template <typename T> struct ListNode {
  ListNode(const T& v) : value(v), next(nullptr) {}
  T value;
  shared_ptr<ListNode<T>> next;
};

template <typename T> void print(shared_ptr<ListNode<T>> t) {
  shared_ptr<ListNode<T>> ptr{t};
  while (ptr != nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }
  cout << " ";
}

template <typename T> bool isListPalidrome(shared_ptr<ListNode<T>> t) {
  int listSize{};
  shared_ptr<ListNode<T>> current = t;

  while (current != nullptr) {
    listSize++;
    current = current->next;
  }
  current = t;

  return false;
}

int main(int argc, char* argv[]) {

  auto head = std::make_shared<ListNode<int>>(1);
  auto element = std::make_shared<ListNode<int>>(2);
  head->next = element;
  element->next = std::make_shared<ListNode<int>>(2);
  element = element->next;
  element->next = std::make_shared<ListNode<int>>(1);
  element = element->next;
  element = head;
  print(head);
  cout << isListPalidrome(head) << "\n";
}