# libs/neural-network/meson.build
project('neural-network', 'cpp')

# 声明头文件目录，让外部可以使用
inc = include_directories('include')

sources = files(
  'src/network.cpp',
  'src/layer.cpp',
  'src/neuron.cpp',
)

# 编译库，可以是 shared_library 或 static_library
# 这里用 library() 函数更灵活，用户可以在配置时通过 --default-library 选择类型 [citation:1]
neural-network = library('neural-network',
  sources
  include_directories : inc,
  install : true   # 如果需要安装可以开启
)



# 👇 最关键的一步：声明这个子项目对外提供的依赖项
neural-network_dep = declare_dependency(
  include_directories : inc,
  link_with : neural-network
)