/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:33:42 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/06 18:33:43 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
private:
	bool	empty;
	int 	last_index;
	Contact	contacts[8];
public:
			PhoneBook(void);
	void	add(void);
	void	search(void);
};

#endif
