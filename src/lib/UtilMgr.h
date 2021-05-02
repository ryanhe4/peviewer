//
// Created by yangheechan on 2021-04-23.
//

#ifndef PEVIEW_UTILMGR_H
#define PEVIEW_UTILMGR_H

#include "template/Singleton.h"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>

class UtilMgr final : public Singleton<UtilMgr> {
public:
    explicit UtilMgr(token token) { };
    virtual ~UtilMgr() = default;
    auto log(std::string_view msg) const -> void;
    auto getTime() const -> std::string;
};

#endif //PEVIEW_UTILMGR_H
