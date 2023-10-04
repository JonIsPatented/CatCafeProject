#include <iostream>

#include "Cat.h"

int main()
{
    cc::Cat cat; 
    cc::CatBuilder()
        .Name("Floof")
        .Color("Orange")
        .Pattern("Tabby")
        .ID(19564)
        .Sex("Male")
        .BirthDate(12, 3, 2014)
        .ExtractBuild(cat);

    cat.DisplayInformation();
}
