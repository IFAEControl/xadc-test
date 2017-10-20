#pragma once

enum class xadc_param : unsigned {
    vccInt,
    vccAux,
    vccBRam,
    temp,
    vAux0,
};

enum class xadc_alarm : unsigned {
    vccInt,
    vccAux,
    vccBRam,
    temp,
};

class xadc_core {
  public:
    explicit xadc_core(bool f = false);
    ~xadc_core();

    float touch(const xadc_param p) const;
    float get_value(const xadc_param p) const;
    bool get_alarm_status(const xadc_alarm a) const;
    void set_threshold(const xadc_alarm a, float threshold_low, float threshold_high,
                       struct Xadc_callback* callback = nullptr);

  private:
    const bool _full;
};