/**
 * \file OutPointerFilter.h
 */

#ifndef ATK_CORE_OUTPOINTERFILTER_H
#define ATK_CORE_OUTPOINTERFILTER_H

#include "TypedBaseFilter.h"

namespace ATK
{
  /// Filter allowing to output data in an array
  template<typename DataType_>
  class ATK_CORE_EXPORT OutPointerFilter : public TypedBaseFilter<DataType_>
  {
  public:
    /// Simplify parent calls
    typedef TypedBaseFilter<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::converted_inputs_size;
    using Parent::converted_inputs;
    using Parent::input_sampling_rate;
    using Parent::set_input_sampling_rate;
    
  public:
    /**
     * @brief Create a filter for the end of a pipeline
     * @param array is the pointer to the data that will be reused during all the processing
     * @param size in the size of the data for one channel
     * @param channels is the number of total channels
     * @param interleaved indicates if the data is interleaved (Wav/Fortran order) or not (C order). If interleaved, size and channels switch position.
     */
    OutPointerFilter(DataType* array, int channels, int64_t size, bool interleaved);
    /// Destructor
    virtual ~OutPointerFilter();
    
    /**
     * @brief Resets the pointer and the internal offset
     * @param array is the pointer to the new array
     * @param size is the allocated size of the array
     */
    void set_pointer(DataType* array, int64_t size);

  protected:
    /// This implementation retrieves inputs from other filters and converts it accordingly
    virtual void process_impl(int64_t size) const override final;
    /// Current offset in the array
    mutable int64_t offset;
    /// Output array
    DataType* array;
    /// Size of the output array
    int64_t mysize;
    /// Number of channels/ports in the array
    int channels;
    /// Is the output array interleaved?
    bool interleaved;
  };
}

#endif
