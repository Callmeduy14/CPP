/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:27:44 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/19 09:27:45 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

static void test_point(const Point& a, const Point& b, const Point& c, const Point& p) {
    std::cout << "P(" << p.getX() << ", " << p.getY() << ") -> "
              << (bsp(a, b, c, p) ? "inside" : "outside")
              << std::endl;
}

int main(void) {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    test_point(a, b, c, Point(1.0f, 1.0f));   // inside
    test_point(a, b, c, Point(5.0f, 5.0f));   // inside
    test_point(a, b, c, Point(0.0f, 0.0f));   // vertex -> outside
    test_point(a, b, c, Point(5.0f, 0.0f));   // edge   -> outside
    test_point(a, b, c, Point(7.0f, 7.0f));   // outside

    return 0;
}
