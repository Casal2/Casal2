/**
 * @file Category.h
 * @author Scott Rasmussen (scott.rasmussen@zaita.com)
 * @github https://github.com/Zaita
 * @date 18/02/2015
 * @section LICENSE
 *
 * Copyright NIWA Science �2015 - www.niwa.co.nz
 *
 * @section DESCRIPTION
 *
 * This object represents one category in the model.
 * Because stuff in this is built by the partition there is no need
 * to hide the members behind accessors.
 */
#ifndef PARTITION_CATEGORY_H_
#define PARTITION_CATEGORY_H_

// headers
#include <map>
#include <vector>
#include <string>

#include "Common/Utilities/Types.h"
#include "Common/Selectivities/Selectivity.h"

// namespaces
namespace niwa {
class AgeLength;
class Model;

namespace partition {
using std::string;
using std::map;
using std::vector;
using std::pair;
using niwa::utilities::Double;

/**
 * Class definition
 */
class Category {
public:
  // methods
  Category(Model* model) : model_(model) { };
  virtual                     ~Category() = default;
  void                        UpdateMeanLengthData();
  void                        UpdateMeanWeightData();
  void                        UpdateAgeLengthData(const vector<Double>& length_bins, bool plus_grp, Selectivity* selectivity);
  void                        CollapseAgeLengthData();
  void                        CollapseAgeLengthDataToLength();

  // accessors
  unsigned                    age_spread() const { return (max_age_ - min_age_) + 1; }

  // members
  string                      name_ = "";
  unsigned                    min_age_ = 0;
  unsigned                    max_age_ = 0;
  vector<unsigned>            years_;
  vector<Double>              data_;
  vector<Double>              length_data_;
  vector<vector<Double>>      age_length_matrix_; // age_length_matrix_[age][length]
  //map<unsigned, Double>       mean_length_per_; // map<bin, number per>
  //map<unsigned, Double>       mean_weight_per_; // map<age, weight per>
  map<unsigned, map<unsigned,Double>> mean_length_by_time_step_age_; // map<age, weight per>
  map<unsigned, map<unsigned,Double>> mean_weight_by_time_step_age_; // map<age, weight per>

  AgeLength*                  age_length_ = nullptr;

private:
  // members
  Model*                      model_ = nullptr;
};

} /* namespace partitions */
} /* namespace niwa */

#endif /* PARTITION_CATEGORY_H_ */
