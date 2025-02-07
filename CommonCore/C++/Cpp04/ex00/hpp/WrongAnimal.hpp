#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
protected:
    std::string _type;
public:
    WrongAnimal();
    virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal &copy);

    WrongAnimal &operator=(const WrongAnimal &src);
    void makeSound(void) const;
    std::string getType(void) const;
};

#endif
