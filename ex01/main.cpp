#include <iostream>
#include <list>
#include "Span.hpp"

int	main()
{

  // Simple tests
  
  Span sp(10000);

  try 
  {
    for (int i = 0; i < 10000; ++i)
      sp.addNumber(i);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  try 
  {
    for (int i = 0; i < 10001; ++i)
      sp.addNumber(i);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  // Iterator tests
  
  Span sp2(10000);

  std::list<int> lst;

  for (int i = 0; i < 10000; ++i)
    lst.push_back(i * 10);

  try 
  {
    sp2.addNumber(lst.begin(), lst.end());

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  lst.clear();
  for (int i = 0; i < 10001; ++i)
    lst.push_back(i * 10);

  try 
  {
    sp2.addNumber(lst.begin(), lst.end());

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

	return 0;
}
