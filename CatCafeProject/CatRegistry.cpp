#include "CatRegistry.h"

#include <iostream>
#include <type_traits>

cc::CatRegistry::CatRegistry() {}

cc::CatRegistry::~CatRegistry() {}

cc::CatRegistry::CatRegistry(const CatRegistry& other)
    : m_cats(other.m_cats)
{}

cc::CatRegistry::CatRegistry(CatRegistry&& other) noexcept
    : m_cats(std::move(other.m_cats))
{}

void cc::CatRegistry::DisplayAllCats() const
{
    if (!m_cats.size())
    {
        std::cout << "----------------------------------\n"
            << "The are no cats in this registry.\n"
            "----------------------------------\n" << std::endl;
        return;
    }
    std::cout << "----------------------------------\n";
    for (Cat cat : m_cats)
    {
        cat.DisplayInformation();
        std::cout << "----------------------------------\n";
    }
    std::cout << std::flush;
}

void cc::CatRegistry::PromptCreate()
{
    m_cats.push_back(
        cc::CatBuilder()
        .PromptPopulate()
        .CopyBuild()
    );
}

void cc::CatRegistry::Add(const Cat& cat)
{
    m_cats.push_back(cat);
}

void cc::CatRegistry::Add(Cat&& cat) noexcept
{
    m_cats.push_back(std::move(cat));
}

void cc::CatRegistry::Remove(const size_t index)
{
    m_cats.erase(m_cats.begin() + index);
}

cc::CatRegistry& cc::CatRegistry::operator=(const CatRegistry& other)
{
    m_cats = other.m_cats;
    return *this;
}

cc::CatRegistry& cc::CatRegistry::operator=(CatRegistry&& other) noexcept
{
    m_cats = std::move(other.m_cats);
    return *this;
}

cc::Cat& cc::CatRegistry::operator[](const size_t index)
{
    return m_cats[index];
}

const cc::Cat& cc::CatRegistry::operator[](const size_t index) const
{
    return m_cats[index];
}
