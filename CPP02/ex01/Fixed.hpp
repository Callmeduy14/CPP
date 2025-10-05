/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:23:50 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/19 09:25:18 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>    // roundf

// Fixed: Fixed-point number with 8 fractional bits.
// Adds conversions to/from int/float and stream insertion operator.
class Fixed {
private:
    int                 _raw;
    static const int    _fractionalBits = 8;

public:
    // Bentuk Kanonik Ortodoks (Rule of Three)
    Fixed();                                // Konstruktor default: inisialisasi nilai
    Fixed(const Fixed& other);              // Konstruktor salin
    Fixed& operator=(const Fixed& other);   // Copy assignment
    ~Fixed();                               // Destruktor

    // New constructors
    Fixed(const int val);                   // from int
    Fixed(const float val);                 // from float

    // Fungsi konversi tipe
    float toFloat(void) const;              // fixed -> float
    int   toInt(void) const;                // fixed -> int

    // Raw accessors
    int  getRawBits(void) const;            // (kept for compatibility with ex00)
    void setRawBits(int const raw);
};

// Non-member stream insertion operator (no 'friend' per module rules)
std::ostream& operator<<(std::ostream& os, const Fixed& fx);

#endif
