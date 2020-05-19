# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
vec2.cpp
mat2.cpp
classes/circle.cpp
classes/rectangle.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  glew.c
  tests.cpp
vec2.cpp
mat2.cpp
classes/circle.cpp
classes/rectangle.cpp
window.cpp #too many linker errors
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )