/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:27:57 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/19 09:28:03 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

// Point: titik 2D immutable using Fixed for coordinates.
// Anggota bertipe const untuk menegaskan immutability.
class Point {
private:
    const Fixed _x;
    const Fixed _y;

public:
    // Bentuk Kanonik Ortodoks (Rule of Three)
    Point();                                 // default: (0,0)
    Point(const float x, const float y);     // from floats
    Point(const Point& other);               // copy
    Point& operator=(const Point& other);    // assignment (tidak melakukan apa-apa karena anggota const)
    ~Point();                                // destructor

    // Fungsi akses
    const Fixed& getX() const;
    const Fixed& getY() const;
};

// Mengembalikan true jika dan hanya jika 'point' lies strictly inside triangle abc (edges/vertices => false).
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
