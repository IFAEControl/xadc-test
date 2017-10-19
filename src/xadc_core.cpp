#include <cstdio>
#include <stdexcept>

#include "xadc_core_if.h"

#include "xadc_core.h"

xadc_core::xadc_core() {
    if(xadc_core_init(EXADC_INIT_FULL))
        throw std::runtime_error("Could not initalize xadc_core");
}

xadc_core::~xadc_core() {
    xadc_core_deinit();
}

float xadc_core::touch(const xadc_param p) const {
    return xadc_touch(static_cast<XADC_Param>(p));
}

float xadc_core::get_value(const xadc_param p) const {
    xadc_update_stat();
    return xadc_get_value(static_cast<XADC_Param>(p));
}