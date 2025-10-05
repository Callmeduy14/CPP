/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:23:16 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/19 09:23:17 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default ctor
Fixed::Fixed() : _raw(0) {
    std::cout << "Konstruktor default: inisialisasi nilai called" << std::endl;
}

// Copy ctor
Fixed::Fixed(const Fixed& other) : _raw(other._raw) {
    std::cout << "Konstruktor salin called" << std::endl;
}

// Copy assignment
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Operator penugasan salin (operator=) called" << std::endl;
    if (this != &other) {
        this->_raw = other._raw;
    }
    return *this;
}

// Dtor
Fixed::~Fixed() {
    std::cout << "Destruktor called" << std::endl;
}

// Int ctor
Fixed::Fixed(const int val) {
    std::cout << "Int constructor called" << std::endl;
    this->_raw = val << _fractionalBits; // scale up
}

// Float ctor
Fixed::Fixed(const float val) {
    std::cout << "Float constructor called" << std::endl;
    this->_raw = static_cast<int>(roundf(val * (1 << _fractionalBits)));
}

// Fungsi konversi tipe
float Fixed::toFloat(void) const {
    return static_cast<float>(this->_raw) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_raw >> _fractionalBits;
}

// Raw accessors (compatibility)
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw) {
    this->_raw = raw;
}

// Operator << untuk mencetak
std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}
