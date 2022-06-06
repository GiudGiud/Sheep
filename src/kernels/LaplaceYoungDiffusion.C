//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "LaplaceYoungDiffusion.h"

registerMooseObject("SheepApp", LaplaceYoungDiffusion);

InputParameters
LaplaceYoungDiffusion::validParams()
{
  auto params = ADKernelGrad::validParams();
  params.addClassDescription("Diffusion for the Laplace Young equation");
  return params;
}

LaplaceYoungDiffusion::LaplaceYoungDiffusion(const InputParameters & parameters) : ADKernelGrad(parameters) {}

ADRealVectorValue
LaplaceYoungDiffusion::precomputeQpResidual()
{
  const ADReal k = 1 / std::sqrt(1 + _grad_u[_qp] * _grad_u[_qp]);
  return k * _grad_u[_qp];
}
