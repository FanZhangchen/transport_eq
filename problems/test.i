[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 20
  ny = 20
  xmin = 0.0
  xmax = 10.0
  ymin = 0.0
  ymax = 10.0
[]

[Variables]
  [u]
  []
[]

[Kernels]
  [Diffusion]
    type = ExampleDiffusion
    variable = u
  []
  [Convection]
    type = ExampleConvection
    variable = u
  []
[]

[Materials]
  [mat]
    type = ExampleMaterial
  []
[]

[BCs]
  [left]
    type = DirichletBC
    variable = u
    boundary = left
    value = 0.0
  []
  [right]
    type = DirichletBC
    variable = u
    boundary = right
    value = 1.0
  []
[]

# Transient (time-dependent) details for simulations go here:
[Executioner]
  type = Steady
  solve_type = Newton
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[VectorPostprocessors]
  [rho]
    type = LineValueSampler
    variable = u
    start_point = '0 5 0'
    end_point = '10 5 0'
    num_points = 41
    sort_by = x
  []
[]

[Outputs]
  exodus = true
  [csv]
    type = CSV
    file_base = x_out_Peclet_1e-1
    execute_on = final
  []
[]
