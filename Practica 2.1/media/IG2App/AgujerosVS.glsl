#version 330 core
in vec4 vertex; 
in vec3 normal;
in vec2 uv0; 
uniform mat4 modelViewProjMat; 

uniform mat4 modelViewMat; 
uniform mat4 normalMat; 

out vec2 vUv0;
out vec3  modelViewNormal; 
out vec3  modelViewVertex; 

void main() {

vUv0 = uv0; 

gl_Position = modelViewProjMat * vertex; 

// diffuse en view space
 modelViewVertex = vec3(modelViewMat * vertex);
 modelViewNormal = normalize(vec3(normalMat * vec4(normal,0)));

}
