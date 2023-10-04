#ifndef JC_DATE_DMY_H
#define JC_DATE_DMY_H

#include <ostream>
#include <map>

namespace cc
{
    class DateDMY
    {
    public:
        DateDMY();
        DateDMY(uint8_t, uint8_t, uint16_t);
        DateDMY(const DateDMY&);
        DateDMY(DateDMY&&) noexcept;
        ~DateDMY();
    public:
        DateDMY& operator=(const DateDMY&);
        DateDMY& operator=(DateDMY&&) noexcept;
    public:
        friend std::ostream& operator<<(std::ostream&, const DateDMY&);
    private:
        uint8_t m_day;
        uint8_t m_month;
        uint16_t m_year;
    private:
        static std::map<uint8_t, uint8_t> monthMaxDays;
        static std::map<uint8_t, std::string> monthNames;
    };
}

#endif
