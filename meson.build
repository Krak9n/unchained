project(
  'unchained',
  'c', 'cpp',
  version : '0.1',
  meson_version : '>= 1.3.0',
  default_options : ['warning_level=3', 'cpp_std=c++23', 'c_std=c99'],
)

freetype = dependency('freetype2')
glfw = dependency('glfw3')

glad_sp = subproject('glad')
glad_dep = glad_sp.get_variable('glad_dep')

dependencies = [
  freetype,
  glfw,
  glad_dep,
]

sources = [
  'src/main.cpp',
  'src/pipeline/shader.cpp',
  'src/pipeline/TextState.cpp',
  'src/pipeline/VideoState.cpp',
  'src/text/text.cpp',
  'src/window/window.cpp',
  'src/ppm/img_s.cpp',
]

exe = executable(
  'unchained',
  sources,
  install : true,
  dependencies : dependencies,
)

test('basic', exe)
