#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <iterator>

class Span
{
  public:
    Span(unsigned int size);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);

    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end)
    {
      std::vector<int>::size_type count = static_cast<std::vector<int>::size_type>(std::distance(begin, end));
      std::vector<int>::size_type freeSpace = maxSize - numbers.size();
      if (count > freeSpace)
        throw std::runtime_error("Not enough space in container\n");

      for (Iterator it = begin; it != end; ++it)
        addNumber(*it);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

  private:
    unsigned int maxSize;
    std::vector<int> numbers;
};

#endif
