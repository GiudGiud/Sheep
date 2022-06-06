//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "LaplaceYoungSource.h"

registerMooseObject("SheepApp", LaplaceYoungSource);

InputParameters
LaplaceYoungSource::validParams()
{
  auto params = ADKernelValue::validParams();
  params.addClassDescription("Source/sink for the Laplace Young equation");
  params.addParam<Real>("kappa", 1, "Coefficient for the source term in the LY equation");
  return params;
}

LaplaceYoungSource::LaplaceYoungSource(const InputParameters & parameters) :
  ADKernelValue(parameters),
  _kappa(getParam<Real>("kappa"))
   {}

ADReal
LaplaceYoungSource::precomputeQpResidual()
{
  return _kappa * _u[_qp];
}
