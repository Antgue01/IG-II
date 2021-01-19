//Vertex Shader
#version 330 core // archivo ExplotaVS.glsl
in vec4 vertex;
in vec2 uv0;
in vec3 normal;

out vec2 Vuv0;
out vec3  modelViewNormal; 
out vec3  modelViewVertex; 

uniform mat4 modelViewMat; 
uniform mat4 normalMat; 

void main() {
gl_Position = vertex; // El GS tiene que transformar las coordenadas de gl_Position al espacio de corte
Vuv0 = uv0;

modelViewVertex = vec3(modelViewMat * vertex);
modelViewNormal = normalize(vec3(normalMat * vec4(normal,0)));
}