#include <exception>
#include <iostream>
#include "App.h"
int main(int argc, char* argv[])
{
    try {
        App app(argc, argv);
        return app.run();
    }
    catch (std::exception e) {
        std::cout << e.what();
        return -1;
    }
}
