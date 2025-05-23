#pragma once

#include <stdexcept>
#include <vector>

class Span {
 private:
  unsigned _maxSize;
  std::vector<int> _numbers;

  Span();  // Default constructor is private to prevent usage

 public:
  // === OCF ===
  Span(const Span& other);
  Span& operator=(const Span& other);
  ~Span();

  // === Constructors ===
  Span(unsigned N);

  // === Methods ===
  void addNumber(int number);
  unsigned shortestSpan() const;
  unsigned longestSpan() const;

  template <typename Iterator>
  void addNumbers(Iterator begin, Iterator end) {
    unsigned distance = std::distance(begin, end);
    if (_numbers.size() + distance > _maxSize) {
      throw std::runtime_error("Cannot add range: would exceed maximum size");
    }
    _numbers.insert(_numbers.end(), begin, end);
  }
};
