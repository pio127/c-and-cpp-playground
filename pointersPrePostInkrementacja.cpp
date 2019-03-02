#include <iostream>
using std::cout;

int main() {

  // Wskazniki trzeba inizjalizowac, wskazujac na nullptr
  int* ptr1{nullptr};
  int var1{1000};

  cout << "adres przed uzyciem wskaznika: " << ptr1 << "\n";
  ptr1 = &var1;
  cout << "adres po wzkazaniu na zmienna: " << ptr1 << "\n";
  ptr1 = new int;
  cout << "adres rezerwowanej przestrzeni w pamieci: " << ptr1 << "\n";

  cout << "\n";

  // Uzycie podwojnego wskaznika
  int var2{127}, *ptr2{nullptr}, **ptrPtr2{nullptr};
  ptr2 = &var2;
  ptrPtr2 = &ptr2;

  //  Dereferencja *(ptr+1) == ptr[1]  uzycie zapisu klamrowego
  cout << "Wartosc zmiennej uzyskana z podwojnej dereferencji " << *(*ptrPtr2)
       << "\n";
  cout << "Wartosc zmiennej uzyskana z podwojnej dereferencji " << ptrPtr2[0][0]
       << "\n";

  int tab[]{1, 2};
  int* ptr3{tab};

  // post-inkrementacji i pre-inkrementacji dla dereferencji
  cout << "Operacja pre-inkrementacji dla dereferencji " << *++ptr3 << "\n";
  ptr3 = tab;
  cout << "Operacja post-inkrementacji dla dereferencji " << *ptr3++ << "\n";

  // Analogia przy przypisywaniu wartosci
  int var3{10};
  cout << "Operacja pre-inkrementacji " << ++var3 << "\n";
  var3 = 10;
  cout << "Operacja post-inkrementacji " << var3++ << "\n";

  delete ptr1;
}