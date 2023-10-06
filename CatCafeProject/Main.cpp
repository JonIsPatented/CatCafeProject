#include <iostream>

#include "Cat.h"
#include "CatRegistry.h"
#include "Menu.h"

int main()
{
    //cc::CatRegistry catRegistry;

    //catRegistry.Add(
    //    cc::CatBuilder()
    //    .Name("Floof")
    //    .Color("Orange")
    //    .Pattern("Tabby")
    //    .ID(19564)
    //    .Sex("Male")
    //    .BirthDate(12, 3, 2014)
    //    .CopyBuild()
    //);

    //catRegistry.PromptCreate();

    //catRegistry.DisplayAllCats();

    cc::Menu menu;
    menu.Run();
}
