#include <iostream>
#include <list>
#include "Span.hpp"

int	main()
{

  // Simple tests
  
  Span sp1(10000);

  try 
  {
    for (int i = 0; i < 10000; ++i)
      sp1.addNumber(i);

    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }


  Span sp2(10000);
  try 
  {
    for (int i = 0; i < 10001; ++i)
      sp2.addNumber(i);

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  // Iterator tests
  
  Span sp3(10000);

  std::list<int> lst;

  for (int i = 0; i < 10000; ++i)
    lst.push_back(i * 10);

  try 
  {
    sp3.addNumber(lst.begin(), lst.end());

    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  Span sp4(10000);

  lst.clear();
  for (int i = 0; i < 10001; ++i)
    lst.push_back(i * 10);

  try 
  {
    sp4.addNumber(lst.begin(), lst.end());

    std::cout << sp4.shortestSpan() << std::endl;
    std::cout << sp4.longestSpan() << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

	return 0;
}
