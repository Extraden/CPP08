#include "Span.hpp"

Span::Span(unsigned int n) : size(n) {}

Span::Span(const Span& other) : size(other.size)
{

}

Span&	Span::operator=(const Span& other) {
  if (this != &other)
    size = other.size;

  return *this;
}

Span::~Span() {}
