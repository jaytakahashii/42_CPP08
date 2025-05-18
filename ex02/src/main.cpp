#include <iostream>
#include <string>

#include "MutantStack.hpp"
#include "color.hpp"

void sectionTitle(const std::string& title) {
  std::cout << BOLDWHITE << "\n=== " << title << " ===\n" << RESET;
}

int main() {
  // 基本テスト
  sectionTitle("Basic Stack Operations");
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << BOLDYELLOW << "Top: " << RESET << mstack.top() << std::endl;
  mstack.pop();
  std::cout << BOLDYELLOW << "Size after pop: " << RESET << mstack.size()
            << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  // イテレータテスト
  sectionTitle("Iterator Traversal (begin -> end)");
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  for (; it != ite; ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  // reverse_iterator テスト
  sectionTitle("Reverse Iterator Traversal (rbegin -> rend)");
  for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
       rit != mstack.rend(); ++rit)
    std::cout << *rit << " ";
  std::cout << std::endl;

  // const_iterator テスト
  sectionTitle("Const Iterator Check");
  const MutantStack<int> constStack = mstack;
  for (MutantStack<int>::const_iterator cit = constStack.begin();
       cit != constStack.end(); ++cit)
    std::cout << *cit << " ";
  std::cout << std::endl;

  // コピーコンストラクタ / 代入演算子テスト
  sectionTitle("Copy Constructor and Assignment Operator");
  MutantStack<int> copyStack(mstack);
  MutantStack<int> assignedStack;
  assignedStack = mstack;
  std::cout << BOLDYELLOW << "Copied stack top: " << RESET << copyStack.top()
            << std::endl;
  std::cout << BOLDYELLOW << "Assigned stack size: " << RESET
            << assignedStack.size() << std::endl;

  // std::stack への代入テスト
  sectionTitle("std::stack Compatibility");
  std::stack<int> stdStack(mstack);
  std::cout << BOLDYELLOW << "std::stack top: " << RESET << stdStack.top()
            << std::endl;

  // std::string でのテンプレート使用
  sectionTitle("MutantStack<std::string> Test");
  MutantStack<std::string> strStack;
  strStack.push("hello");
  strStack.push("world");
  strStack.push("!");
  for (MutantStack<std::string>::iterator sit = strStack.begin();
       sit != strStack.end(); ++sit)
    std::cout << *sit << " ";
  std::cout << std::endl;

  sectionTitle("All tests complete.");
  return 0;
}
