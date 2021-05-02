//
// Created by yangheechan on 2021-04-23.
//

#include "UtilMgr.h"
auto UtilMgr::log(std::string_view msg) const -> void
{
    std::cout << "[ " << getTime() << " ] " << msg << "\n";
}
auto UtilMgr::getTime() const -> std::string
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}
