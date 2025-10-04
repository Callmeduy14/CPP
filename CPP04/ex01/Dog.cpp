#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain()) {
    this->type = "Dog";
    std::cout << "[Dog] ctor: type=" << this->type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*(other.brain))) {
    std::cout << "[Dog] copy-ctor: deep copy brain" << std::endl;
    this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] copy-assign: deep copy brain" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *this->brain = *(other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "[Dog] dtor: type=" << this->type << std::endl;
}

void Dog::makeSound() const {
    std::cout << "[Dog] Woof! Woof!" << std::endl;
}

void Dog::setIdea(int idx, const std::string& idea) {
    brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const {
    return brain->getIdea(idx);
}
