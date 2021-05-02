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
auto UtilMgr::getPalette(const Color _palette) const -> std::map<int, QString>
{
    static std::map<int, QString> ret;
    switch (_palette) {
    case Color::blueGrey : {
        ret[50] = "#eceff1";
        ret[100] = "#cfd8dc";
        ret[200] = "#b0bec5";
        ret[300] = "#90a4ae";
        ret[400] = "#78909c";
        ret[500] = "#607d8b";
        ret[600] = "#546e7a";
        ret[700] = "#455a64";
        ret[800] = "#37474f";
        ret[900] = "#263238";
    }
        break;
    case Color::grey: {
        ret[50] = "#fafafa";
        ret[100] = "#f5f5f5";
        ret[200] = "#eeeeee";
        ret[300] = "#e0e0e0";
        ret[400] = "#bdbdbd";
        ret[500] = "#9e9e9e";
        ret[600] = "#757575";
        ret[700] = "#616161";
        ret[800] = "#424242";
        ret[900] = "#212121";
    }
        break;
    case Color::teal: {
        ret[50] = "#e0f2f1";
        ret[100] = "#b2dfdb";
        ret[200] = "#80cbc4";
        ret[300] = "#4db6ac";
        ret[400] = "#26a69a";
        ret[500] = "#009688";
        ret[600] = "#00897b";
        ret[700] = "#00796b";
        ret[800] = "#00695c";
        ret[900] = "#004d40";
    }
        break;
    default: break;
    }

    return ret;
}
