#version 330 core
in vec4 vertex; 
in vec3 normal;
in vec2 uv0; 
uniform mat4 modelViewProjMat; 
out vec2 vUv0;
out vec3 vXxxNormal; 
out vec4 vXxxVertex; 

void main() {

vUv0 = uv0; 

vXxxNormal = normal;
vXxxVertex = vertex;

gl_Position = modelViewProjMat * vertex; 

}
