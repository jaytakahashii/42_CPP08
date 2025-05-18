#include <iostream>
#include <stack>
#include <string>

#include "MutantStack.hpp"
#include "color.hpp"

void sectionTitle(const std::string& title) {
  std::cout << BOLDWHITE << "\n=== " << title << " ===\n" << RESET;
}

void printStackState(const std::string& label, const std::stack<int>& s) {
  std::cout << BOLDYELLOW << label << " (std::stack)" << RESET << std::endl;
  std::cout << "Top: " << s.top() << std::endl;
  std::cout << "Size: " << s.size() << std::endl;
  std::cout << "Empty: " << (s.empty() ? "true" : "false") << std::endl;
}

void printMutantStackState(const std::string& label,
                           const MutantStack<int>& s) {
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

  // pop
  stdStack.pop();
  mstack.pop();

  printStackState("After Pop", stdStack);
  printMutantStackState("After Pop", mstack);

  // empty & size
  std::cout << "\n"
            << BOLDYELLOW << "std::stack is empty?: " << RESET
            << (stdStack.empty() ? "true" : "false") << std::endl;
  std::cout << BOLDGREEN << "MutantStack is empty?: " << RESET
            << (mstack.empty() ? "true" : "false") << std::endl;

  sectionTitle("MutantStack Iterator Traversal");
  mstack.push(100);
  mstack.push(200);
  mstack.push(300);

  std::cout << BOLDGREEN << "Forward: ";
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    std::cout << *it << " ";
  std::cout << RESET << std::endl;

  std::cout << BOLDGREEN << "Reverse: ";
  for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
       rit != mstack.rend(); ++rit)
    std::cout << *rit << " ";
  std::cout << RESET << std::endl;

  sectionTitle("Copy and Assignment Check");
  MutantStack<int> copyStack(mstack);
  MutantStack<int> assignedStack;
  assignedStack = mstack;
  std::cout << BOLDGREEN << "Copied stack top: " << RESET << copyStack.top()
            << std::endl;
  std::cout << BOLDGREEN << "Assigned stack size: " << RESET
            << assignedStack.size() << std::endl;

  sectionTitle("std::stack Compatibility Construction");
  std::stack<int> constructedStack(mstack);
  std::cout << BOLDYELLOW << "Constructed std::stack top: " << RESET
            << constructedStack.top() << std::endl;

  sectionTitle("MutantStack<std::string> Test");
  MutantStack<std::string> strStack;
  strStack.push("alpha");
  strStack.push("beta");
  strStack.push("gamma");

  for (MutantStack<std::string>::iterator it = strStack.begin();
       it != strStack.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  return 0;
}
