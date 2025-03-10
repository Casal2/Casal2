/**
 * @file Manager.h
 * @author  Scott Rasmussen (scott.rasmussen@zaita.com)
 * @date 28/05/2014
 * @section LICENSE
 *
 * Copyright Casal2 Project 2024 - https://github.com/Casal2/
 *
 * @section DESCRIPTION
 *
 * << Add Description >>
 */
#ifndef PROJECTS_MANAGER_H_
#define PROJECTS_MANAGER_H_

// headers
#include "../BaseClasses/Manager.h"
#include "../Projects/Project.h"

// namespaces
namespace niwa {
class Model;
namespace projects {

/**
 * Class definition
 */
class Manager : public niwa::base::Manager<niwa::projects::Manager, niwa::Project> {
  friend class niwa::base::Manager<niwa::projects::Manager, niwa::Project>;
  friend class niwa::Managers;

public:
  // methods
  virtual ~Manager() noexcept(true);
  void     Build() override final;
  void     Build(shared_ptr<Model> model);
  void     Update(unsigned current_year);
  void     StoreValues(unsigned current_year);
  Project* GetProject(const string& label);
  void     SetObjectsForNextIteration();
protected:
  // methods
  Manager();
};

} /* namespace projects */
} /* namespace niwa */

#endif /* MANAGER_H_ */
