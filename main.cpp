#include <iostream>
#include "base/log/Logger.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    logError<< "main failed" <<errno;
    logInfo<< "main info";
    logDebug<<"main debug";
    logTrace <<"logTrace";
    logWarn<<"logWarn";
    return 0;
}
