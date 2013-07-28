/**
 * @file Basic.cpp
 * @author  Scott Rasmussen (scott.rasmussen@zaita.com)
 * @date 24/07/2013
 * @section LICENSE
 *
 * Copyright NIWA Science �2013 - www.niwa.co.nz
 *
 */

// headers
#include "Basic.h"

// namespaces
namespace isam {
namespace sizeweights {

/**
 * default constructor
 */
Basic::Basic() {
  parameters_.RegisterAllowed(PARAM_A);
  parameters_.RegisterAllowed(PARAM_B);
}

/**
 * validate the values passed in from the configuration
 * file. Check that neither 'a' or 'b' are greater
 * than 0.0
 */
void Basic::DoValidate() {
  a_ = parameters_.Get(PARAM_A).GetValue<double>();
  b_ = parameters_.Get(PARAM_B).GetValue<double>();

  if (a_ <= 0.0)
    LOG_ERROR(parameters_.location(PARAM_A) << " (" << a_ << ") cannot be less than or equal to 0.0");
  if (b_ <= 0.0)
    LOG_ERROR(parameters_.location(PARAM_B) << " (" << b_ << ") cannot be less than or equal to 0.0");
}

/**
 * Calculate and return the mean weight for the size of fish passed in.
 *
 * @param size The size of the population to calculate mean weight for
 * @return The mean weight of the population at the parameter size
 */
Double Basic::mean_weight(Double size) const {
  return a_ * pow(size, b_) * 1000;
}

} /* namespace sizeweights */
} /* namespace isam */
