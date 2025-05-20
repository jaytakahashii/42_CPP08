#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "color.hpp"
#include "easyfind.hpp"

static void sectionTitle(const std::string& title) {
  std::cout << BOLDWHITE << "\n=== " << title << " ===\n" << RESET;
}

int main() {
  try {
    sectionTitle("Vector Test");
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
      vec.push_back(i * 2);  // 0, 2, 4, ..., 18
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Found '6': ";
    std::vector<int>::iterator it = easyfind(vec, 6);
    std::cout << *it << std::endl;

    std::cout << "Found '7': ";
    it = easyfind(vec, 7);
    std::cout << *it << std::endl;
  } catch (const std::exception& e) {
    std::cerr << RED "\nException: " << e.what() << RESET << std::endl;
  }

  sectionTitle("List Test");
  try {
    std::list<int> lst;
    lst.push_back(42);
    lst.push_back(21);

    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Found '42': ";
    std::list<int>::iterator it = easyfind(lst, 42);
    std::cout << *it << std::endl;
  } catch (const std::exception& e) {
    std::cerr << RED "\nException: " << RESET << e.what() << std::endl;
  }

  sectionTitle("Deque Test");
  try {
    std::deque<int> deq;
    deq.push_back(42);
    deq.push_back(21);

    std::cout << "Deque: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Found '42': ";
    std::deque<int>::iterator it = easyfind(deq, 42);
    std::cout << *it << std::endl;
  } catch (const std::exception& e) {
    std::cerr << RED "\nException: " RESET << e.what() << std::endl;
  }
  return 0;
}
