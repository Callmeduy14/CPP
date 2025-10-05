/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:27:52 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/19 09:27:53 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& /*other*/) {
    // Members are const; assignment cannot modify them.
    // Provide a valid operator= to satisfy Bentuk Kanonik Ortodoks (Rule of Three) requirements.
    return *this;
}

Point::~Point() {}

const Fixed& Point::getX() const { return _x; }
const Fixed& Point::getY() const { return _y; }
