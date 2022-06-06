//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "Material.h"

/**
 * Diffusion coefficient in Laplace Young
 */
class LaplaceYoungDiffusionCoef : public Material
{
public:
  LaplaceYoungDiffusionCoef(const InputParameters & parameters);

  static InputParameters validParams();

protected:
  virtual void computeQpProperties() override;

  /// The diffusion coefficient
  ADMaterialProperty<Real> & _k;

  /// Gradient of the variable dependency
  const ADVariableGradient & _grad_u;
};
