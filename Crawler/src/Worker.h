//
// Created by sergiy on 09.11.2019.
//

#ifndef CPPPROJECT_WORKER_H
#define CPPPROJECT_WORKER_H

#include "HttpManager.h"
#include "HttpParser.h"
#include "PageData.h"
class WorkerController;

class Worker {
private:
    WorkerController* workerController;
    HttpParser parser;
    HttpManager manager;

   void notifyController();
public:
    PageData addTask(const std::string& url);
    Worker();

};


#endif //CPPPROJECT_WORKER_H
