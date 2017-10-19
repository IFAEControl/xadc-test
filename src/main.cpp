#include <iostream>

#include "xadc_core.h"

int main() {
    xadc_core x;

    std::cout << x.get_value(xadc_param::temp) << std::endl;
    std::cout << x.touch(xadc_param::temp) << std::endl;
}
