/*
 Copyright (C) 2012-2014 Soomla Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#ifndef __CCDomainFactory_H_
#define __CCDomainFactory_H_

#include "cocos2d.h"
#include "CCDomain.h"

namespace soomla {
    class CCDomainFactory {
    public:
        static CCDomainFactory* getInstance();
        void registerCreator(const char* key, std::function<soomla::CCDomain *(cocos2d::__Dictionary *)> creator);
        soomla::CCDomain *createWithDictionary(cocos2d::__Dictionary *dict);
        soomla::CCDomain *createWithDictionaryAndType(cocos2d::__Dictionary *dict, const char *type);
    private:
        std::map<std::string, std::function<soomla::CCDomain *(cocos2d::__Dictionary *)>> mCreators;
    };
}


#endif //__CCDomainFactory_H_
