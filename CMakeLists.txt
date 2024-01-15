cmake_minimum_required(VERSION 3.27)
project(High)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SCRIPTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cmake/scripts)

include_directories(vendor/glad/include)
include_directories(vendor/GLFW/include)
include_directories(vendor/glm)

# Add the GLFW directory
add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/glm)

# Add glad
add_library(glad vendor/glad/src/glad.c)

# Define Shader files
set(SHADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/High/Shaders)
set(SHADER_FILES
    ${SHADER_DIR}/Scene.vert
    ${SHADER_DIR}/Scene.frag
)

# Transform the shader files into header files
foreach(SHADER_FILE ${SHADER_FILES})
    message(STATUS "Shader file: ${SHADER_FILE}")
    # Get the file name component
    get_filename_component(FILE_NAME ${SHADER_FILE} NAME)
    set(HEADER_FILE ${SHADER_DIR}/Generated/${FILE_NAME}.h)

    message(STATUS "Header file: ${HEADER_FILE}")

    # Get the file name without extension
    string(REPLACE ".frag" "" FILE_NAME ${FILE_NAME})
    string(REPLACE ".vert" "" FILE_NAME ${FILE_NAME})

    # Create the header file
    add_custom_command(
        OUTPUT ${HEADER_FILE}
        COMMAND python ${CMAKE_SCRIPTS_DIR}/glsl_to_header.py ${SHADER_FILE} ${HEADER_FILE}
        DEPENDS ${SHADER_FILE}
        COMMENT "Converting ${SHADER_FILE} to ${HEADER_FILE}"
    )
    list(APPEND HEADER_FILES ${HEADER_FILE})
endforeach()

add_executable(High src/main.cpp
        src/High/Core/Window.cpp
        src/High/Core/Window.h
        src/High/Events/Event.h
        src/High/Events/WindowEvent.h
        src/High/Core/Base.h ${HEADER_FILES}
        src/High/OpenGL/VertexBuffer.cpp
        src/High/OpenGL/VertexBuffer.h
        src/High/OpenGL/VertexArray.cpp
        src/High/OpenGL/VertexArray.h
        src/High/OpenGL/Shader.cpp
        src/High/OpenGL/Shader.h
        src/High/OpenGL/ShaderProgram.cpp
        src/High/OpenGL/ShaderProgram.h
        src/High/OpenGL/Context.cpp
        src/High/OpenGL/Context.h
        src/High/Core/Application.cpp
        src/High/Core/Application.h
        src/High/Core/Assertions.h
        src/High/OpenGL/Renderer2D.cpp
        src/High/OpenGL/Renderer2D.h
        src/High/OpenGL/Texture.cpp
        src/High/OpenGL/Texture.h)

# Link glad to the executable
target_link_libraries(High glfw glad glm ${OPENGL_gl_LIBRARY})
