#include <iostream>

#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);

  std::cout << "Top: " << mstack.top() << std::endl;
  mstack.pop();

  std::cout << "Size after pop: " << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  std::cout << "Iterating through stack:" << std::endl;
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
       ++it) {
    std::cout << *it << std::endl;
  }

  std::stack<int> copy(mstack);
  return 0;
}
