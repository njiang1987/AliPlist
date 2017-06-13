/*
 *  AliPlist.cpp
 *  AliPlist
 *
 *  Created by jingsong.jn on 2017/6/12.
 *  Copyright © 2017年 jingsong.jn. All rights reserved.
 *
 */

#include <iostream>
#include "AliPlist.hpp"
#include "Plist.hpp"

using namespace std;
using namespace AliPlist;

namespace AliPlist
{
    class PlistStore
    {
    public:
        map<string, boost::any> dict;
    };
};

void PlistParser::readFile(string file)
{
    store = new PlistStore();
    map<string, boost::any>& dict = store->dict;
    Plist::readPlist(file.c_str(), dict);
}

string PlistParser::getStringValue(string key)
{
    string testString = boost::any_cast<const string&>(store->dict.find(key)->second).c_str();
    return testString;
}

bool PlistParser::getBoolValue(std::string key)
{
    bool testBool = boost::any_cast<const bool&>(store->dict.find(key)->second);
    return testBool;
}

map<string, string> PlistParser::getDictionaryValue(string key)
{
    const map<string, boost::any>& dict = boost::any_cast<const map<string, boost::any>& >(store->dict.find(key)->second);
    map<string, string> result;
    
    for(auto iter = dict.begin(); iter != dict.end(); iter++)
    {
        string tkey = iter->first;
        string tValue = boost::any_cast<const string&>(iter->second).c_str();
        result[tkey] = tValue;
    }
    
    return result;
    
}
