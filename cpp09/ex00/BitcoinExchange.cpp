#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

// Canonical form
BitcoinExchange::BitcoinExchange() : _marketFilename(M_FILENAME) { BitcoinExchange::parseCSV(_marketFilename); }
BitcoinExchange::BitcoinExchange( const std::string& filename ) : _marketFilename(M_FILENAME)
{
	if (BitcoinExchange::parseCSV(_marketFilename))
		BitcoinExchange::calculatePrice(filename);
}
BitcoinExchange::~BitcoinExchange() { _dbMarket.clear(); }

// Member functions
/**
 * @brief Will parse a string into a struct which contains a chrono date and value member.
 */
auto	BitcoinExchange::parseEntry( const std::string& field , const char& midSep ) const -> Entry
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
auto	BitcoinExchange::parseCSV( const std::string& filename ) -> bool
{
	Entry			entry;
	std::ifstream	infileCSV(filename);
	std::string		line;

	if (!infileCSV)
	{
		std::cerr << "Error: Unable to open CSV, did you include data.csv?" << std::endl;
		return (false);
	}

	if (!std::getline(infileCSV, line))
	{
		std::cerr << "Error: parsing CSV file" << std::endl;
		infileCSV.close();
		return (false);
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
			if (it != _dbMarket.begin() && std::prev(it)->_value == entry._value)
				continue ;
			_dbMarket.insert(it, entry);
		}
		catch(...) {}
	}
	infileCSV.close();
	return (true);
}
/*
	NOTE: find_if can be readapted here to ffind a match in the database
	TODO: has to retrieve the closest Market date to the parsed date,
		then multiply the retrieved market value by the coin amount at that time.
	TODO: Print "Error: " with an explicit error when the function throws an exception.
 */
auto	BitcoinExchange::calculatePrice( const std::string& filename ) -> void
{
	Entry			entry;
	std::ifstream	infileInput(filename);
	std::string		line;

	if (!infileInput)
	{
		std::cerr << "Unable to open " << filename << std::endl;
		return ;
	}
	if (_dbMarket.empty())
	{
		std::cerr << "No exchange rate database available" << std::endl;
		return ;
	}

	if (!std::getline(infileInput, line))
	{
		std::cerr << "Error: parsing input file" << std::endl;
		infileInput.close();
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
				[entry](const Entry& e){ return (entry._date >= e._date); }
			);
			if (it != _dbMarket.end())
				printEntry(entry, (*it));
			else
				printMissingMarketData();
		}
		catch(const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
	}
	infileInput.close();
}

auto	BitcoinExchange::printEntry( const Entry& input, const Entry& market ) -> void
{
	std::string	date = BitcoinExchange::chronoToString(input._date);
	std::cout << date << " => " << input._value << " = " << (input._value * market._value) << std::endl;
}

auto	BitcoinExchange::printMissingMarketData() -> void
{
	std::cerr << "Error: missing market data" << std::endl;
}

auto	BitcoinExchange::chronoToString( std::chrono::year_month_day date ) -> std::string
{
	std::ostringstream	sstream;

	sstream << static_cast<int>(date.year()) << '-' << static_cast<unsigned>(date.month()) << '-' << static_cast<unsigned>(date.day());
	return (sstream.str());
}

auto	BitcoinExchange::launch( const std::string& filename ) -> void
{
	if (_dbMarket.empty())
		BitcoinExchange::parseCSV(_marketFilename);
	if (_dbMarket.empty())
	{
		std::cerr << "Error: parsing CSV file, did you include data.csv?" << std::endl;
		return ;
	}
	BitcoinExchange::calculatePrice(filename);
}
