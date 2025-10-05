/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:23:01 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/19 09:23:02 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0) {
    std::cout << "Konstruktor default: inisialisasi nilai called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _raw(other._raw) {
    std::cout << "Konstruktor salin called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Operator penugasan salin (operator=) called" << std::endl;
    if (this != &other) {
        this->_raw = other._raw;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destruktor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw) {
    this->_raw = raw;
}
