#include "Cat.h"

#include <iostream>
#include <iomanip>
#include <type_traits>
#include <stdexcept>
#include <vector>

#include "StringManip.h"

void cc::Cat::DisplayInformation() const
{
    std::cout << *this << std::endl;
}

std::ostream& cc::operator<<(std::ostream& os, const cc::Cat& cat)
{
    return os
        
        << std::left << std::setw(12) << "Name:"
        << std::right << std::setw(22) << cat.m_name << "\n"
        
        << std::left << std::setw(12) << "Color:"
        << std::right << std::setw(22) << cat.m_color << "\n"

        << std::left << std::setw(12) << "Pattern:"
        << std::right << std::setw(22) << cat.m_pattern << "\n"

        << std::left << std::setw(12) << "Birth Date:"
        << std::right << std::setw(22) << cat.m_birthDate << "\n"
        
        << std::left << std::setw(12) << "Sex:"
        << std::right << std::setw(22) << (cat.m_sex == Cat::Sex::MALE ? "M" : "F") << "\n"
        
        << std::left << std::setw(12) << "ID:"
        << std::right << std::setw(22) << cat.m_id;
}

cc::Cat::Cat() : m_birthDate({1,1,2000}), m_id(0), m_sex(Cat::Sex::FEMALE) {}

cc::Cat::Cat(const Cat& other)
    : m_name(other.m_name), m_color(other.m_color), m_pattern(other.m_pattern),
    m_id(other.m_id), m_sex(other.m_sex), m_birthDate(other.m_birthDate) {}

cc::Cat::Cat(Cat&& other) noexcept
    : m_name(std::move(other.m_name)), m_color(std::move(other.m_color)), m_pattern(std::move(other.m_pattern)),
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
    m_name = std::move(other.m_name);
    m_color = std::move(other.m_color);
    m_pattern = std::move(other.m_pattern);
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

cc::CatBuilder& cc::CatBuilder::ID(const uint32_t id)
{
    if (id < 1 || id > 999'999)
        throw std::invalid_argument("ID must be between 1 and 999999.");
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
    m_cat.m_birthDate = DateDMY(day, month, year);
    return *this;
}

cc::CatBuilder& cc::CatBuilder::BirthDate(const DateDMY& date)
{
    m_cat.m_birthDate = date;
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

cc::CatBuilder& cc::CatBuilder::PromptPopulate()
{
    std::cout << "Enter Cat Details:\n" << std::endl;

    std::cout << "Name: ";
    std::getline(std::cin, m_cat.m_name);

    std::cout << "Color: ";
    std::getline(std::cin, m_cat.m_color);

    std::cout << "Pattern: ";
    std::getline(std::cin, m_cat.m_pattern);

    bool validSex{ false };
    std::cout << "Sex: ";
    std::string sex;
    while (!validSex)
    {
        std::getline(std::cin, sex);
        try
        {
            Sex(sex);
            validSex = true;
        }
        catch (const std::exception&)
        {
            std::cout << "Invalid sex. Please enter either 'Male' or 'Female'." << std::endl;
        }
    }

    bool validDate{ false };
    std::cout << "Birth Date (DD/MM/YYYY): ";
    std::string dateString;
    uint8_t day, month; uint16_t year;
    while (!validDate)
    {
        try
        {
            std::getline(std::cin, dateString);
            std::vector<std::string> splitDateString{ cc::splitString(dateString, '/') };
            if (splitDateString.size() != 3)
                throw std::exception();

            day = std::stoi(splitDateString[0]);
            month = std::stoi(splitDateString[1]);
            year = std::stoi(splitDateString[2]);
            BirthDate(day, month, year);
            validDate = true;
        }
        catch (const std::exception&)
        {
            std::cout << "Invalid date. Please enter the date in the following format: DD/MM/YYYY." << std::endl;
            day = 0; month = 0; year = 0;
        }
    }

    bool validID{ false };
    std::cout << "ID: ";
    uint32_t id;
    while (!validID)
    {
        try
        {
            std::cin >> id;
            std::cin.ignore();
            if (std::cin.fail())
                throw std::exception();
            ID(id);
            validID = true;
        }
        catch (const std::exception&)
        {
            std::cout << "Invalid ID. An ID must be a number between 1 and 999999." << std::endl;
        }
    }

    return *this;
}
