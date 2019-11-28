#include <iostream>
#include <Quartz/Utilities/ContentLoader.hpp>

int main(){
    try
    {
        qz::utils::loadLua("save1");
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}