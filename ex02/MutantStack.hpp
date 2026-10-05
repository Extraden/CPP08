#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack& other) { (void)other; };
		MutantStack& operator=(const MutantStack& other) {(void)other; };
		~MutantStack() {};

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
    {
      return this->c.begin();
    }
    
    iterator end()
    {
      return this->c.end();
    }
    

};

#endif
