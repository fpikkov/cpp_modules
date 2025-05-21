/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:29:41 by fpikkov           #+#    #+#             */
/*   Updated: 2025/05/20 13:29:42 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void )
{
	_name = "unknown";

	for (int idx = 0; idx < ITEM_MAX; idx++)
		_inventory[idx] = 0;
	for (int idx = 0; idx < STORAGE_MAX; idx++)
		_storage[idx] = 0;
}

/**
 * Your Character must have a constructor taking its name as a parameter.
 */
Character::Character( std::string const & name )
{
	_name = name;

	for (int idx = 0; idx < ITEM_MAX; idx++)
		_inventory[idx] = 0;
	for (int idx = 0; idx < STORAGE_MAX; idx++)
		_storage[idx] = 0;
}

/**
 * Must be deep copy
 * Materias of a Character must be deleted before the new ones are added to their inventory
 *
 * Delete all of this instance's AMateria's, then allocate new from other's inventory.
 * Use the clone() method to get copies of AMateria unless the subject is asking you to store addresses.
 */
Character::Character( const Character& other )
{
	*this = other;
}

/**
 * Must be deep copy
 *  Materias of a Character must be deleted before the new ones are added to their inventory
 */
Character&	Character::operator=(const Character& other )
{
	// Avoid self-assignment
	if (this != &other)
	{
		// Clear the allocated objects
		clearInventory();
		clearStorage();

		// Copy Character's name
		_name = other.getName();

		// Deep copy of other class' inventory objects
		for (int idx = 0; idx < ITEM_MAX; idx++)
		{
			if (other._inventory[idx])
				_inventory[idx] = other._inventory[idx]->clone();
		}

		// Deep copy of other class' storage objects
		for (int idx = 0; idx < STORAGE_MAX; idx++)
		{
			if (other._storage[idx])
				_storage[idx] = other._storage[idx]->clone();
		}
	}
	return (*this);
}

/**
 * Materias must be deleted when a Character is destroyed.
 */
Character::~Character( void )
{
	clearInventory();
	clearStorage();
}

std::string const & Character::getName( void ) const
{
	return (_name);
}

void	Character::equip( AMateria* m )
{
	// NULL check
	if (!m)
		return ;

	// Find an empty inventory space
	for (int idx = 0; idx < ITEM_MAX; idx++)
	{
		if (!_inventory[idx])
		{
			// Prevent double free later
			for (int i = 0; i < STORAGE_MAX; i++)
			{
				if (_storage[i] && _storage[i] == m)
					_storage[i] = 0;
			}
			_inventory[idx] = m;
			return ;
		}
	}

	// Messaging in case inventory is full
	std::cout << getName() << " can not equip additional items." << std::endl;

	// Prevent double free in case the same resource has been stored previously
	for (int i = 0; i < STORAGE_MAX; i++)
	{
		if (_storage[i] && _storage[i] == m)
			return ;
	}

	// Memory safety (place the resource in storage)
	for (int i = 0; i < STORAGE_MAX; i++)
	{
		if (!_storage[i])
		{
			_storage[i] = m;
			return ;
		}
	}

	// In case storage was full
	std::string	buffer;
	std::cout << "Character storage is full, would you like to delete the resource? y/n" << std::endl;
	std::getline(std::cin, buffer);
	if (!buffer.empty() && (buffer[0] == 'y' || buffer[0] == 'Y'))
		delete (m);

}

/**
 * The unequip() member function must NOT delete the Materia!
 */
void	Character::unequip( int idx )
{
	// Range check
	if (idx < 0 || idx >= ITEM_MAX)
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}

	// NULL check
	if (!_inventory[idx])
	{
		std::cout << "Nothing to unequip." << std::endl;
		return ;
	}

	// Move inventory item to storage
	for (int iter = 0; iter < STORAGE_MAX; iter++)
	{
		// Prevent double free if location is already stored
		if (_storage[iter] && _storage[iter] == _inventory[idx])
		{
			_inventory[idx] = 0;
			return ;
		}
		// Move inventory item to storage
		if (!_storage[iter])
		{
			_storage[iter] = _inventory[idx];
			_inventory[idx] = 0;
			return ;
		}
	}

	// What are you still doing here?
	std::cout << "The floor is full, could not unequip the requested item." << std::endl;

	std::string	buffer;
	std::cout << "Would you like to clear the items on the floor and continue with unequipping? y/n" << std::endl;
	std::getline(std::cin, buffer);
	if (!buffer.empty() && (buffer[0] == 'y' || buffer[0] == 'Y'))
	{
		Character::clearStorage();
		Character::unequip(idx);
	}
}

/**
 * The use(int, ICharacter&) member function will have to use the Materia at the
 * slot[idx], and pass the target parameter to the AMateria::use function.
 */
void	Character::use( int idx, ICharacter& target )
{
	// Range check
	if (idx < 0 || idx >= ITEM_MAX)
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}

	// NULL check
	if (!_inventory[idx])
	{
		std::cout << "Nothing to use." << std::endl;
		return ;
	}

	// Valid index, use the item
	_inventory[idx]->use(target);
}

void	Character::clearInventory( void )
{
	for (int idx = 0; idx < ITEM_MAX; idx++)
	{
		if (_inventory[idx] != 0)
		{
			delete (_inventory[idx]);
			_inventory[idx] = 0;
		}
	}
}

void	Character::clearStorage( void )
{
	for (int idx = 0; idx < STORAGE_MAX; idx++)
	{
		if (_storage[idx] != 0)
		{
			delete (_storage[idx]);
			_storage[idx] = 0;
		}
	}
}

/**
 * @brief Call manually to empty floor storage
 */
void	Character::emptyFloor( void )
{
	clearStorage();
}
