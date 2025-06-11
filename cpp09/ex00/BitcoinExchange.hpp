#pragma once

#include <deque>
#include <chrono>
#include <iostream>
#include <string>

/**
 * Basicaly return the iterator where the date would be next valid entry
 * All entries within the container will be constructed in a sorted ordder
 *
 *  .insert(std::find_if( []() { current_date < prev_date; ++it }, Entry _name));
 */

#ifdef M_FILENAME
# undef M_FILENAME
#endif
#define M_FILENAME "data.csv"

class BitcoinExchange
{
	private:
		struct Entry
		{
			std::chrono::year_month_day	_date;
			float						_value;
		};

		std::deque<Entry>	_dbMarket;
		std::string			_inputFilename;
		const std::string	_marketFilename;

		auto		parseEntry( const std::string& , const char& ) const -> Entry;
		auto		parseCSV( const std::string& ) -> bool;
		auto		calculatePrice( const std::string& ) -> void;
		static auto	printEntry( const Entry&, const Entry& ) -> void;
		static auto	printMissingMarketData() -> void;
		static auto	chronoToString( std::chrono::year_month_day date ) -> std::string;

	public:
		BitcoinExchange();
		BitcoinExchange( const std::string& );
		BitcoinExchange( const BitcoinExchange& ) = delete;
		auto operator=( const BitcoinExchange& ) -> BitcoinExchange& = delete;
		~BitcoinExchange();

		auto	launch( const std::string& ) -> void;
};
