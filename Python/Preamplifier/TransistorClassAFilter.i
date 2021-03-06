
%{
#include <ATK/Preamplifier/TransistorClassAFilter.h>
%}

namespace ATK
{
  template<class DataType>
  class TransistorClassAFilter: public BaseFilter
  {
  public:
    ~TransistorClassAFilter();
  };
}

%template(FloatTransistorClassAFilter) ATK::TransistorClassAFilter<float>;
%template(DoubleTransistorClassAFilter) ATK::TransistorClassAFilter<double>;

PreampExtendSimple(ATK::TransistorClassAFilter, float);
PreampExtendSimple(ATK::TransistorClassAFilter, double);
