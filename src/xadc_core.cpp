#include <cstdio>
#include <stdexcept>

#include "xadc_core_if.h"

#include "xadc_core.h"

xadc_core::xadc_core(bool f, bool dummy) : _full(f), _dummy(dummy) {
    if(_dummy) return;

    auto mode = _full ? EXADC_INIT_FULL : EXADC_INIT_READ_ONLY;
    if(xadc_core_init(mode))
        throw std::runtime_error("Could not initalize xadc_core");
}

xadc_core::~xadc_core() {
    if(_dummy) return;

    xadc_core_deinit();
}

float xadc_core::touch(const xadc_param p) const {
    if(_dummy) return 0;

    return xadc_touch(static_cast<XADC_Param>(p));
}

float xadc_core::get_value(const xadc_param p) const {
    if(_dummy) return 0;

    xadc_update_stat();
    return xadc_get_value(static_cast<XADC_Param>(p));
}

bool xadc_core::get_alarm_status(const xadc_alarm a) const {
    if(_dummy) return false;
    
    return xadc_get_alarm_status(static_cast<XADC_Alarm>(a));
}

void xadc_core::set_threshold(const xadc_alarm a, float threshold_low,
                              float threshold_high, struct Xadc_callback* callback) {
    if(_dummy) return;
    
    if(xadc_set_threshold(static_cast<XADC_Alarm>(a), threshold_low, threshold_high, callback))
        throw std::runtime_error("Could not set threshold");
}