project(
  'shorelark',
  'cpp',
  version : '0.1.0',
  meson_version : '>= 1.3.0',
  default_options : ['warning_level=3', 'cpp_std=c++17'],
)

neural-network_dep = dependency('neural-network', fallback : ['neural-network', 'neural-network_dep'])

dependencies = [
  neural=network_dep
]

sources = [
  'main.cpp',
]

exe = executable(
  'shorelark',
  sources,
  install : true,
  dependencies : dependencies,
)

test('basic', exe)
