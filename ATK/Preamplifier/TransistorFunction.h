/**
 * \file TransistorFunction.h
 */

#ifndef ATK_PREAMPLIFIER_TRANSISTORFUNCTION_H
#define ATK_PREAMPLIFIER_TRANSISTORFUNCTION_H

namespace ATK
{
  template <typename DataType_>
  class TransistorFunction
  {
  protected:
    const DataType_ Is;
    const DataType_ Br;
    const DataType_ Bf;
    
  public:
    const DataType_ Vt;

    DataType_ Lb(const std::pair<DataType_, DataType_>& exp)
    {
      return Is * ((exp.first - 1) / Bf + (exp.second - 1) / Br);
    }

    DataType_ Lb_Vbe(const std::pair<DataType_, DataType_>& exp)
    {
      return Is / Vt * (exp.first / Bf + exp.second / Br);
    }

    DataType_ Lb_Vbc(const std::pair<DataType_, DataType_>& exp)
    {
      return -Is / Vt * (exp.second / Br);
    }

    DataType_ Lc(const std::pair<DataType_, DataType_>& exp)
    {
      return Is * ((exp.first - exp.second) - (exp.second - 1) / Br);
    }

    DataType_ Lc_Vbe(const std::pair<DataType_, DataType_>& exp)
    {
      return Is / Vt * ((exp.first - exp.second) - exp.second / Br);
    }

    DataType_ Lc_Vbc(const std::pair<DataType_, DataType_>& exp)
    {
      return Is / Vt * (exp.second + exp.second / Br);
    }

    TransistorFunction(DataType_ Is, DataType_ Vt, DataType_ Br, DataType_ Bf)
      :Is(Is), Br(Br), Bf(Bf), Vt(Vt)
    {
    }

    /// Build a new transistor function for a filter
    static TransistorFunction build_standard_function()
    {
      return TransistorFunction(1e-12, 26e-3, 1, 100);
    }

    /// Build a new transistor function for a filter
    static TransistorFunction build_2n3403()
    {
      return TransistorFunction(1e-12, 26e-3, 1, 300);
    }

  };
}

#endif
