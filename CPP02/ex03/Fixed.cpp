/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:27:26 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/19 09:27:27 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Canonical
Fixed::Fixed() : _raw(0) {}

Fixed::Fixed(const Fixed& other) : _raw(other._raw) {}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_raw = other._raw;
    }
    return *this;
}

Fixed::~Fixed() {}

// Extra ctors
Fixed::Fixed(const int val) {
    this->_raw = val << _fractionalBits;
}

Fixed::Fixed(const float val) {
    this->_raw = static_cast<int>(roundf(val * (1 << _fractionalBits)));
}

// Fungsi konversi tipe
float Fixed::toFloat(void) const {
    return static_cast<float>(this->_raw) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_raw >> _fractionalBits;
}

// Raw
int Fixed::getRawBits(void) const { return this->_raw; }
void Fixed::setRawBits(int const raw) { this->_raw = raw; }

// Comparisons (compare raw values directly since scale is identical)
bool Fixed::operator>(const Fixed& rhs) const { return this->_raw > rhs._raw; }
bool Fixed::operator<(const Fixed& rhs) const { return this->_raw < rhs._raw; }
bool Fixed::operator>=(const Fixed& rhs) const { return this->_raw >= rhs._raw; }
bool Fixed::operator<=(const Fixed& rhs) const { return this->_raw <= rhs._raw; }
bool Fixed::operator==(const Fixed& rhs) const { return this->_raw == rhs._raw; }
bool Fixed::operator!=(const Fixed& rhs) const { return this->_raw != rhs._raw; }

// Arithmetic
Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed res;
    res._raw = this->_raw + rhs._raw;
    return res;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed res;
    res._raw = this->_raw - rhs._raw;
    return res;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed res;
    // Use wider type to avoid overflow on intermediate
    long long prod = static_cast<long long>(this->_raw) * static_cast<long long>(rhs._raw);
    res._raw = static_cast<int>(prod >> _fractionalBits);
    return res;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    Fixed res;
    // Scale numerator before dividing to keep precision
    long long num = (static_cast<long long>(this->_raw) << _fractionalBits);
    res._raw = static_cast<int>(num / rhs._raw); // may crash on division by 0
    return res;
}

// ++/--
Fixed& Fixed::operator++() {         
    ++this->_raw;
    return *this;
}

Fixed Fixed::operator++(int) {        
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed& Fixed::operator--() {          
    --this->_raw;
    return *this;
}

Fixed Fixed::operator--(int) {        
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

// Fungsi statis min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

// Operator << untuk mencetak
std::ostream& operator<<(std::ostream& os, const Fixed& fx) {
    os << fx.toFloat();
    return os;
}
