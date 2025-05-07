/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:31:52 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/06 12:31:53 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point( void );
		Point( const float x, const float y);
		Point( const int x, const int y);
		Point( const Point& other );
		Point&	operator=(const Point& other);
		~Point( void );

		Fixed	crossProduct(Point const other, Point const point) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
