/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:31:47 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/06 12:31:48 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(0), y(0)
{

}

Point::Point( const float x, const float y) : x(x), y(y)
{

}

Point::Point( const int x, const int y) : x(x), y(y)
{

}

Point::Point(const Point& other) : x(other.x), y(other.y)
{

}

Point&	Point::operator=(const Point& other)
{
	if (this != &other)
		throw (std::runtime_error("Cannot assign to const members"));
	return (*this);
}


Point::~Point( void )
{

}

/**
 * @brief Finds the cross product area between two vertices (this and other) and a target point.
 * @return Fixed point value of the cross product area
 */
Fixed	Point::crossProduct(Point const other, Point const point) const
{
	return ((other.x - this->x) * (point.y - this->y)) - ((other.y - this->y) * (point.x - this->x));
}
