#include <iostream>
#include <list>
#include <vector>
#include <climits>
#include "Span.hpp"

static void printTitle(const char* title)
{
  std::cout << "\n--- " << title << " ---" << std::endl;
}

int	main()
{
  printTitle("Subject example");
  try
  {
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << " (expected 2)" << std::endl;
    std::cout << "Longest:  " << sp.longestSpan() << " (expected 14)" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  printTitle("10000 single insertions");
  try
  {
    Span sp(10000);

    for (int i = 0; i < 10000; ++i)
      sp.addNumber(i);

    std::cout << "Shortest: " << sp.shortestSpan() << " (expected 1)" << std::endl;
    std::cout << "Longest:  " << sp.longestSpan() << " (expected 9999)" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  printTitle("Single insertion overflow");
  try
  {
    Span sp(10000);

    for (int i = 0; i < 10001; ++i)
      sp.addNumber(i);

    std::cout << "ERROR: exception expected" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << "Caught expected exception: " << e.what();
  }

  printTitle("10000 range insertions from list");
  try
  {
    std::list<int> values;

    for (int i = 0; i < 10000; ++i)
      values.push_back(i * 10);

    Span sp(10000);
    sp.addNumber(values.begin(), values.end());

    std::cout << "Shortest: " << sp.shortestSpan() << " (expected 10)" << std::endl;
    std::cout << "Longest:  " << sp.longestSpan() << " (expected 99990)" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  printTitle("Range insertion overflow and unchanged state");
  Span rangeOverflow(5);
  rangeOverflow.addNumber(100);

  std::vector<int> tooMany;
  for (int i = 0; i < 5; ++i)
    tooMany.push_back(i);

  try
  {
    rangeOverflow.addNumber(tooMany.begin(), tooMany.end());
    std::cout << "ERROR: exception expected" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << "Caught expected exception: " << e.what();
  }

  try
  {
    rangeOverflow.addNumber(110);
    std::cout << "Shortest after failed range insertion: "
              << rangeOverflow.shortestSpan() << " (expected 10)" << std::endl;
    std::cout << "Longest after failed range insertion:  "
              << rangeOverflow.longestSpan() << " (expected 10)" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  printTitle("No span with zero elements");
  try
  {
    Span empty(5);
    std::cout << empty.shortestSpan() << std::endl;
    std::cout << "ERROR: exception expected" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << "Caught expected exception: " << e.what();
  }

  printTitle("No span with one element");
  try
  {
    Span one(5);
    one.addNumber(42);
    std::cout << one.longestSpan() << std::endl;
    std::cout << "ERROR: exception expected" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << "Caught expected exception: " << e.what();
  }

  printTitle("Duplicates");
  try
  {
    Span duplicates(4);

    duplicates.addNumber(10);
    duplicates.addNumber(50);
    duplicates.addNumber(10);
    duplicates.addNumber(100);

    std::cout << "Shortest: " << duplicates.shortestSpan() << " (expected 0)" << std::endl;
    std::cout << "Longest:  " << duplicates.longestSpan() << " (expected 90)" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  printTitle("Negative values");
  try
  {
    Span negative(4);

    negative.addNumber(-100);
    negative.addNumber(-10);
    negative.addNumber(20);
    negative.addNumber(50);

    std::cout << "Shortest: " << negative.shortestSpan() << " (expected 30)" << std::endl;
    std::cout << "Longest:  " << negative.longestSpan() << " (expected 150)" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  printTitle("INT_MIN and INT_MAX");
  try
  {
    Span limits(2);

    limits.addNumber(INT_MIN);
    limits.addNumber(INT_MAX);

    std::cout << "Shortest: " << limits.shortestSpan()
              << " (expected " << UINT_MAX << ")" << std::endl;
    std::cout << "Longest:  " << limits.longestSpan()
              << " (expected " << UINT_MAX << ")" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  printTitle("Copy constructor");
  try
  {
    Span original(5);

    original.addNumber(5);
    original.addNumber(20);
    original.addNumber(50);

    Span copy(original);

    std::cout << "Shortest: " << copy.shortestSpan() << " (expected 15)" << std::endl;
    std::cout << "Longest:  " << copy.longestSpan() << " (expected 45)" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  printTitle("Copy assignment");
  try
  {
    Span original(5);

    original.addNumber(5);
    original.addNumber(20);
    original.addNumber(50);

    Span assigned(100);
    assigned = original;

    std::cout << "Shortest: " << assigned.shortestSpan() << " (expected 15)" << std::endl;
    std::cout << "Longest:  " << assigned.longestSpan() << " (expected 45)" << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }

  return 0;
}
