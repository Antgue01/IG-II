#version 330 core // archivo ExplotaFS.glsl
out vec4 fFragColor;
in vec2 Guv0;
in vec3  GmodelViewNormal; 
in vec3  GmodelViewVertex; 

uniform float Flipping;
uniform sampler2D texturaL;
uniform sampler2D texturaM;

uniform vec3 lightAmbient; 
uniform vec3 lightDiffuse;
uniform vec4 lightPosition;


float diff(vec3 cVertex, vec3 cNormal)
{
  vec3 lightDir = lightPosition.xyz;

  if(lightPosition.w == 1) lightDir = lightPosition.xyz - cVertex;

  return max(dot(cNormal,normalize(lightDir)),0.0);
}


void main() {

vec4 frontColor;
vec4 backColor;
// ambient
vec3 ambient = lightAmbient * vec4(texture(texturaM,Guv0)).xyz* vec4(texture(texturaL,Guv0)).xyz;

vec3 diffuse = diff(GmodelViewVertex, GmodelViewNormal) * lightDiffuse *vec4(texture(texturaM,Guv0)).xyz ;

frontColor = vec4(ambient + diffuse,1.0);

diffuse = diff( GmodelViewVertex,-GmodelViewNormal) *lightDiffuse * vec4(texture(texturaL,Guv0)).xyz;

backColor = vec4(ambient + diffuse,1.0);


bool frontFacing = (Flipping > -1)? gl_FrontFacing : ! gl_FrontFacing;
if(frontFacing)    
    fFragColor = vec4(texture(texturaM,Guv0))*frontColor;
else
    fFragColor = vec4(texture(texturaL,Guv0))*backColor;


}