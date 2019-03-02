#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
using std::cout;

class Test {
private:
public:
  std::string originalPointer;
  Test(std::string _nazwa) : originalPointer(_nazwa) {
    cout << "	Obiekt typu Test o adresie " << this << " stworzony\n";
  };
  ~Test() { cout << "	Obiekt typu Test o adresie: " << this << " usuniety\n"; }
};

void customDeleter(Test* ptr) {
  cout << "	Custom deleter used\n";
  delete ptr;
}

int main() {
  // tylko unique pointer może wskazywać na obiekt, inne nie mogą
  cout << "UNIQUE\n";
  std::unique_ptr<Test> p1{new Test{"p1"}};
  std::unique_ptr<Test> p2{new Test{"p2"}};
  cout << "	Odleglosc p2 od p1 w pamieci = "
       << (std::max(p1.get(), p2.get()) - std::min(p1.get(), p2.get())) *
              sizeof(Test)
       << " bajtow\n";

  cout << "	Wskaznik p1 = " << p1.get() << "\n";
  cout << "	Wskaznik p2 = " << p2.get() << "\n";
  // Zamania wskazywanych obietkow
  p1.swap(p2);
  cout << "	Wskaznik p1 = " << p1.get() << "\n";
  cout << "	Wskaznik p2 = " << p2.get() << "\n";
  // Wywalenie p1 i przejecie roli przez p2
  p2 = std::move(p1);
  cout << "	Wskaznik p1 = " << p1.get() << "\n";
  cout << "	Wskaznik p2 = " << p2.get() << "\n";
  //
  p2.reset();
  cout << "	Wskaznik p1 = " << p1.get() << "\n";
  cout << "	Wskaznik p2 = " << p2.get() << "\n";

  cout << "\nSHARED\n";
  // Bardziej wydajne jest przez std::make_shared inicjalizować niz przez new
  auto p3 = std::make_shared<Test>("p3");
  // Smart pointer przy inicjalizacji od razu wskazuje na nullptr
  std::shared_ptr<Test> p4;
  cout << "	Liczba wskaznikow wskazujacych na obiekt: " << p3.use_count()
       << "\n";
  cout << "	Wskaznik p4 = " << p4.get() << "\n";
  p4 = std::make_shared<Test>("p4_2");
  cout << "	Wskaznik p4 = " << p4.get() << "\n";
  cout << "	Liczba wskaznikow wskazujacych na obiekt: " << p3.use_count()
       << "\n";
  p3.reset();
  p4.reset();

  cout << "\nWEAK\n";
  // Uzywane przy wskazaniach cyklicznych: obiekt A posiada wskaznik na B i vice
  // versa
  auto p5 = std::make_shared<Test>("p5");
  cout << "	Liczba wskaznikow wskazujacych na obiekt: " << p5.use_count()
       << "\n";
  std::weak_ptr<Test> p6{p5};
  // weak pointer nie zwieksza liczby referencji
  cout << "	Liczba wskaznikow wskazujacych na obiekt: " << p5.use_count()
       << "\n";
  p5.reset();

  {
    cout << "\nDELETER\n";
    // Podanie wlasnej funkcji wywolanej w momencie usuniecia
    std::shared_ptr<Test> p7{new Test{"p7"}, customDeleter};
    std::shared_ptr<Test> p8{new Test{"p8"}, [](Test* ptr) {
                               cout << "	Custom  lambda deleter used\n";
                               delete ptr;
                             }};
  }

  cout << "\nMIXED SMART POINTERS\n";
  // Stworzenie wskaznika na wektor wskaznikow, wskazujacych na obiekty T
  std::unique_ptr<std::vector<std::shared_ptr<Test>>> vecPtr;
  vecPtr = std::make_unique<std::vector<std::shared_ptr<Test>>>();

  (*vecPtr).push_back(std::make_shared<Test>("a"));
  (*vecPtr).push_back(std::make_shared<Test>("b"));
  (*vecPtr).push_back(std::make_shared<Test>("c"));

  cout << "	Wartosci wskazywane przez wskazniki: ";
  for (const auto& a : (*vecPtr)) {
    cout << a->originalPointer << " ";
  }

  cout << "\nKONIEC PROGRAMU\n";
}