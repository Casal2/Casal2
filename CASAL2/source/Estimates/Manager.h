/**
 * @file Manager.h
 * @author  Scott Rasmussen (scott.rasmussen@zaita.com)
 * @date 17/09/2014
 * @section LICENSE
 *
 * Copyright Casal2 Project 2024 - https://github.com/Casal2/
 *
 * @section DESCRIPTION
 *
 * This class is the manager responsible for holding all of the estimates in the system
 * and providing access to the other systems like ObjectiveFunction, Reports etc.
 */
#ifndef ESTIMATE_MANAGER_H_
#define ESTIMATE_MANAGER_H_

// headers
#include "../BaseClasses/Manager.h"
#include "../Estimates/Creators/Creator.h"
#include "../Estimates/Estimate.h"
#include "../Utilities/Map.h"

// namespaces
namespace niwa {
class Managers;
class Model;

namespace estimates {

/**
 * Class definition
 */
class Manager : public niwa::base::Manager<estimates::Manager, niwa::Estimate> {
  friend class niwa::base::Manager<estimates::Manager, niwa::Estimate>;
  friend class niwa::Managers;

public:
  // methods
  virtual ~Manager();
  void              Validate() override final;
  void              Validate(shared_ptr<Model> model);
  void              Build() override final;
  void              Build(shared_ptr<Model> model);
  unsigned          GetIsEstimatedCount();
  vector<Estimate*> GetIsEstimated();
  vector<Estimate*> GetInObjectiveFunction();
  vector<Estimate*> GetIsMCMCd();
  void              Clear() override final;
  bool              HasEstimate(const string& parameter);
  void              FlagIsEstimated(const string& parameter);
  void              UnFlagIsEstimated(const string& parameter);
  void              FlagIsInObjective(const string& parameter);
  void              UnFlagIsInObjective(const string& parameter);
  void              AddCreator(Creator* creator) { creators_.push_back(creator); }
  Estimate*         GetEstimate(const string& parameter);
  Estimate*         GetEstimateByLabel(const string& label);
  vector<Estimate*> GetEstimatesByLabel(const string& label);
  void              SetActivePhase(unsigned phase);
  void              SetEstimatedValuesToInitialValues();
  unsigned          GetNumberOfPhases();
  vector<Double>    lower_bounds();
  vector<Double>    upper_bounds();

private:
  // methods
  Manager(){};

  // members
  vector<Creator*> creators_;
};

} /* namespace estimates */
} /* namespace niwa */
#endif /* ESTIMATE_MANAGER_H_ */
