//
// Created by sergiy on 09.11.2019.
//

#ifndef CPPPROJECT_HTTPMANAGER_H
#define CPPPROJECT_HTTPMANAGER_H

#include <string>

class HttpManager {
public:
    HttpManager();

public:
    std::string getHttpResponse(const std::string& url);
};


#endif //CPPPROJECT_HTTPMANAGER_H
