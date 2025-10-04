#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Polymorphism demo ===" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;

    std::cout << "\n=== Wrong polymorphism demo ===" << std::endl;
    WrongAnimal wrongBase;
    WrongCat wrongKitty;

    WrongAnimal& ref = wrongKitty;
    ref.makeSound();
    wrongKitty.makeSound();

    return 0;
}
