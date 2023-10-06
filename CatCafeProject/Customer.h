#ifndef JC_CUSTOMER_H
#define JC_CUSTOMER_H

#include <string>

namespace cc
{
    class Customer
    {
    public:
        void DisplayInformation() const;
    public:
        std::string GetFirstName() const;
        std::string GetLastName() const;
        std::string GetPhoneNumberAsString() const;
        uint16_t GetPhoneNumber() const;
    public:
        void SetFirstName(const std::string&);
        void SetLastName(const std::string&);
        void SetPhoneNumber(const uint16_t);
    public:
        Customer();
        Customer(const std::string&, const std::string&, uint16_t);
        Customer(const Customer&);
        Customer(Customer&&) noexcept;
        ~Customer();
    public:
        Customer& operator=(const Customer&);
        Customer& operator=(Customer&&) noexcept;
    private:
        std::string m_firstName;
        std::string m_lastName;
        uint16_t m_phoneNumber;
    };
}

#endif
