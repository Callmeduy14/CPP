#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "[AMateria] ctor: type=" << _type << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
    std::cout << "[AMateria] copy-ctor: type=" << _type << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "[AMateria] copy-assign from type=" << other._type << std::endl;
    if (this != &other) _type = other._type;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "[AMateria] dtor: type=" << _type << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& /*target*/) {
    std::cout << "* uses a generic materia *" << std::endl;
}
