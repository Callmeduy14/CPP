/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:22:49 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/19 09:25:07 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// Fixed: Minimal fixed-point class in Bentuk Kanonik Ortodoks (Rule of Three).
// Stores raw value as int with 8 fractional bits.
class Fixed {
private:
    int                 _raw;                         // raw fixed-point value
    static const int    _fractionalBits = 8;          // number of fractional bits

public:
    // Konstruktor default: inisialisasi nilai
    Fixed();

    // Konstruktor salin
    Fixed(const Fixed& other);

    // Operator penugasan salin (operator=)
    Fixed& operator=(const Fixed& other);

    // Destruktor
    ~Fixed();

    // Fungsi akses
    int  getRawBits(void) const;                      // prints a log and returns raw value
    void setRawBits(int const raw);                   // sets raw value
};

#endif
