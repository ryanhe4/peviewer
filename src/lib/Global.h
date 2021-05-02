//
// Created by yangheechan on 2021-05-02.
//

#ifndef PEVIEWER_GLOBAL_H
#define PEVIEWER_GLOBAL_H

#include "template/Singleton.h"

class Global : public Singleton<Global> {
public:
    Global();
    ~Global();
};

#endif //PEVIEWER_GLOBAL_H
