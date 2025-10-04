#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain()) {
    this->type = "Cat";
    std::cout << "[Cat] ctor: type=" << this->type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*(other.brain))) {
    std::cout << "[Cat] copy-ctor: deep copy brain" << std::endl;
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] copy-assign: deep copy brain" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *this->brain = *(other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "[Cat] dtor: type=" << this->type << std::endl;
}

void Cat::makeSound() const {
    std::cout << "[Cat] Meow~" << std::endl;
}

void Cat::setIdea(int idx, const std::string& idea) {
    brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const {
    return brain->getIdea(idx);
}
