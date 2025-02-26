/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:33:54 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/06 18:33:56 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	bool		empty;
	std::string	first_name;
	std::string	last_name;
	std::string	nick;
	std::string	number;
	std::string	secret;
public:
			Contact(void);
	void	input(void);
	void	output(int &index);
	void	details(void);
};

#endif
