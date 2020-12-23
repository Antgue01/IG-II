#version 330 core // archivo ExplotaFS.glsl
out vec4 fFragColor;
in vec2 Guv0;

uniform float Flipping;
uniform sampler2D texturaL;
uniform sampler2D texturaM;

void main() {
bool frontFacing = (Flipping > -1)? gl_FrontFacing : ! gl_FrontFacing;
if(frontFacing)    
    fFragColor = vec4(texture(texturaM,Guv0));
else
    fFragColor = vec4(texture(texturaL,Guv0));


}