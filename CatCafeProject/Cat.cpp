#include "Cat.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <type_traits>
#include <stdexcept>

void cc::Cat::DisplayInformation()
{
	std::cout << std::left << std::setw(12) << "Name:"
		<< std::right << std::setw(18) << m_name << std::endl;
	std::cout << std::left << std::setw(12) << "Color:"
		<< std::right << std::setw(18) << m_color << std::endl;
	std::cout << std::left << std::setw(12) << "Pattern:"
		<< std::right << std::setw(18) << m_pattern << std::endl;

	std::stringstream birthDate;
	birthDate << m_birthDate.month << "/" << m_birthDate.day << "/" << m_birthDate.year;

	std::cout << std::left << std::setw(12) << "Birth Date:"
		<< std::right << std::setw(18) << birthDate.str() << std::endl;
	
	std::cout << std::left << std::setw(12) << "Sex:"
		<< std::right << std::setw(18) << (m_sex == Sex::MALE ? "M" : "F") << std::endl;

	std::cout << std::left << std::setw(12) << "ID:"
		<< std::right << std::setw(18) << m_id << std::endl;
}

cc::Cat::Cat() : m_birthDate({1,1,2000}), m_id(0), m_sex(Cat::Sex::FEMALE) {}

cc::Cat::Cat(const Cat& other)
	: m_name(other.m_name), m_color(other.m_color), m_pattern(other.m_pattern),
	m_id(other.m_id), m_sex(other.m_sex), m_birthDate(other.m_birthDate) {}

cc::Cat::Cat(Cat&& other) noexcept
	: m_name(other.m_name), m_color(other.m_color), m_pattern(other.m_pattern),
	m_id(other.m_id), m_sex(other.m_sex), m_birthDate(other.m_birthDate) {}

cc::Cat::~Cat() {}

cc::Cat& cc::Cat::operator=(const Cat& other)
{
	m_name = other.m_name;
	m_color = other.m_color;
	m_pattern = other.m_pattern;
	m_id = other.m_id;
	m_sex = other.m_sex;
	m_birthDate = other.m_birthDate;
	return *this;
}

cc::Cat& cc::Cat::operator=(Cat&& other) noexcept
{
	m_name = other.m_name;
	m_color = other.m_color;
	m_pattern = other.m_pattern;
	m_id = other.m_id;
	m_sex = other.m_sex;
	m_birthDate = other.m_birthDate;
	return *this;
}

cc::CatBuilder& cc::CatBuilder::Name(const std::string& name)
{
	m_cat.m_name = name;
	return *this;
}

cc::CatBuilder& cc::CatBuilder::Color(const std::string& color)
{
	m_cat.m_color = color;
	return *this;
}

cc::CatBuilder& cc::CatBuilder::Pattern(const std::string& pattern)
{
	m_cat.m_pattern = pattern;
	return *this;
}

cc::CatBuilder& cc::CatBuilder::ID(const uint64_t id)
{
	m_cat.m_id = id;
	return *this;
}

cc::CatBuilder& cc::CatBuilder::Sex(const std::string& sex)
{
	if (sex != "Male" && sex != "Female")
		throw std::invalid_argument("Must enter either Male or Female");
	m_cat.m_sex = sex == "Male" ? Cat::Sex::MALE : Cat::Sex::FEMALE;
	return *this;
}

cc::CatBuilder& cc::CatBuilder::BirthDate(const uint8_t day, const uint8_t month, const uint16_t year)
{
	if (day < 1 || day > 31)
		throw std::invalid_argument("Illegal Day");
	if (month < 1 || month > 12)
		throw std::invalid_argument("Illegal Month");
	m_cat.m_birthDate = { day, month, year };
	return *this;
}

cc::Cat cc::CatBuilder::CopyBuild()
{
	return m_cat;
}

void cc::CatBuilder::ExtractBuild(Cat& moveTo)
{
	moveTo = std::move(m_cat);
}