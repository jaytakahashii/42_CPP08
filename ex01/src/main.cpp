#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Span.hpp"
#include "color.hpp"

static void sectionTitle(const std::string& title) {
  std::cout << BOLDWHITE << "\n=== " << title << " ===\n" << RESET;
}

int main() {
  srand(time(NULL));

  sectionTitle("Simple Test");
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

  sectionTitle("Big Test");
  try {
    Span bigSpan(100000);
    for (int i = 0; i < 10000; ++i)
      bigSpan.addNumber(rand());
    std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
  }

  sectionTitle("More Big Test");
  try {
    Span moreBigSpan(1000000);
    for (int i = 0; i < 100000; ++i)
      moreBigSpan.addNumber(rand());
    std::cout << "Shortest: " << moreBigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << moreBigSpan.longestSpan() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
  }

  sectionTitle("Exception Test");
  try {
    Span emptySpan(0);
    emptySpan.shortestSpan();
  } catch (const std::exception& e) {
    std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
  }

  sectionTitle("Iterator Range Test");
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

  sectionTitle("Iterator Range Exception Test");
  try {
    Span smallSpan(5);
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
      vec.push_back(rand());
    smallSpan.addNumbers(vec.begin(), vec.end());
  } catch (const std::exception& e) {
    std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
  }

  return 0;
}
