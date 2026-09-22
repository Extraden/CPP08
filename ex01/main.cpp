#include <iostream>
#include <list>
#include "Span.hpp"

int	main()
{
  Span sp(10000);

  try 
  {
    for (int i = 0; i < 10001; ++i)
      sp.addNumber(i);
  }
  catch (std::exception& e)
  {
    std::cout << e.what();
  }

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;


  // Iterator test
  std::list<int> lst;

  for (int i = 0; i < 10001; ++i)
    lst.push_back(i * 10);

  Span sp2(10000);
  try 
  {
    sp2.addNumber(lst.begin(), lst.end());
  }
  catch (std::exception& e)
  {
    std::cout << e.what();
  }
	return 0;
}
