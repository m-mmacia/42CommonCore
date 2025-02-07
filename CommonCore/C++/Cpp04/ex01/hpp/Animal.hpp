#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <cstdio>
# include <cstdlib>

class Animal
{
protected:
    std::string _type;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &copy);

    Animal &operator=(const Animal &src);
    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif
