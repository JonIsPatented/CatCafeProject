#include "Customer.h"

#include <iostream>
#include <string>
#include <type_traits>

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

void cc::Customer::DisplayInformation() const
{
    // TODO
}
