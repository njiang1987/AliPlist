//
//  main.m
//  AliPlistTest
//
//  Created by jingsong.jn on 2017/6/12.
//  Copyright © 2017年 jingsong.jn. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "AliPlist.hpp"
#include "Plist.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        AliPlist::PlistParser parser;
        parser.readFile("/Users/jingsong.jn/Work/AliPlist/AliPlistTest/XMLExample1.plist");
        string testString = parser.getStringValue("testString");
        cout<<testString<<endl;
        
        bool testBool = parser.getBoolValue("testBoolTrue");
        cout<<testBool<<endl;
        
        map<string, string> dict = parser.getDictionaryValue("testDict");
        cout<<"1"<<endl;
    }
    return 0;
}
