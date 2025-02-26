/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:58:57 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/21 17:58:59 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*horde;

	if (N <= 0 || name.empty())
		return (NULL);
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		new (&horde[i]) Zombie(name);
	return (horde);
}
