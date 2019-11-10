//
// Created by sergiy on 09.11.2019.
//

#ifndef CPPPROJECT_PAGEDATA_H
#define CPPPROJECT_PAGEDATA_H

#include <vector>
#include <string>
struct PageData{
    std::vector<std::string> urls;
    const char *text;
    int httpStatusCode;
};

#endif //CPPPROJECT_PAGEDATA_H
