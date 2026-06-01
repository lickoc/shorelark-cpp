project(
  'shorelark',
  'cpp',
  version : '0.1.0',
  meson_version : '>= 1.3.0',
  default_options : ['warning_level=3', 'cpp_std=c++17'],
)

neural_network_dep = dependency('neural-network', fallback : ['neural-network', 'neural_network_dep'])

dependencies = [
  neural_network_dep
]

sources = [
  'src/main.cpp',
]

exe = executable(
  'shorelark',
  sources,
  install : true,
  dependencies : dependencies,
)

# ==================================
# 测试
# ==================================
# 引入 Google Test 
# ==================================
gtest_dep = dependency('gtest', fallback: ['gtest', 'gtest_dep'])

# ==================================
# 测试可执行文件
# ==================================
neural_network_test_exe = executable(
  'neural_network_tests',
  files('tests/test_neural_network.cpp'),
  dependencies: [gtest_dep, neural_network_dep],
)


test('neural-network', neural_network_test_exe)
