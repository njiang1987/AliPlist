/*
 *  AliPlist.cpp
 *  AliPlist
 *
 *  Created by jingsong.jn on 2017/6/12.
 *  Copyright © 2017年 jingsong.jn. All rights reserved.
 *
 */

#include <iostream>
#include <map>
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
