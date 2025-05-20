#include <iostream>
#include <stack>
#include <string>

#include "MutantStack.hpp"
#include "color.hpp"

static void sectionTitle(const std::string& title) {
  std::cout << BOLDWHITE << "\n=== " << title << " ===\n" << RESET;
}

static void printStackState(const std::string& label,
                            const std::stack<int>& s) {
  std::cout << BOLDYELLOW << label << " (std::stack)" << RESET << std::endl;
  std::cout << "Top: " << s.top() << std::endl;
  std::cout << "Size: " << s.size() << std::endl;
  std::cout << "Empty: " << (s.empty() ? "true" : "false") << std::endl;
}

template <typename T>
static void printMutantStackState(const std::string& label,
                                  const MutantStack<T>& s) {
  std::cout << BOLDGREEN << label << " (MutantStack)" << RESET << std::endl;
  std::cout << "Top: " << s.top() << std::endl;
  std::cout << "Size: " << s.size() << std::endl;
  std::cout << "Empty: " << (s.empty() ? "true" : "false") << std::endl;
}

int main() {
  sectionTitle("Standard Methods Comparison");

  std::stack<int> stdStack;
  MutantStack<int> mstack;

  // push
  stdStack.push(10);
  mstack.push(10);
  stdStack.push(20);
  mstack.push(20);
  stdStack.push(30);
  mstack.push(30);

  printStackState("After Push", stdStack);
  printMutantStackState("After Push", mstack);

  // top
  std::cout << "\n"
            << BOLDYELLOW << "std::stack top(): " << RESET << stdStack.top()
            << std::endl;
  std::cout << BOLDGREEN << "MutantStack top(): " << RESET << mstack.top()
            << std::endl;
  std::cout << std::endl;

  // pop
  stdStack.pop();
  mstack.pop();

  printStackState("After Pop", stdStack);
  printMutantStackState("After Pop", mstack);

  sectionTitle("MutantStack Iterator Traversal");
  mstack.push(100);
  mstack.push(200);
  mstack.push(300);

  printMutantStackState("After Additional Push", mstack);
  std::cout << std::endl;

  std::cout << BOLDGREEN << "Forward: " << RESET;
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    std::cout << *it << " ";
  std::cout << RESET << std::endl;

  std::cout << BOLDGREEN << "Reverse: " << RESET;
  for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
       rit != mstack.rend(); ++rit)
    std::cout << *rit << " ";
  std::cout << RESET << std::endl;

  MutantStack<int>::iterator it = mstack.begin();

  std::cout << BOLDGREEN << "\nIterator Increment: " << RESET;
  it++;
  std::cout << *it << std::endl;

  sectionTitle("Copy and Assignment Check");
  MutantStack<int> copyStack(mstack);
  MutantStack<int> assignedStack;
  assignedStack = mstack;

  printMutantStackState("Copy Stack", copyStack);
  printMutantStackState("Assigned Stack", assignedStack);

  sectionTitle("Const Iterator Check");
  const MutantStack<int> constStack(mstack);

  std::cout << BOLDGREEN << "Const Forward: " << RESET;
  for (MutantStack<int>::const_iterator cit = constStack.begin();
       cit != constStack.end(); ++cit)
    std::cout << *cit << " ";
  std::cout << RESET << std::endl;

  std::cout << BOLDGREEN << "Const Reverse: " << RESET;
  for (MutantStack<int>::const_reverse_iterator crit = constStack.rbegin();
       crit != constStack.rend(); ++crit)
    std::cout << *crit << " ";
  std::cout << RESET << std::endl;

  sectionTitle("MutantStack<std::string> Test");
  MutantStack<std::string> strStack;
  strStack.push("alpha");
  strStack.push("beta");
  strStack.push("gamma");

  printMutantStackState("String Stack", strStack);
  std::cout << std::endl;

  std::cout << BOLDGREEN << "String Stack Forward: " << RESET;
  for (MutantStack<std::string>::iterator it = strStack.begin();
       it != strStack.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  std::cout << std::endl;

  return 0;
}
