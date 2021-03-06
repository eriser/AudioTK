/**
 * \file RobertBristowJohnsonFilter.h
 */

#ifndef ATK_EQ_ROBERTBRISTOWJOHNSONFILTER_H
#define ATK_EQ_ROBERTBRISTOWJOHNSONFILTER_H

#include <ATK/EQ/SecondOrderFilter.h>

namespace ATK
{
  template<typename DataType_>
  class RobertBristowJohnsonLowPassCoefficients : public SecondOrderBaseCoefficients<DataType_>
  {
  public:
    typedef SecondOrderBaseCoefficients<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;
  protected:
    using Parent::cut_frequency;
    using Parent::coefficients_in;
    using Parent::coefficients_out;

    DataType Q;

    void setup() override;
        
  public:
    /*!
     * @brief Constructor
     * @param nb_channels is the number of input and output channels
     */
    RobertBristowJohnsonLowPassCoefficients(int nb_channels = 1);

    /// Sets the Q factor, must be strictly positive
    /*!
     * A smaller Q will lead to a stronger attenuation, a bigger Q will lead to a stronger enhancement
     */
    void set_Q(DataType_ Q);
    /// Returns the Q factor
    DataType_ get_Q() const;
  };

  template<typename DataType_>
  class RobertBristowJohnsonHighPassCoefficients : public SecondOrderBaseCoefficients<DataType_>
  {
  public:
    typedef SecondOrderBaseCoefficients<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;
  protected:
    using Parent::cut_frequency;
    using Parent::coefficients_in;
    using Parent::coefficients_out;

    DataType Q;

    void setup() override;

  public:
    /*!
     * @brief Constructor
     * @param nb_channels is the number of input and output channels
     */
    RobertBristowJohnsonHighPassCoefficients(int nb_channels = 1);

    /// Sets the Q factor, must be strictly positive
    /*!
     * A smaller Q will lead to a stronger attenuation, a bigger Q will lead to a stronger enhancement
     */
    void set_Q(DataType_ Q);
    /// Returns the Q factor
    DataType_ get_Q() const;
  };

  template<typename DataType_>
  class RobertBristowJohnsonBandPassCoefficients : public SecondOrderBaseCoefficients<DataType_>
  {
  public:
    typedef SecondOrderBaseCoefficients<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;
  protected:
    using Parent::cut_frequency;
    using Parent::coefficients_in;
    using Parent::coefficients_out;

    DataType Q;

    void setup() override;

  public:
    /*!
     * @brief Constructor
     * @param nb_channels is the number of input and output channels
     */
    RobertBristowJohnsonBandPassCoefficients(int nb_channels = 1);

    /// Sets the Q factor, must be strictly positive
    /*!
     * A smaller Q will lead to a bigger bandwidth, a bigger Q will lead to a smaller bandwidth
     */
    void set_Q(DataType_ Q);
    /// Returns the Q factor
    DataType_ get_Q() const;
  };

  template<typename DataType_>
  class RobertBristowJohnsonBandPass2Coefficients : public SecondOrderBaseCoefficients<DataType_>
  {
  public:
    typedef SecondOrderBaseCoefficients<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;
  protected:
    using Parent::cut_frequency;
    using Parent::coefficients_in;
    using Parent::coefficients_out;

    DataType Q;

    void setup() override;

  public:
    /*!
     * @brief Constructor
     * @param nb_channels is the number of input and output channels
     */
    RobertBristowJohnsonBandPass2Coefficients(int nb_channels = 1);

    /// Sets the Q factor, must be strictly positive
    /*!
     * A smaller Q will lead to a bigger bandwidth, a bigger Q will lead to a smaller bandwidth
     */
    void set_Q(DataType_ Q);
    /// Returns the Q factor
    DataType_ get_Q() const;
  };

  template<typename DataType_>
  class RobertBristowJohnsonBandStopCoefficients : public SecondOrderBaseCoefficients<DataType_>
  {
  public:
    typedef SecondOrderBaseCoefficients<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;
  protected:
    using Parent::cut_frequency;
    using Parent::coefficients_in;
    using Parent::coefficients_out;

    DataType Q;

    void setup() override;

  public:
    /*!
     * @brief Constructor
     * @param nb_channels is the number of input and output channels
     */
    RobertBristowJohnsonBandStopCoefficients(int nb_channels = 1);

