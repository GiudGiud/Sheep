sigma = 0.2

[Mesh]
  [cmg]
    type = CartesianMeshGenerator
    dim = 2
    dx = 1
    dy = 1
    ix = 20
    iy = 20
  []
[]

[Variables]
  [u]
  []
[]

[Kernels]
  [diffusion]
    type = LaplaceYoungDiffusion
    variable = u
    diffusivity = k
  []
  [source]
    type = LaplaceYoungSource
    kappa = 1
    variable = u
  []
[]

[BCs]
  [all]
    type = ADNeumannBC
    variable = u
    value = ${sigma}
    boundary = 'top bottom left right'
  []
[]

[Materials]
  [diff]
    type = LaplaceYoungDiffusionCoef
    variable = u
  []
[]

[Executioner]
  type = Steady
  solve_type = NEWTON
[]

[Outputs]
  exodus = true
[]
