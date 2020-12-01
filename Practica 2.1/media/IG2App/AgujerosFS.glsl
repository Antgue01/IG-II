#version 330 core
uniform sampler2D texturaL;
uniform vec4 InColor;
uniform vec4 OutColor;
in vec2 vUv0; 
out vec4 fFragColor;
void main() {
vec3 textColor = vec3(texture(texturaL, vUv0)); 
if(textColor.r > 0.5)
    discard;
if(gl_FrontFacing)    
    fFragColor = vec4(textColor, 1.0) * OutColor;
else
    fFragColor = InColor;
}