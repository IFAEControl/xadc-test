#include <iostream>
#include <unistd.h>

#include "xadc_core.h"

int main() {
    xadc_core x(true);

     std::cout << x.get_value(xadc_param::temp) << std::endl;
     std::cout << x.touch(xadc_param::temp) << std::endl;
    x.set_threshold(xadc_alarm::temp, 70, 64);
}
