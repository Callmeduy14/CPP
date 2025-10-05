/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:27:37 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/19 09:28:12 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

// Fixed: Arithmetic-enabled fixed-point number with operator overloading.
// Implements comparisons, arithmetic, ++/--, and Fungsi statis min/max (const and non-const).
class Fixed {
private:
    int                 _raw;
    static const int    _fractionalBits = 8;

public:
    // Bentuk Kanonik Ortodoks (Rule of Three)
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // Konstruktor tambahan
    Fixed(const int val);
    Fixed(const float val);

    // Fungsi konversi tipe
    float toFloat(void) const;
    int   toInt(void) const;

    // Raw accessors
    int  getRawBits(void) const;
    void setRawBits(int const raw);

    // Operator perbandingan
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // Operator aritmetika
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const; // division by 0 may crash (as per subject)

    // Operator increment/decrement
    Fixed& operator++();    // pre-increment
    Fixed  operator++(int); // post-increment
    Fixed& operator--();    // pre-decrement
    Fixed  operator--(int); // post-decrement

    // Fungsi statis min/max
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Operator << untuk mencetak
std::ostream& operator<<(std::ostream& os, const Fixed& fx);

#endif 
