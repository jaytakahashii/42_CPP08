#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Span.hpp"
#include "color.hpp"

int main() {
  try {
    std::cout << BOLDWHITE "=== Simple Test ===" RESET << std::endl;
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // 大規模テスト
    std::cout << BOLDWHITE "\n=== Big Test ===" RESET << std::endl;
    Span bigSpan(100000);
    for (int i = 0; i < 10000; ++i) {
      bigSpan.addNumber(rand());
    }

    std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;

    std::cout << BOLDWHITE "\n=== MORE BIG Test ===" RESET << std::endl;
    Span moreBigSpan(1000000);
    for (int i = 0; i < 100000; ++i) {
      moreBigSpan.addNumber(rand());
    }
    std::cout << "Shortest: " << moreBigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << moreBigSpan.longestSpan() << std::endl;

    std::cout << BOLDWHITE "\n=== Exception Test ===" RESET << std::endl;
    Span emptySpan(0);
    try {
      emptySpan.shortestSpan();
    } catch (const std::exception& e) {
      std::cerr << "Exception: " << e.what() << std::endl;
    }

  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
