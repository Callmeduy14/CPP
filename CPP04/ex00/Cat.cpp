#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << "[Cat] ctor: type=" << this->type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "[Cat] copy-ctor: from type=" << other.type << std::endl;
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] copy-assign from type=" << other.type << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] dtor: type=" << this->type << std::endl;
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow~" << std::endl;
}
