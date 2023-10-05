#ifndef JC_CC_MENU_H
#define JC_CC_MENU_H

#include <vector>
#include <memory>

#include "CatRegistry.h"

namespace cc
{
    class Menu
    {
    public:
        void Run();
        void Stop();
        void PrintMenu() const;
    public:
        Menu();
        Menu(const Menu&);
        Menu(Menu&&) noexcept;
        ~Menu();
    public:
        Menu& operator=(const Menu&);
        Menu& operator=(Menu&&) noexcept;
    private:
        friend class MenuOption;
    private:
        std::vector<std::unique_ptr<MenuOption>> m_menuOptions;
        CatRegistry m_catRegistry;
        bool m_shouldContinue;
    };
}

#endif
