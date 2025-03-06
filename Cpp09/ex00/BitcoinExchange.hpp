/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menasy <menasy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:16:03 by menasy            #+#    #+#             */
/*   Updated: 2025/03/07 00:27:31 by menasy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <algorithm>
# include <iterator>
# include <sstream>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include <math.h>
# include <vector>
# include <utility>

class BitcoinExchange
{
	private:
		std::vector<std::pair<std::string, float> > dataMap; 
		std::vector<std::pair<std::string, std::string> > inputMap; 
		void openFileOperation(const char *file, std::ifstream& dataFile ,std::ifstream& inputFile);
		void readFile(std::ifstream& dataFile ,std::ifstream& inputFile);
		void fileToDataMap(std::string& str);
		void fileToInputMap(std::string& str);
		void displayMaps(); 
		std::string inputHandler(std::vector<std::pair<std::string, std::string> > ::iterator inputIt, std::vector<std::pair<std::string, float> > ::iterator& dataIt);
		bool isValidate(const std::string& date);
		void mapHandler();
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void btcExchange(const char *file);

		class FileErrorException: public std::exception
		{
			public:
				char const* what() const throw();
		};
		
};

#endif