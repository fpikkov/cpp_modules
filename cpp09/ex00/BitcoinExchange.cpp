#include "BitcoinExchange.hpp"
#include <sstream>
#include <stdexcept>
#include <algorithm>

// Canonical form
BitcoinExchange::BitcoinExchange( const std::string& filename ) : _marketFilename("data.csv")
{
	BitcoinExchange::parseCSV(_marketFilename);
}
BitcoinExchange::~BitcoinExchange() {}

// Member functions
/**
 * @brief Will parse a string into a struct which contains a chrono date and value member.
 */
auto	BitcoinExchange::parseEntry( const std::string& field , const char& midSep ) const -> Entry&
{
	Entry				entry;
	std::istringstream	sstream(field);
	int					y, m, d;
	float				v;
	char				sep1, sep2, sep3;

	if (field.empty())
		throw (std::invalid_argument("date and value entry was empty"));

	if (!(sstream >> y >> sep1 >> m >> sep2 >> d >> sep3 >> v))
		throw (std::invalid_argument("bad input"));

	if (sep1 != '-' || sep2 != '-' || sep3 != midSep)
		throw (std::invalid_argument("bad input"));
	if (v > 1000.0f)
		throw (std::invalid_argument("too large a number"));
	else if (v < 0.0f)
		throw (std::invalid_argument("not a positive number"));

	entry._date = std::chrono::year_month_day(
		std::chrono::year(y),
		std::chrono::month(static_cast<unsigned>(m)),
		std::chrono::day(static_cast<unsigned>(d)));
	entry._value = v;

	if (!entry._date.ok())
		throw (std::invalid_argument("invalid date"));

	return (entry);
}

/**
 * @brief Accepts the filename of the CSV which contains market data.
 * Will create an entry struct from each line read, then place them in a container in
 * ascending by date order.
 */
auto	BitcoinExchange::parseCSV( const std::string& filename ) -> void
{
	Entry			entry;
	std::ifstream	infileCSV(filename);
	std::string		line;

	if (!infileCSV)
	{
		std::cerr << "Unable to open CSV" << std::endl;
		return ;
	}

	while (std::getline(infileCSV, line))
	{
		try
		{
			entry = parseEntry(line, ',');
			auto it = std::find_if(
				_dbMarket.begin(),
				_dbMarket.end(),
				[entry](const Entry& e){ return (entry._date > e._date); }
			);
			if (it != _dbMarket.begin())
			{
				if (std::prev(it)->_value == entry._value)
					continue ;
			}
			_dbMarket.insert(it, entry);
		}
		catch(...) {}
	}
	infileCSV.close();
}
/*
	NOTE: find_if useless here
	TODO: has to retrieve the closest Market date to the parsed date,
		then multiply the retrieved market value by the coin amount at that time.
	TODO: Print "Error: " with an explicit error when the function throws an exception.

auto	BitcoinExchange::parseInput( const std::string& filename ) -> void
{
	Entry			entry;
	std::ifstream	infileInput(filename);
	std::string		line;

	if (!infileInput)
	{
		std::cerr << "Unable to open " << filename << std::endl;
		return ;
	}

	while (std::getline(infileInput, line))
	{
		try
		{
			entry = parseEntry(line, ',');
			auto it = std::find_if(
				_dbMarket.begin(),
				_dbMarket.end(),
				[entry](const Entry& e){ return (entry._date > e._date); }
			);
			if (it != _dbMarket.begin())
			{
				if (std::prev(it)->_value == entry._value)
					continue ;
			}
			_dbMarket.insert(it, entry);
		}
		catch(...) {}
	}
	infileInput.close();
} */
