#include "SheepApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
SheepApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

SheepApp::SheepApp(InputParameters parameters) : MooseApp(parameters)
{
  SheepApp::registerAll(_factory, _action_factory, _syntax);
}

SheepApp::~SheepApp() {}

void
SheepApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"SheepApp"});
  Registry::registerActionsTo(af, {"SheepApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
SheepApp::registerApps()
{
  registerApp(SheepApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
SheepApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SheepApp::registerAll(f, af, s);
}
extern "C" void
SheepApp__registerApps()
{
  SheepApp::registerApps();
}
