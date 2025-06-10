#pragma once

#include <deque>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

/**
 * Basicaly return the iterator where the date would be next valid entry
 * All entries within the container will be constructed in a sorted ordder
 *
 *  .insert(std::find_if( []() { current_date < prev_date; ++it }, Entry _name));
 */

class BitcoinExchange
{
	private:
		struct Entry
		{
			std::chrono::year_month_day	_date;
			float						_value;
		};

		auto	parseEntry( const std::string& , const char& ) const -> Entry&;
		auto	parseCSV( const std::string& ) -> void;
		auto	parseInput( const std::string& ) -> void;

		std::ifstream		_infileUser; // Put in parser
		std::deque<Entry>	_dbMarket;
		std::deque<Entry>	_dbCoins;
		const std::string	_marketFilename;

	public:
		BitcoinExchange() = delete;
		BitcoinExchange( const std::string& _fileName );
		BitcoinExchange( const BitcoinExchange& ) = delete;
		auto operator=( const BitcoinExchange& ) -> BitcoinExchange& = delete;
		~BitcoinExchange();


};
