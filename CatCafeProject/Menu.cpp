#include "Menu.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

namespace cc
{
    class MenuOption
    {
    public:
        MenuOption(const std::string& stringRepresentation)
            : m_stringRepresentation(stringRepresentation) {}
        virtual void Activate(cc::Menu&) const = 0;
        const std::string& GetStringRepresentation() const;
    protected:
        cc::CatRegistry& GetCatRegistry(cc::Menu&) const;
    private:
        std::string m_stringRepresentation;
    };

    class AddCatMenuOption : public MenuOption
    {
    public:
        AddCatMenuOption() : MenuOption("Add Cat") {}
        void Activate(cc::Menu& callingMenu) const
        {
            GetCatRegistry(callingMenu).PromptCreate();
        }
    };

    class RemoveCatMenuOption : public MenuOption
    {
    public:
        RemoveCatMenuOption() : MenuOption("Remove Cat") {}
        void Activate(cc::Menu& callingMenu) const
        {
            // TODO
        }
    };

    class DisplayCatsMenuOption : public MenuOption
    {
    public:
        DisplayCatsMenuOption() : MenuOption("Display Cats") {}
        void Activate(cc::Menu& callingMenu) const
        {
            GetCatRegistry(callingMenu).DisplayAllCats();
        }
    };

    class ExitMenuOption : public MenuOption
    {
    public:
        ExitMenuOption() : MenuOption("Exit") {}
        void Activate(cc::Menu& callingMenu) const
        {
            callingMenu.Stop();
        }
    };
}

void cc::Menu::Run()
{
    while (m_shouldContinue)
    {
        PrintMenu();

    }
}

void cc::Menu::PrintMenu() const
{
    std::cout << "Main Menu:\n\n----------------------------------\n" << std::endl;
    for (int i = 0; i < m_menuOptions.size(); i++)
    {
        std::stringstream indexMarker;
        indexMarker << i + 1 << '.';
        std::cout << std::setw(6) << std::left
            << indexMarker.str()
            << std::setw(28) << std::right
            << m_menuOptions[i]->GetStringRepresentation()
            << "\n";
    }
    std::cout << "\n----------------------------------\n" << std::endl;
}

void cc::Menu::Stop()
{
    m_shouldContinue = false;
}

cc::CatRegistry& cc::MenuOption::GetCatRegistry(cc::Menu& callingMenu) const
{
    return callingMenu.m_catRegistry;
}

const std::string& cc::MenuOption::GetStringRepresentation() const
{
    return m_stringRepresentation;
}

cc::Menu::Menu()
    : m_shouldContinue(true)
{
    m_menuOptions.emplace_back(std::make_unique<AddCatMenuOption>());
    m_menuOptions.emplace_back(std::make_unique<RemoveCatMenuOption>());
    m_menuOptions.emplace_back(std::make_unique<DisplayCatsMenuOption>());
    m_menuOptions.emplace_back(std::make_unique<ExitMenuOption>());
}
