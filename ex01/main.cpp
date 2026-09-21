#include <iostream>
#include "Span.hpp"

int	main()
{
  Span span(4);

  try
  {
    span.addNumber(14);
    span.addNumber(123178);
    span.addNumber(-245);
    span.addNumber(12);
    span.addNumber(14);
  } catch (std::exception& e) {
    std::cout << e.what();
  }

  std::cout << span.shortestSpan();

	return 0;
}
