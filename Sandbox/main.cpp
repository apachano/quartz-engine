#include <iostream>
#include <Quartz/Utilities/ContentLoader.hpp>

int main(){
    if(qz::utils::loadLua("save1")){
        std::cout << "Mods loaded";
    } else {
        std::cout << "Something failed";
    }
}