#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
  std::vector<int> v;

  v.push_back(0);
  v.push_back(2);
  v.push_back(4);
  v.push_back(6);
  v.push_back(8);
  v.push_back(10);

  try
  {
    std::cout << *easyfind(v, 6) << "\n";
  } catch (std::exception& e) {
    std::cout << e.what() << "\n";
  }
  
  try
  {
    std::cout << *easyfind(v, 1) << "\n";
  } catch (std::exception& e) {
    std::cout << e.what() << "\n";
  }
  return 0;
}
