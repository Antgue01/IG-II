#version 330 core
in vec4 vertex; 
in vec2 uv0; 
in vec2 uv1; 
uniform mat4 modelViewProjMat; 
out vec2 vUv0;
out vec2 vUv1;
void main() {
vUv0 = uv0; 
vUv1 = ((vUv0.x - 0.5) * 0.5 + 0.5),(vUv0.y - 0.5) * 0.5 + 0.5));
gl_Position = modelViewProjMat * vertex; 
}
