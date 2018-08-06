#include "Textures.h"

bool loadTextures(map<string, Texture> * textures, vector<pair<string, string>> * files)
{
    Texture t;
    bool ret = true;
    for (unsigned   int i=0; i<files->size(); i++)
    {
        pair<string, string> cur = files->at(i);
        if (!t.loadFromFile(cur.first))
        {
            cout<<"Couldn't load the following file: "<<cur.first<<endl;
            ret = false;
        }
        else
        {
            textures->emplace(cur.second, t);
        }
    }
    return ret;
}
