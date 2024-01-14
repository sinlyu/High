import sys
import os


def glsl_to_header(shader_file, header_file):
    shader_filename = os.path.basename(shader_file)
    shader_name = shader_filename.split('.')[0]
    shader_type = shader_filename.split('.')[-1]

    code_shader_source_name = f'{shader_name}{shader_type.capitalize()}ShaderSource'
    code_shader_name = f'{shader_name}{shader_type.capitalize()}Shader'
    code_shader_type = get_shader_type(shader_type)
    code_tab_count = 0

    with open(shader_file, 'r') as f:
        shader = f.read()
    with open(header_file, 'w') as f:
        f.write(write_indent('#pragma once\n', code_tab_count))
        f.write(write_indent('#include "../../OpenGL/Shader.h"\n', code_tab_count))
        f.write(write_indent('namespace High::Shaders\n{', code_tab_count))  # namespace High::Shaders

        code_tab_count += 1

        f.write(write_indent(f'inline OpenGL::Shader* Load{code_shader_name}()', code_tab_count))
        f.write(write_indent('{', code_tab_count))

        code_tab_count += 1

        f.write(write_indent(f'const auto {code_shader_source_name} = R"(', code_tab_count))
        f.write(write_indent(f'{shader}', code_tab_count + 1))
        f.write(write_indent(f')";', code_tab_count))
        f.write(write_indent(
            f'const auto {code_shader_name} = new High::OpenGL::Shader(High::OpenGL::ShaderType::{code_shader_type});',
            code_tab_count))
        f.write(write_indent(f'{code_shader_name}->Load({code_shader_source_name});', code_tab_count))
        f.write(write_indent(f'return {code_shader_name};', code_tab_count))

        code_tab_count -= 1

        f.write(write_indent('}', code_tab_count))

        code_tab_count -= 1

        f.write(write_indent('}\n', code_tab_count))  # namespace High::Shaders


def get_shader_type(shader_type):
    if shader_type == 'vert':
        return 'Vertex'
    if shader_type == 'frag':
        return 'Fragment'


def write_indent(text, tab_count=0):
    code_tab_size = 4
    contents = ''
    indent = ''

    lines = text.split('\n')

    if tab_count > 0:
        indent += ' ' * (code_tab_size * tab_count)

    for line in lines:
        contents += f'{indent}{line}\n'

    return contents


if __name__ == '__main__':
    glsl_to_header(sys.argv[1], sys.argv[2])
