//
// Created by sergiy on 09.11.2019.
//

#ifndef CPPPROJECT_WORKERCONTROLLER_H
#define CPPPROJECT_WORKERCONTROLLER_H

#include "DataQueue.h"
#include "UrlsQueue.h"
#include "Worker.h"
#include <vector>
#include "string"
class WorkerController {
private:
    std::vector<Worker> workerList;
    DataQueue* dataQueue;
    UrlsQueue* urlsQueue;

    std::string sendTask(const Worker* worker, const std::string& url);
    void createWorker();
    void removeWorker();
    std::string getUrl();

public:
    WorkerController();

    void workerIsReady();
};


#endif //CPPPROJECT_WORKERCONTROLLER_H
