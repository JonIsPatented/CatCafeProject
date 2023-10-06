#include "CatRegistry.h"

#include <iostream>
#include <type_traits>
#include <stdexcept>

#include "StringManip.h"

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

void cc::CatRegistry::PromptRemove()
{
    DisplayAllCats();
    std::cout << "Enter the ID of the cat to remove (or 'cancel'): ";

    bool validCat{ false };
    while (!validCat)
    {
        uint32_t inputId{ 0 };
        std::string input;
        getline(std::cin, input);
        
        if (toLowerCase(input) == "cancel")
            return;

        try
        {
            inputId = std::stoi(input);

            size_t foundCatIndex{ 0 };
            for (size_t i = 0; i < m_cats.size(); i++)
                if (m_cats[i].m_id == inputId)
                {
                    foundCatIndex = i;
                    validCat = true;
                    break;
                }

            if (!validCat)
                throw std::exception();

            Remove(foundCatIndex);
        }
        catch (std::invalid_argument&)
        {
            std::cout << "Invalid Input. Enter an ID." << std::endl;
        }
        catch (std::exception&)
        {
            std::cout << "No cat found for the provided ID." << std::endl;
        }
    }

    std::cout << "Cat successfully removed.\n" << std::endl;
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

size_t cc::CatRegistry::Size() const
{
    return m_cats.size();
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
