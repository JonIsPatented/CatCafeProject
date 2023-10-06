#include "Customer.h"

#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>

cc::Customer::Customer()
    : m_firstName("None"), m_lastName("None"), m_phoneNumber(0)
{}

cc::Customer::Customer(const std::string& firstName, const std::string& lastName, const uint16_t phoneNumber)
    : m_firstName(firstName), m_lastName(lastName)
{
    SetPhoneNumber(phoneNumber);
}

cc::Customer::Customer(const Customer& other)
    : m_firstName(other.m_firstName), m_lastName(other.m_lastName), m_phoneNumber(other.m_phoneNumber)
{}

cc::Customer::Customer(Customer&& other) noexcept
    : m_firstName(std::move(other.m_firstName)), m_lastName(std::move(other.m_lastName)),
    m_phoneNumber(other.m_phoneNumber)
{}

cc::Customer::~Customer() {}

cc::Customer& cc::Customer::operator=(const Customer& other)
{
    m_firstName = other.m_firstName;
    m_lastName = other.m_lastName;
    m_phoneNumber = other.m_phoneNumber;
    return *this;
}

cc::Customer& cc::Customer::operator=(Customer&& other) noexcept
{
    m_firstName = std::move(other.m_firstName);
    m_lastName = std::move(other.m_lastName);
    m_phoneNumber = other.m_phoneNumber;
    return *this;
}

void cc::Customer::DisplayInformation() const
{
    // TODO
}

std::string cc::Customer::GetFirstName() const
{
    return m_firstName;
}

std::string cc::Customer::GetLastName() const
{
    return m_lastName;
}

std::string cc::Customer::GetPhoneNumberAsString() const
{
    std::stringstream phoneNumberStream;
    phoneNumberStream
        << '(' << (m_phoneNumber / 10000000) << ')'
        << (m_phoneNumber / 10000 % 1000)
        << '-' << m_phoneNumber % 1000000;
    return phoneNumberStream.str();
}

uint16_t cc::Customer::GetPhoneNumber() const
{
    return m_phoneNumber;
}

void cc::Customer::SetFirstName(const std::string& firstName)
{
    m_firstName = firstName;
}

void cc::Customer::SetLastName(const std::string& lastName)
{
    m_lastName = lastName;
}

void cc::Customer::SetPhoneNumber(const uint16_t phoneNumber)
{
    if (phoneNumber < 1 || phoneNumber > 999'999'9999)
        throw std::invalid_argument("Invalid Phone Number");
    m_phoneNumber = phoneNumber;
}
