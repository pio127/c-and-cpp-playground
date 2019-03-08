#include <iostream>

template<typename T> struct ListNode {
  T value;
  ListNode<T> *next;
};

template<typename T> class List {
  private:
    ListNode<T> *head{nullptr};
    ListNode<T> *current{nullptr};
  public:
    List(std::initializer_list<T> values){
      for(auto v:values) {
        if(head == nullptr) {
          head = new ListNode<T>;
          head->value = v;
          current = head;
        } else {
          current->next = new ListNode<T>;
          current = current->next;
          current->value = v;
        }
      }
      current->next = nullptr;
    }
    ~List(){
      std::cout << "Freeing memory\n";
      current = head;
      ListNode<T> *previous{nullptr};
      while (current == nullptr) {
        previous = current;
        current = current->next;
        delete previous;
      }
    }

    ListNode<T> *listHead() {
      return head;
    }

};

bool isListPalindrome(ListNode<int> * l) {
    
    int listLength{0};
    ListNode<int> *head{l};
    ListNode<int> *tail{nullptr};
    ListNode<int> *middle{nullptr};
    ListNode<int> *current{nullptr};
    ListNode<int> *currentHalf{nullptr};
    
    current = head;
    if (l == nullptr) {
      return true;
    }
  
    // First iteration to obrain list length  
    while(current->next != nullptr){
        current=current->next;
        listLength++;
    }

    tail = current;
    current = head;
    int middleIndex = listLength/2;
  

    for(int x=0; x < middleIndex; x++){
      current = current->next;
    }
    middle = current;

    if (listLength == 1) {
      return true;
    } else if (listLength < 4 ) {
      return (head->value == tail->value);
    } else if (listLength < 6) {
      std::swap(middle->next, tail);
    } else {
      // Reversing second half of the list
      ListNode<int> *first{middle->next};
      ListNode<int> *second{first->next};
      ListNode<int> *last{second->next};

      middle->next = tail;
      first->next = nullptr;

      while (true) {
        second->next = first;
        first = second;
        second = last;
        if (last == nullptr) {
          break;
        }
        last = last->next;
      }
    } 
      // Comparing first with middle elements
      current = head;
      currentHalf = middle->next;
      while (currentHalf != nullptr) {
        if (current->value != currentHalf->value) {
          return false;
        }
        current = current->next;
        currentHalf = currentHalf->next;
      }

  return true;
}


int main() {
  List<int> list1 = {1, 2, 1, 4 ,1, 2, 1};
  if (isListPalindrome(list1.listHead())) {
    std::cout << "List1 is a palidrome\n"; 
  } else {
    std::cout << "List1 is not a palidrome\n"; 
  }

  List<int> list2 = {1, 1, 2, 1 ,1, 2, 1, 1};
  if (isListPalindrome(list2.listHead())) {
    std::cout << "List2 is a palidrome\n"; 
  } else {
    std::cout << "List2 is not a palidrome\n"; 
  }
}