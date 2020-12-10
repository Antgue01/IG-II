#version 330 core
in vec4 vertex; 
in vec2 uv0; 
uniform mat4 modelViewProjMat; 
void main() {
vUv0 = uv0; 
gl_Position = modelViewProjMat * vertex; 
}