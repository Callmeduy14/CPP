#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) _learned[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i) _learned[i] = 0;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            if (_learned[i]) { delete _learned[i]; _learned[i] = 0; }
            if (other._learned[i]) _learned[i] = other._learned[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        if (_learned[i]) { delete _learned[i]; _learned[i] = 0; }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (_learned[i] == 0) {
            _learned[i] = m->clone(); // store a copy
            return;
        }
    }
    // full: ignore
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (_learned[i] && _learned[i]->getType() == type) {
            return _learned[i]->clone();
        }
    }
    return 0;
}
