#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << "[Dog] ctor: type=" << this->type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "[Dog] copy-ctor: from type=" << other.type << std::endl;
    this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] copy-assign from type=" << other.type << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] dtor: type=" << this->type << std::endl;
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof! Woof!" << std::endl;
}
