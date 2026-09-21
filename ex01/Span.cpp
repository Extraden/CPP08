#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span(unsigned int size) : maxSize(size) {}

Span::Span(const Span& other) : maxSize(other.maxSize) {}

Span&	Span::operator=(const Span& other)
{
  if (this != &other)
    maxSize = other.maxSize;
  return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
  if (numbers.size() == maxSize)
    throw std::runtime_error("Vector is full!\n");
  numbers.push_back(n);
}


unsigned int Span::shortestSpan() const
{
  if (numbers.size() < 2)
    throw std::runtime_error("Not enough numbers in vector\n");
  std::vector<int> tmp = numbers;
  std::sort(tmp.begin(), tmp.end());

  unsigned int shortest = tmp[1] - tmp[0];

  for (std::vector<int>::iterator it = tmp.begin(); it + 1 != tmp.end(); ++it)
  {
    unsigned int currentSpan = *(it + 1) - *it;
    if (currentSpan < shortest)
      shortest = currentSpan;
  }
  return shortest;
}

unsigned int Span::longestSpan() const
{
  if (numbers.size() < 2)
    throw std::runtime_error("Not enough numbers in vector\n");
  std::vector<int> tmp(numbers);

  std::sort(tmp.begin(), tmp.end());
  return tmp.back() - tmp.front();
}
