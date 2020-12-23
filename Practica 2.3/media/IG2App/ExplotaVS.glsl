//Vertex Shader
#version 330 core // archivo ExplotaVS.glsl
in vec4 vertex;
in vec2 uv0;
out vec2 Vuv0;
void main() {
gl_Position = vertex; // El GS tiene que transformar las coordenadas de gl_Position al espacio de corte
Vuv0 = uv0;
}