/**
 * \file ButterworthFilter.h
 */

#ifndef ATK_EQ_BUTTERWORTHFILTER_H
#define ATK_EQ_BUTTERWORTHFILTER_H

#include <ATK/Core/TypedBaseFilter.h>

namespace ATK
{
  template<typename DataType_>
  class ButterworthLowPassCoefficients: public TypedBaseFilter<DataType_>
  {
  public:
    typedef TypedBaseFilter<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::setup;
  protected:
    DataType cut_frequency;
    
    const static int in_order=2;
    const static int out_order=2;
    
    void setup();
    
    DataType coefficients_in[3];
    DataType coefficients_out[2];
    
  public:
    ButterworthLowPassCoefficients();
    
    void set_cut_frequency(DataType cut_frequency);
    DataType get_cut_frequency() const;
  };
}

#endif
