#pragma once 


enum class xadc_param : unsigned {
   vccInt,
   vccAux,
   vccBRam,
   temp,
   vAux0,
};

class xadc_core {
public:
   xadc_core();
   ~xadc_core();

   float touch(const xadc_param p) const;
   float get_value(const xadc_param p) const;
};