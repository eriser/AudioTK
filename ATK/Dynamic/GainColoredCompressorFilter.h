/**
 * \file GainColoredCompressorFilter.h
 */

#ifndef ATK_DYNAMIC_GAINCOLOREDCOMPRESSORFILTER_H
#define ATK_DYNAMIC_GAINCOLOREDCOMPRESSORFILTER_H

#include <vector>

#include <ATK/Dynamic/GainFilter.h>
#include "config.h"

namespace ATK
{
  /// Colored gain "compressor". Computes a new amplitude/volume gain based on threshold, slope and the power of the input signal
  template<typename DataType_>
  class ATK_DYNAMIC_EXPORT GainColoredCompressorFilter : public ParentGainFilter<DataType_>
  {
  protected:
    /// Simplify parent calls
    typedef ParentGainFilter<DataType_> Parent;
    using Parent::ratio;
    using Parent::start_recomputeLUT;

  public:
    using typename Parent::DataType;
    /*!
    * @brief Constructor
    * @param nb_channels is the number of input and output channels
    * @param LUTsize is the total LUT size used by the filter
    * @param LUTprecision is the number of elements used to compute values < 1
    */
    GainColoredCompressorFilter(int nb_channels = 1, size_t LUTsize = 128*1024, size_t LUTprecision = 64);
    /// Destructor
    ~GainColoredCompressorFilter();

    /// Sets the softness of the knee of the filter (positive value)
    void set_softness(DataType_ softness);
    /// Retrieves the softness afctor
    DataType_ get_softness() const;

    /// Sets the color of the filter, the behavior around the threshold
    /*!
    * A positive value increases the gain, a negative value lowers it
    */
    void set_color(DataType_ color);
    /// Returns the color factor
    DataType_ get_color() const;
    /// Sets the quality, the extent around the threshold where the color factor has an effect
    void set_quality(DataType_ quality);
    /// Returns the quality factor
    DataType_ get_quality() const;

    DataType_ computeGain(DataType_ value) const;
  private:
    DataType_ softness;
    DataType_ color;
    DataType_ quality;
  };
}

#endif
