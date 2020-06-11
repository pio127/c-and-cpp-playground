#include <bits/stdc++.h>
using namespace std;

void insertionSort(int tab[], int n);
void bubbleSort(int tab[], int n);

void print(int tab[], int n);
void printStringTab(string tab[], int n);
void checkIfSorted(int tab[], int n);
bool intComparator(int x, int y);
bool stringComparator(string x, string y);

int main() {
  const int numOfElem = 6;
  // tablica STL ma ten plus, że kopiowanie jej jest przez operator przypisania
  // array<int, numOfElem> tabSTL = {9, 8 ,7 ,6, 5};
  // auto tabSTL2=tabSTL;

  int tab[numOfElem] = {5, 4, 3, 10, 2, 1};
  int tab2[numOfElem];
  int tab3[numOfElem];
  string tabString[numOfElem] = {"abcd", "bc", "aaaa", "bb", "d"};

  // 2 metody kopiowania zwykłych tablic
  // dla c++11 zalecane jest zastosowanie iteratorów
  copy(begin(tab), end(tab), begin(tab2));
  copy(tab, tab + numOfElem, tab3);

  print(tab, numOfElem);
  print(tab2, numOfElem);
  print(tab3, numOfElem);
  printStringTab(tabString, numOfElem);

  // Komparator działa tak, że jeżeli zwraca true, to elementy nie są
  // zamieniane. Jeżeli false to je zamienia, dlatego domyslnie jest x<y, gdzie
  // x jest pierwszym elementem odwrócenie warunku da tablicę posortowaną
  // malejąco.
  insertionSort(tab, numOfElem);
  bubbleSort(tab2, numOfElem);
  sort(tab3, tab3 + numOfElem, intComparator);
  sort(tabString, tabString + numOfElem, stringComparator);

  checkIfSorted(tab, numOfElem);
  print(tab, numOfElem);
  checkIfSorted(tab2, numOfElem);
  print(tab2, numOfElem);
  checkIfSorted(tab3, numOfElem);
  print(tab3, numOfElem);
  printStringTab(tabString, numOfElem);

  return 0;
}

void insertionSort(int tab[], int n) {
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (tab[i] > tab[j])
        swap(tab[i], tab[j]);
}
void bubbleSort(int tab[], int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 1; j++)
      if (tab[j] > tab[j + 1])
        swap(tab[j], tab[j + 1]);
}
void print(int tab[], int n) {
  for (int i = 0; i < n; i++)
    cout << tab[i] << " ";
  cout << "\n\n";
}
void checkIfSorted(int tab[], int n) {
  typedef enum { no = 0, yes = 1 } sorted;
  sorted isSorted = yes;
  for (int i = 0; i < n - 1; i++) {
    if (tab[i] > tab[i + 1]) {
      isSorted = no;
      break;
    }
  }
  if (isSorted == yes)
    cout << "Array is sorted\n";
  else
    cout << "Array is not sorted\n";
}
bool intComparator(int x, int y) { return x > y; }
void printStringTab(string tab[], int n) {
  for (int i = 0; i < n; i++)
    cout << tab[i] << " ";
  cout << "\n\n";
}
bool stringComparator(string x, string y) { return x > y; }