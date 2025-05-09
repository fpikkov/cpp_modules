/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:16:29 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/09 16:16:31 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap& other );
		FragTrap&	operator=( const FragTrap& other);
		~FragTrap( void );

		void	highFivesGuys(void);
};

#endif
