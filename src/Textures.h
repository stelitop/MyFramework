#ifndef TEXTURES_H
#define TEXTURES_H

#include<iostream>
#include<map>
#include<SFML/Graphics.hpp>
#include<map>
#include<vector>

using namespace std;
using namespace sf;

///@brief Load the textures that will be used, by giving a vector of pairs that contains the path in the first argument and the name it will ba called in the program in the second argument
bool loadTextures(map<string, Texture> * textures, vector<pair<string, string>> * files);

#endif // TEXTURES_H
