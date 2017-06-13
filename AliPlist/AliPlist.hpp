/*
 *  AliPlist.hpp
 *  AliPlist
 *
 *  Created by jingsong.jn on 2017/6/12.
 *  Copyright © 2017年 jingsong.jn. All rights reserved.
 *
 */

#ifndef AliPlist_
#define AliPlist_

#include <string>

/* The classes below are exported */
#pragma GCC visibility push(default)

namespace AliPlist
{
    class PlistStore;
    
    class PlistParser
    {
    private:
        PlistStore *store;
    public:
        void readFile(std::string file);
        std::string getStringValue(std::string key);
    };
}

#pragma GCC visibility pop
#endif
