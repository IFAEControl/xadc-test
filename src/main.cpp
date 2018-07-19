#include <iostream>
#include <unistd.h>

#include "xadc_core.h"

int main() {
    xadc_core x(false);

    std::cout << "Update Temp: " << x.touch(xadc_param::temp) << std::endl;
    std::cout << "Update VccAux0: " << x.touch(xadc_param::vAux0) << std::endl;
    std::cout << "Update VccAux: " << x.touch(xadc_param::vccAux) << std::endl;
    std::cout << "Update VccBRam: " << x.touch(xadc_param::vccBRam) << std::endl;
    std::cout << "Update VccInt: " << x.touch(xadc_param::vccInt) << std::endl;
    std::cout << "Get Temp: " << x.get_value(xadc_param::temp) << std::endl;
    std::cout << "Get VccAux0: " << x.get_value(xadc_param::vAux0) << std::endl;
    std::cout << "Get VccAux: " << x.get_value(xadc_param::vccAux) << std::endl;
    std::cout << "Get VccBRam: " << x.get_value(xadc_param::vccBRam) << std::endl;
    std::cout << "Get VccInt: " << x.get_value(xadc_param::vccInt) << std::endl;
    //x.set_threshold(xadc_alarm::temp, 62, 64);

}
