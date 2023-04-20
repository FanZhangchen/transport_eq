//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "transportEQTestApp.h"
#include "transportEQApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
transportEQTestApp::validParams()
{
  InputParameters params = transportEQApp::validParams();
  return params;
}

transportEQTestApp::transportEQTestApp(InputParameters parameters) : MooseApp(parameters)
{
  transportEQTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

transportEQTestApp::~transportEQTestApp() {}

void
transportEQTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  transportEQApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"transportEQTestApp"});
    Registry::registerActionsTo(af, {"transportEQTestApp"});
  }
}

void
transportEQTestApp::registerApps()
{
  registerApp(transportEQApp);
  registerApp(transportEQTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
transportEQTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  transportEQTestApp::registerAll(f, af, s);
}
extern "C" void
transportEQTestApp__registerApps()
{
  transportEQTestApp::registerApps();
}
