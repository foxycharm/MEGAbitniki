//
// Created by sergiy on 09.11.2019.
//

#ifndef CPPPROJECT_HTTPPARSER_H
#define CPPPROJECT_HTTPPARSER_H

#include "PageData.h"

class HttpParser {
private:
    PageData pageData;
public:
    HttpParser();

    PageData parse(const std::string& http_response);
};


#endif //CPPPROJECT_HTTPPARSER_H

