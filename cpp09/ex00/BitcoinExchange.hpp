#pragma once

#include <deque>
#include <chrono>
#include <iostream>
#include <string>
#include <limits>

static constexpr const char*	MARKET_DATA_FILENAME	= "data.csv";
static constexpr float			MARKET_MAX_VALUE		= ( std::numeric_limits<float>::max() / 1000.0f );

class BitcoinExchange
{
	private:
		struct Entry
		{
			std::chrono::year_month_day	_date;
			float						_value;
		};
		class BadInputException : public std::invalid_argument
		{
			public:
				BadInputException( const std::string& );
		};

		std::deque<Entry>	_dbMarket;
		std::string			_inputFilename;
		const std::string	_marketFilename;

		auto		parseEntry( const std::string& , const char&, bool ) const -> Entry;
		auto		parseCSV( const std::string& ) -> bool;
		auto		removeDuplicates( void ) -> void;
		auto		calculatePrice( const std::string& ) -> void;
		static auto	printEntry( const Entry&, const Entry& ) -> void;
		static auto	printMissingMarketData( const Entry& ) -> void;
		static auto	chronoToString( const std::chrono::year_month_day& ) -> std::string;

	public:
		BitcoinExchange();
		BitcoinExchange( const std::string& );
		BitcoinExchange( const BitcoinExchange& ) = delete;
		auto operator=( const BitcoinExchange& ) -> BitcoinExchange& = delete;
		~BitcoinExchange();

		auto	launch( const std::string& ) -> void;
};
