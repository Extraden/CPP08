#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
  public:
    Span(unsigned int size);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

  private:
    unsigned int maxSize;
    std::vector<int> numbers;
};

#endif
