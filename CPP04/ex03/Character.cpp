#include "Character.hpp"

Character::Character(const std::string& name) : _name(name) {
    for (int i = 0; i < 4; ++i) _inv[i] = 0;
}

Character::Character(const Character& other) : _name(other._name) {
    for (int i = 0; i < 4; ++i) _inv[i] = 0;
    copyInv(other);
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        clearInv();
        copyInv(other);
    }
    return *this;
}

Character::~Character() {
    clearInv();
}

void Character::clearInv() {
    for (int i = 0; i < 4; ++i) {
        if (_inv[i]) {
            delete _inv[i];
            _inv[i] = 0;
        }
    }
}

void Character::copyInv(const Character& other) {
    for (int i = 0; i < 4; ++i) {
        if (other._inv[i]) _inv[i] = other._inv[i]->clone();
        else _inv[i] = 0;
    }
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (_inv[i] == 0) {
            _inv[i] = m;
            return;
        }
    }
    // full: do nothing
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) return;
    _inv[idx] = 0; // do not delete (caller should handle)
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) return;
    if (_inv[idx]) _inv[idx]->use(target);
}
