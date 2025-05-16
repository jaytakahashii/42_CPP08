#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Span.hpp"

int main() {
  try {
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // 大規模テスト
    Span bigSpan(10000);
    for (int i = 0; i < 10000; ++i) {
      bigSpan.addNumber(rand());
    }

    std::cout << "Big span (10,000 elements):" << std::endl;
    std::cout << "  Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "  Longest: " << bigSpan.longestSpan() << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
