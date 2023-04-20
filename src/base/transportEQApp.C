#include "transportEQApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
transportEQApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

transportEQApp::transportEQApp(InputParameters parameters) : MooseApp(parameters)
{
  transportEQApp::registerAll(_factory, _action_factory, _syntax);
}

transportEQApp::~transportEQApp() {}

void
transportEQApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"transportEQApp"});
  Registry::registerActionsTo(af, {"transportEQApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
transportEQApp::registerApps()
{
  registerApp(transportEQApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
transportEQApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  transportEQApp::registerAll(f, af, s);
}
extern "C" void
transportEQApp__registerApps()
{
  transportEQApp::registerApps();
}
