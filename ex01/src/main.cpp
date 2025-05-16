#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Span.hpp"
#include "color.hpp"

int main() {
  srand(time(NULL));

  std::cout << BOLDWHITE "=== Simple Test ===" RESET << std::endl;
  try {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
  }

  std::cout << BOLDWHITE "\n=== Big Test ===" RESET << std::endl;
  try {
    Span bigSpan(100000);
    for (int i = 0; i < 10000; ++i)
      bigSpan.addNumber(rand());
    std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
  }

  std::cout << BOLDWHITE "\n=== MORE BIG Test ===" RESET << std::endl;
  try {
    Span moreBigSpan(1000000);
    for (int i = 0; i < 100000; ++i)
      moreBigSpan.addNumber(rand());
    std::cout << "Shortest: " << moreBigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << moreBigSpan.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
  }

  std::cout << BOLDWHITE "\n=== Exception Test ===" RESET << std::endl;
  try {
    Span emptySpan(0);
    emptySpan.shortestSpan();
  } catch (const std::exception& e) {
    std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
  }

  std::cout << BOLDWHITE "\n=== Iterator Range Test ===" RESET << std::endl;
  try {
    Span rangeSpan(10);
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
      vec.push_back(rand() % 100);
    rangeSpan.addNumbers(vec.begin(), vec.end());
    std::cout << "Shortest: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << rangeSpan.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
  }

  std::cout << BOLDWHITE "\n=== Iterator Range Exception Test ===" RESET
            << std::endl;
  try {
    Span smallSpan(5);
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
      vec.push_back(rand() % 100);
    smallSpan.addNumbers(vec.begin(), vec.end());
  } catch (const std::exception& e) {
    std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
  }

  return 0;
}
