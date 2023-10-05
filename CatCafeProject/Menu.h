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
	private:
		friend class MenuOption;
	private:
		std::vector<std::unique_ptr<MenuOption>> m_menuOptions;
		CatRegistry m_catRegistry;
	};

	class MenuOption
	{
	public:
		virtual void Activate(Menu&) const = 0;
	protected:
		CatRegistry& GetCatRegistry(Menu&) const;
	};

	class AddCatMenuOption : public MenuOption
	{
	public:
		void Activate(Menu&) const;
	};

	class RemoveCatMenuOption : public MenuOption
	{
	public:
		void Activate(Menu&) const;
	};

	class DisplayCatsMenuOption : public MenuOption
	{
	public:
		void Activate(Menu&) const;
	};
}

#endif
