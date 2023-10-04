#include "DateDMY.h"

#include <sstream>

std::map<uint8_t, uint8_t> cc::DateDMY::monthMaxDays
{
	{ 1, 31 },
	{ 2, 29 },
	{ 3, 31 },
	{ 4, 30 },
	{ 5, 31 },
	{ 6, 30 },
    { 7, 31 },
	{ 8, 31 },
	{ 9, 30 },
	{ 10, 31 },
	{ 11, 30 },
	{ 12, 31 }
};

std::map<uint8_t, std::string> cc::DateDMY::monthNames
{
	{ 1, "January" },
	{ 2, "February" },
	{ 3, "March" },
	{ 4, "April" },
	{ 5, "May" },
	{ 6, "June" },
	{ 7, "July" },
	{ 8, "August" },
	{ 9, "September" },
	{ 10, "October" },
	{ 11, "November" },
	{ 12, "December" }
};

cc::DateDMY::DateDMY()
	: m_day(1), m_month(1), m_year(2005)
{}

cc::DateDMY::DateDMY(uint8_t day, uint8_t month, uint16_t year)
	: m_day(day), m_month(month), m_year(year)
{
	if (!monthMaxDays.count(month))
		throw std::invalid_argument("Invalid Month");
	if (day < 1 || day > monthMaxDays.at(month))
		throw std::invalid_argument("Invalid Day");
}

cc::DateDMY::DateDMY(const DateDMY& other)
	: m_day(other.m_day), m_month(other.m_month), m_year(other.m_year)
{}

cc::DateDMY::DateDMY(DateDMY&& other) noexcept
	: m_day(other.m_day), m_month(other.m_month), m_year(other.m_year)
{}

cc::DateDMY::~DateDMY() {}

cc::DateDMY& cc::DateDMY::operator=(const DateDMY& other)
{
	m_day = other.m_day;
	m_month = other.m_month;
	m_year = other.m_year;
	return *this;
}

cc::DateDMY& cc::DateDMY::operator=(DateDMY&& other) noexcept
{
	m_day = other.m_day;
	m_month = other.m_month;
	m_year = other.m_year;
	return *this;
}

std::ostream& cc::operator<<(std::ostream& os, const DateDMY& date)
{
	std::stringstream dateStream;
	dateStream << DateDMY::monthNames.at(date.m_month) << " " << +date.m_day << ", " << date.m_year;
	return os << dateStream.str();
}
