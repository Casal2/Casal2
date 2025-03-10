/**
 * @file VectorAverage.Test.cpp
 * @author C.Marsh
 * @date 21/6/2017
 * @section LICENSE
 *
 * Copyright Casal2 Project 2024 - https://github.com/Casal2/
 */
#ifdef TESTMODE

// Headers
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <boost/lexical_cast.hpp>

#include "../../Model/Model.h"
#include "../../TestResources/MockClasses/Model.h"
#include "VectorAverage.h"

// Namespaces
namespace niwa {
namespace additionalpriors {

using ::testing::Return;

/*
 * Mock class to make testing easier
 */
class MockVectorAverage : public VectorAverage {
public:
  MockVectorAverage(shared_ptr<Model> model, string method, double k, double multiplier, vector<double>* parameter) : VectorAverage(model) {
    method_             = method;
    k_                  = k;
    multiplier_         = multiplier;
    addressable_vector_ = parameter;
  }
};

/**
 * Test the results of our KnifeEdge are correct
 */
TEST(AdditionalPriors, VectorAverage) {
  // layout is mu, sigma, a, b, expected_score
  vector<double>         example_ycs = {0.478482, 0.640663, 0.640091, 0.762361, 0.560125, 0.651637, 0.764833, 0.645498, 0.678341};
  string                 method      = "k";
  vector<vector<double>> values      = {{1, 100, 12.46850242587778}, {2, 200, 366.18007151842227}};

  shared_ptr<Model> model = shared_ptr<Model>(new Model());
  for (auto line : values) {
    MockVectorAverage vector_average(model, method, line[0], line[1], &example_ycs);
    EXPECT_DOUBLE_EQ(line[2], vector_average.GetScore());
  }
}

} /* namespace additionalpriors */
} /* namespace niwa */

#endif /* ifdef TESTMODE */