    /// Sets the Q factor, must be strictly positive
    /*!
     * A smaller Q will lead to a bigger bandwidth, a bigger Q will lead to a smaller bandwidth
     */
    void set_Q(DataType_ Q);
    /// Returns the Q factor
    DataType_ get_Q() const;
  };

  template<typename DataType_>
  class RobertBristowJohnsonAllPassCoefficients : public SecondOrderBaseCoefficients<DataType_>
  {
  public:
    typedef SecondOrderBaseCoefficients<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;
  protected:
    using Parent::cut_frequency;
    using Parent::coefficients_in;
    using Parent::coefficients_out;

    DataType Q;

    void setup() override;

  public:
    /*!
     * @brief Constructor
     * @param nb_channels is the number of input and output channels
     */
    RobertBristowJohnsonAllPassCoefficients(int nb_channels = 1);

    /// Sets the Q factor, must be strictly positive
    /*!
     * A smaller Q will lead to a spread response, a bigger Q will lead to a smaller response
     */
    void set_Q(DataType_ Q);
    /// Returns the Q factor
    DataType_ get_Q() const;
  };

  template<typename DataType_>
  class RobertBristowJohnsonBandPassPeakCoefficients : public SecondOrderBaseCoefficients<DataType_>
  {
  public:
    typedef SecondOrderBaseCoefficients<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;
  protected:
    using Parent::cut_frequency;
    using Parent::coefficients_in;
    using Parent::coefficients_out;

    DataType Q;
    DataType gain;

    void setup() override;

  public:
    /*!
     * @brief Constructor
     * @param nb_channels is the number of input and output channels
     */
    RobertBristowJohnsonBandPassPeakCoefficients(int nb_channels = 1);

    /// Sets the Q factor, must be strictly positive
    /*!
     * A smaller Q will lead to a spread response, a bigger Q will lead to a smaller response
     */
    void set_Q(DataType_ Q);
    /// Returns the Q factor
    DataType_ get_Q() const;
    /// Sets the gain of the peak
    void set_gain(DataType_ gain);
    /// Returns the gain for the peak
    DataType_ get_gain() const;
  };

  template<typename DataType_>
  class RobertBristowJohnsonLowShelvingCoefficients : public SecondOrderBaseCoefficients<DataType_>
  {
  public:
    typedef SecondOrderBaseCoefficients<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;
  protected:
    using Parent::cut_frequency;
    using Parent::coefficients_in;
    using Parent::coefficients_out;

    DataType Q;
    DataType gain;

    void setup() override;

  public:
    /*!
     * @brief Constructor
     * @param nb_channels is the number of input and output channels
     */
    RobertBristowJohnsonLowShelvingCoefficients(int nb_channels = 1);

    /// Sets the Q factor, must be strictly positive
    /*!
     * A smaller Q will lead to a spread response, a bigger Q will lead to a smaller response
     */
    void set_Q(DataType_ Q);
    /// Returns the Q factor
    DataType_ get_Q() const;
    /// Sets the gain of the shelf
    void set_gain(DataType_ gain);
    /// Returns the gain for the shelf
    DataType_ get_gain() const;
};

  template<typename DataType_>
  class RobertBristowJohnsonHighShelvingCoefficients : public SecondOrderBaseCoefficients<DataType_>
  {
  public:
    typedef SecondOrderBaseCoefficients<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::input_sampling_rate;
    using Parent::output_sampling_rate;
  protected:
    using Parent::cut_frequency;
    using Parent::coefficients_in;
    using Parent::coefficients_out;

    DataType Q;
    DataType gain;

    void setup() override;

  public:
    /*!
     * @brief Constructor
     * @param nb_channels is the number of input and output channels
     */
    RobertBristowJohnsonHighShelvingCoefficients(int nb_channels = 1);

    /// Sets the Q factor, must be strictly positive
    /*!
     * A smaller Q will lead to a spread response, a bigger Q will lead to a smaller response
     */
    void set_Q(DataType_ Q);
    /// Returns the Q factor
    DataType_ get_Q() const;
    /// Sets the gain of the shelf
    void set_gain(DataType_ gain);
    /// Returns the gain for the shelf
    DataType_ get_gain() const;
  };
}

#endif
