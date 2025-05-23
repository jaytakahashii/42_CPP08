#include "Span.hpp"

#include <algorithm>
#include <cstdlib>
#include <limits>

Span::Span(unsigned N) : _maxSize(N) {
}

Span::Span(const Span& other)
    : _maxSize(other._maxSize), _numbers(other._numbers) {
}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    _maxSize = other._maxSize;
    _numbers = other._numbers;
  }
  return *this;
}

Span::~Span() {
}

void Span::addNumber(int number) {
  if (_numbers.size() >= _maxSize) {
    throw std::runtime_error("Cannot add more numbers: span is full");
  }
  _numbers.push_back(number);
}

unsigned Span::shortestSpan() const {
  if (_numbers.size() <= 1) {
    throw std::runtime_error("Not enough numbers to calculate span");
  }

  std::vector<int> sorted = _numbers;
  std::sort(sorted.begin(), sorted.end());

  unsigned minSpan =
      std::numeric_limits<int>::max() - std::numeric_limits<int>::min();
  for (unsigned i = 1; i < sorted.size(); ++i) {
    unsigned diff = sorted[i] - sorted[i - 1];
    if (diff < minSpan) {
      minSpan = diff;
    }
  }
  return minSpan;
}

unsigned Span::longestSpan() const {
  if (_numbers.size() <= 1) {
    throw std::runtime_error("Not enough numbers to calculate span");
  }

  unsigned min = *std::min_element(_numbers.begin(), _numbers.end());
  unsigned max = *std::max_element(_numbers.begin(), _numbers.end());
  return max - min;
}
