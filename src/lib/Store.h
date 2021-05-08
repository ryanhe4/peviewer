//
// Created by yangheechan on 2021-05-02.
//

#ifndef PEVIEWER_STORE_H
#define PEVIEWER_STORE_H

#include "template/Singleton.h"

class Store : public Singleton<Store> {
public:
    Store();
    ~Store();
};

#endif//PEVIEWER_STORE_H
