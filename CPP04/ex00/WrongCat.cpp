#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "[WrongCat] ctor: type=" << this->type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "[WrongCat] copy-ctor: from type=" << other.type << std::endl;
    this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "[WrongCat] copy-assign from type=" << other.type << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] dtor: type=" << this->type << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "[WrongCat] meow? (won't dispatch via base ref)" << std::endl;
}
