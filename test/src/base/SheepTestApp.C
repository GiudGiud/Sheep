//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "SheepTestApp.h"
#include "SheepApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
SheepTestApp::validParams()
{
  InputParameters params = SheepApp::validParams();
  return params;
}

SheepTestApp::SheepTestApp(InputParameters parameters) : MooseApp(parameters)
{
  SheepTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

SheepTestApp::~SheepTestApp() {}

void
SheepTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  SheepApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"SheepTestApp"});
    Registry::registerActionsTo(af, {"SheepTestApp"});
  }
}

void
SheepTestApp::registerApps()
{
  registerApp(SheepApp);
  registerApp(SheepTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
SheepTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SheepTestApp::registerAll(f, af, s);
}
extern "C" void
SheepTestApp__registerApps()
{
  SheepTestApp::registerApps();
}
