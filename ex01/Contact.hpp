/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:16:17 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/09/19 23:28:35 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
	private:
	std::string Name;
	std::string SurName;
	std::string NickName;
	std::string DarkSecret;
	int			TelNo;

	public:

	std::string ft_get_name() const;
	std::string ft_get_surName() const;
	std::string ft_get_nickName() const;
	std::string ft_get_darkSecret() const;
	int			ft_get_telNo() const;

	void	ft_set_name(std::string name);
	void	ft_set_surName(std::string surName);
	void	ft_set_nickName(std::string nickName);
	void	ft_set_darkSecret(std::string darkSecret);
	void	ft_set_telNo(int telNo);

};
# endif
