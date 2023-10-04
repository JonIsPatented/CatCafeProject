#ifndef JC_CAT_H
#define JC_CAT_H

#include <string>
#include <ostream>

#include "DateDMY.h"

namespace cc
{
    class Cat
    {
    public:
        void DisplayInformation();
        friend std::ostream& operator<<(std::ostream&, Cat&);
    public:
        Cat();
        Cat(const Cat&);
        Cat(Cat&&) noexcept;
        ~Cat();
        Cat& operator=(const Cat&);
        Cat& operator=(Cat&&) noexcept;
    private:
        std::string m_name;
        std::string m_color;
        std::string m_pattern;
        uint32_t m_id;
        DateDMY m_birthDate;
        enum class Sex
        {
            MALE,
            FEMALE
        } m_sex;
    public:
        friend class CatBuilder;
    };

    class CatBuilder
    {
    public:
        CatBuilder& Name(const std::string&);
        CatBuilder& Color(const std::string&);
        CatBuilder& Pattern(const std::string&);
        CatBuilder& ID(const uint64_t);
        CatBuilder& Sex(const std::string&);
        CatBuilder& BirthDate(const uint8_t, const uint8_t, const uint16_t);
        CatBuilder& BirthDate(const DateDMY&);
    public:
        Cat CopyBuild();
        void ExtractBuild(Cat&);
    private:
        Cat m_cat;
    };
}

#endif
