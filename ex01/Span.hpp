#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
  public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

  private:
    int size;
};

#endif
