/**
 * \ file TimeVaryingSecondOrderFilter.cpp
 */

#include <ATK/Core/InPointerFilter.h>

#include <ATK/EQ/TimeVaryingSecondOrderFilter.h>
#include <ATK/EQ/TimeVaryingIIRFilter.h>

#include <ATK/Mock/FFTCheckerFilter.h>
#include <ATK/Mock/SimpleSinusGeneratorFilter.h>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN
#include <boost/test/unit_test.hpp>

#include <boost/scoped_array.hpp>

#define PROCESSSIZE (1024*64)

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingBandPassCoefficients_1k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(1000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingBandPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_Q(1);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0.31610222820014583));
  frequency_checks.push_back(std::make_pair(10000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingBandPassCoefficients_100_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(100);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingBandPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_Q(1);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(10, 0));
  frequency_checks.push_back(std::make_pair(100, 0.8408964152537104));
  frequency_checks.push_back(std::make_pair(1000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);
  
  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingBandPassCoefficients_2k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(2000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingBandPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_Q(1);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0));
  frequency_checks.push_back(std::make_pair(2000, 0.22326595903140814));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingBandPassPeakCoefficients_1k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(1000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingBandPassPeakCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_Q(1);
  filter.set_gain(2);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);
  
  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 1.0074946766389419));
  frequency_checks.push_back(std::make_pair(10000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingBandPassPeakCoefficients_100_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(100);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingBandPassPeakCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_Q(1);
  filter.set_gain(2);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);
  
  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(10, 0));
  frequency_checks.push_back(std::make_pair(100, 1.4142135623730931));
  frequency_checks.push_back(std::make_pair(1000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingBandPassPeakCoefficients_2k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(2000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingBandPassPeakCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_Q(1);
  filter.set_gain(2);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);
  
  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0));
  frequency_checks.push_back(std::make_pair(2000, 1.0018333926095173));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingAllPassCoefficients_1k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(1000);

  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingAllPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_Q(.1);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 1));
  frequency_checks.push_back(std::make_pair(10000, 0));
  checker.set_checks(frequency_checks);

  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);

  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingAllPassCoefficients_100_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(100);

  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingAllPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_Q(.1);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(10, 0));
  frequency_checks.push_back(std::make_pair(100, 1));
  frequency_checks.push_back(std::make_pair(1000, 0));
  checker.set_checks(frequency_checks);

  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);

  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingAllPassCoefficients_2k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(2000);

  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingAllPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_Q(.1);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0));
  frequency_checks.push_back(std::make_pair(2000, 1));
  checker.set_checks(frequency_checks);

  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);

  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingLowPassCoefficients_1k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(1000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingLowPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0.09991943746806305));
  frequency_checks.push_back(std::make_pair(10000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingLowPassCoefficients_100_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(100);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingLowPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(10, 0));
  frequency_checks.push_back(std::make_pair(100, 0.8408964152537146));
  frequency_checks.push_back(std::make_pair(1000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingLowPassCoefficients_2k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(2000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingLowPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0));
  frequency_checks.push_back(std::make_pair(2000, 0.04984673793807906));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingLowPassCoefficients_200_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(200);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingLowPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(200, 0.49246840910199763));
  frequency_checks.push_back(std::make_pair(1000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingHighPassCoefficients_1k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(1000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingHighPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 1000;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0.8697981291708585));
  frequency_checks.push_back(std::make_pair(10000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingHighPassCoefficients_10k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(10000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingHighPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 1000;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(10000, 1.0344582218093583));
  frequency_checks.push_back(std::make_pair(1000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingHighPassCoefficients_500_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(500);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingHighPassCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 1000;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0));
  frequency_checks.push_back(std::make_pair(500, 0.5091584471108357));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingLowShelvingCoefficients_1k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(1000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingLowShelvingCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_gain(.5);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);
  
  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0.9999157109896207));
  frequency_checks.push_back(std::make_pair(10000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  filter.set_input_port(1, &generator2, 0);

  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingLowShelvingCoefficients_100_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(100);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingLowShelvingCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_gain(.5);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(10, 0));
  frequency_checks.push_back(std::make_pair(100, 0.7951544465306409));
  frequency_checks.push_back(std::make_pair(1000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingLowShelvingCoefficients_200_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(200);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingLowShelvingCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_gain(.5);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 100;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);

  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(200, 0.9599245087100254));
  frequency_checks.push_back(std::make_pair(1000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingHighShelvingCoefficients_1k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(1000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingHighShelvingCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_gain(.5);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 1000;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);
  
  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0.7953107582465426));
  frequency_checks.push_back(std::make_pair(10000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingHighShelvingCoefficients_10k_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(10000);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingHighShelvingCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_gain(.5);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 1000;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);
  
  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(10000, 0.7071168098138222));
  frequency_checks.push_back(std::make_pair(1000, 0));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}

BOOST_AUTO_TEST_CASE( TimeVaryingIIRFilter_TimeVaryingHighShelvingCoefficients_500_test )
{
  ATK::SimpleSinusGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(1024*64);
  generator.set_amplitude(1);
  generator.set_frequency(500);
  
  ATK::TimeVaryingIIRFilter<ATK::TimeVaryingHighShelvingCoefficients<double> > filter;
  filter.set_input_sampling_rate(1024*64);
  filter.set_output_sampling_rate(1024*64);
  filter.set_gain(.5);
  filter.set_min_frequency(100);
  filter.set_max_frequency(12000);
  filter.set_number_of_steps(12000 - 100 + 1);

  boost::scoped_array<float> data(new float[2*PROCESSSIZE]);
  for(ptrdiff_t i = 0; i < 2*PROCESSSIZE; ++i)
  {
    data[i] = 1000;
  }

  ATK::InPointerFilter<float> generator2(data.get(), 1, 2*PROCESSSIZE, false);
  generator2.set_output_sampling_rate(1024*64);
  
  ATK::FFTCheckerFilter<double> checker;
  checker.set_input_sampling_rate(1024*64);
  std::vector<std::pair<int, double> > frequency_checks;
  frequency_checks.push_back(std::make_pair(100, 0));
  frequency_checks.push_back(std::make_pair(1000, 0));
  frequency_checks.push_back(std::make_pair(500, 0.960256352408842));
  checker.set_checks(frequency_checks);
  
  checker.set_input_port(0, &filter, 0);
  filter.set_input_port(0, &generator, 0);
  filter.set_input_port(1, &generator2, 0);

  filter.process(1024*64);
  
  checker.process(PROCESSSIZE);
}
