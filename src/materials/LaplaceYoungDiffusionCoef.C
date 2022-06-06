//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "LaplaceYoungDiffusionCoef.h"

registerMooseObject("SheepApp", LaplaceYoungDiffusionCoef);

InputParameters
LaplaceYoungDiffusionCoef::validParams()
{
  auto params = Material::validParams();
  params.addClassDescription("Diffusion coefficient for the Laplace Young equation");
  params.addRequiredCoupledVar("variable", "Variable to take the gradient of in the expression of the diffusion coefficient");

  return params;
}

LaplaceYoungDiffusionCoef::LaplaceYoungDiffusionCoef(const InputParameters & parameters)
  : Material(parameters),
    _k(declareADProperty<Real>("k")),
    _grad_u(adCoupledGradient("variable"))
{
}

void
LaplaceYoungDiffusionCoef::computeQpProperties()
{
  _k[_qp] = 1 / std::sqrt(1 + _grad_u[_qp] * _grad_u[_qp]);
}
