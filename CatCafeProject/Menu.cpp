#include "Menu.h"

void cc::Menu::Run()
{
	// TODO
}

cc::CatRegistry& cc::MenuOption::GetCatRegistry(Menu& callingMenu) const
{
	return callingMenu.m_catRegistry;
}

void cc::AddCatMenuOption::Activate(Menu& callingMenu) const
{
	GetCatRegistry(callingMenu).PromptCreate();
}

void cc::RemoveCatMenuOption::Activate(Menu& callingMenu) const
{
	// TODO
}

void cc::DisplayCatsMenuOption::Activate(Menu& callingMenu) const
{
	GetCatRegistry(callingMenu).DisplayAllCats();
}
