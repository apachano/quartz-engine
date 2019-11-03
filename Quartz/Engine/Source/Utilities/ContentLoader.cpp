// Copyright 2019 Genten Studios
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#include <Quartz/Utilities/ContentLoader.hpp>

using namespace qz::utils;

Mod::Mod(std::string name)
    : m_name(name)
{};

Mod::~Mod(){};

bool Mod::exists(){

}

void loadLua(std::string save){
    std::fstream fileStream;
    std::queue<Mod> loadedMods;  //What dependencies are already satisfied

    //Holding off on making games a functional feature for now

    /*fileStream.open("save/" + save + "/about.txt");

    fileStream.close();*/

    fileStream.open("save/" + save + "/mods.txt");

    //Check if mods exist and load into array for sorting

    std::queue<Mod> toLoad;

    while (fileStream.peek() != ' '){}
        std::string input;
        std::getline(fileStream, input);
        Mod mod = Mod(input);
        if(!mod.exist()){throw "Mod does not exist" + mod.m_name;} //Should never happen if launcher does all the work but lets check anyways
        toLoad.push(mod)
    }

    //Sort and load the mods :/ I am sure I learned a better sort method in college lol

    while(loLoad.size() > 0){
        int lastPass = toLoad.size();
        for (int i = 0, i < toLoad.size(), i++){
            if(mod dependencies are in Satisfied[]){
                add mod to satisfied[]
                sol(mod) //Probably check for an error here and return an exception
            }
        }
        if (lastPass == toLoad.size()){
            throw "One or more mods are missing required dependencies";
        }
    }

    //Launch

    sol::state lua;
    lua.script_file("");
}

}
