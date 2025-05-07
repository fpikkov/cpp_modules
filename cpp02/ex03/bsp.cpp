/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:32:15 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/06 12:32:16 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Checks whether a given point is inside of a triangle.
 *
 * When the cross product areas of abp, bcp and cap are all of the same sign,
 * then the point lies within the triangle.
 * If one of the cross product areas is zero then the point is on the edge.
 * If more cross product areas are zero then the point is on the vector.
 *
 * @param[in] a vertix of a triangle
 * @param[in] b vertix of a triangle
 * @param[in] c vertix of a triangle
 * @param[in] point the point to check
 * @return true if point is inside the triangle, if the poiint is a vertex or
 * on the edge return false
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ab, bc, ca;

	ab = a.crossProduct(b, point);
	bc = b.crossProduct(c, point);
	ca = c.crossProduct(a, point);

	if (ab > 0 && bc > 0 && ca > 0)
		return (true);
	else if (ab < 0 && bc < 0 && ca < 0)
		return (true);
	return (false);
}
