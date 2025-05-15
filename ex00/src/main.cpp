#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
  try {
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
      vec.push_back(i * 2);  // 0, 2, 4, ..., 18

    std::vector<int>::iterator it = easyfind(vec, 6);
    std::cout << "Found: " << *it << std::endl;

    it = easyfind(vec, 7);  // 例外発生
    std::cout << "Found: " << *it << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    std::list<int> lst;
    lst.push_back(42);
    lst.push_back(21);

    std::list<int>::iterator it = easyfind(lst, 42);
    std::cout << "Found in list: " << *it << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
