#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] ctor: type=" << this->type << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] copy-ctor: type=" << this->type << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] copy-assign from type=" << other.type << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] dtor: type=" << this->type << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "[Animal] makes a generic sound..." << std::endl;
}
