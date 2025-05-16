#include "Span.hpp"

#include <algorithm>
#include <cstdlib>
#include <limits>

Span::Span(unsigned int N) : _maxSize(N) {
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

int Span::shortestSpan() const {
  if (_numbers.size() <= 1) {
    throw std::runtime_error("Not enough numbers to calculate span");
  }

  std::vector<int> sorted = _numbers;
  std::sort(sorted.begin(), sorted.end());

  int minSpan = std::numeric_limits<int>::max();
  for (size_t i = 1; i < sorted.size(); ++i) {
    int diff = sorted[i] - sorted[i - 1];
    if (diff < minSpan) {
      minSpan = diff;
    }
  }
  return minSpan;
}

int Span::longestSpan() const {
  if (_numbers.size() <= 1) {
    throw std::runtime_error("Not enough numbers to calculate span");
  }

  int min = *std::min_element(_numbers.begin(), _numbers.end());
  int max = *std::max_element(_numbers.begin(), _numbers.end());
  return max - min;
}
