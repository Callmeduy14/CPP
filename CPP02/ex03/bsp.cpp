/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 09:25:48 by yyudi             #+#    #+#             */
/*   Updated: 2025/09/19 09:25:49 by yyudi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Helper: luas bertanda (2x luas segitiga) via cross product (2x triangle area) via cross product orientation.
// sign(p1, p2, p3) > 0 => left turn; < 0 => right turn; == 0 => collinear.
static float sign_orient(const Point& p1, const Point& p2, const Point& p3) {
    float x1 = p1.getX().toFloat();
    float y1 = p1.getY().toFloat();
    float x2 = p2.getX().toFloat();
    float y2 = p2.getY().toFloat();
    float x3 = p3.getX().toFloat();
    float y3 = p3.getY().toFloat();

    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float s1 = sign_orient(point, a, b);
    float s2 = sign_orient(point, b, c);
    float s3 = sign_orient(point, c, a);

    // Exclude edges/vertices explicitly
    if (s1 == 0.0f || s2 == 0.0f || s3 == 0.0f)
        return false;

    bool has_neg = (s1 < 0.0f) || (s2 < 0.0f) || (s3 < 0.0f);
    bool has_pos = (s1 > 0.0f) || (s2 > 0.0f) || (s3 > 0.0f);

    // Strictly inside (benar-benar di dalam segitiga) if all three have the same sign
    return !(has_neg && has_pos);
}
