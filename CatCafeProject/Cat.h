#ifndef JC_CAT_H
#define JC_CAT_H

#include <string>
#include <ostream>
#include <vector>

#include "DateDMY.h"

namespace cc
{
    class Cat
    {
    public:
        void DisplayInformation() const;
        friend std::ostream& operator<<(std::ostream&, const Cat&);
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
        friend class CatRegistry;
    };

    class CatBuilder
    {
    public:
        CatBuilder& Name(const std::string&);
        CatBuilder& Color(const std::string&);
        CatBuilder& Pattern(const std::string&);
        CatBuilder& ID(const uint32_t);
        CatBuilder& Sex(const std::string&);
        CatBuilder& BirthDate(const uint8_t, const uint8_t, const uint16_t);
        CatBuilder& BirthDate(const DateDMY&);
    public:
        CatBuilder& PromptPopulate();
    public:
        Cat CopyBuild();
        void ExtractBuild(Cat&);
    private:
        Cat m_cat;
    private:
        static std::map<std::string, Cat::Sex> m_sexes;
    };
}

#endif
