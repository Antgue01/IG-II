#version 330 core
uniform mat4 modelViewMat;
uniform mat4 normalMat;

uniform vec3 lightAmbient; 
uniform vec3 lightDiffuse;
uniform vec4 lightPosition;

uniform vec3 materialDiffuse;

uniform sampler2D texturaL;
uniform sampler2D texturaM;
uniform vec4 InColor;
uniform vec4 OutColor;
uniform float Flipping;

in vec2 vUv0; 
in vec3  modelViewNormal; 
in vec3  modelViewVertex; 

out vec4 fFragColor;

float diff(vec3 cVertex, vec3 cNormal)
{
  vec3 lightDir = lightPosition.xyz;

  if(lightPosition.w == 1) lightDir = lightPosition.xyz - cVertex;

  return max(dot(cNormal,normalize(lightDir)),0.0);
}


void main() 
{

vec3 textColor = vec3(texture(texturaL, vUv0)); 
if(textColor.r < 0.5)
    discard;

vec4 frontColor;
vec4 backColor;
// ambient
vec3 ambient = lightAmbient * materialDiffuse;

vec3 diffuse = diff( modelViewVertex, modelViewNormal) * lightDiffuse * materialDiffuse;

frontColor = vec4(ambient + diffuse,1.0);

diffuse = diff( modelViewVertex,-modelViewNormal) * lightDiffuse * materialDiffuse;

backColor = vec4(ambient + diffuse,1.0);


bool frontFacing = (Flipping > -1)? gl_FrontFacing : ! gl_FrontFacing;
if(frontFacing)    
    fFragColor = vec4(texture(texturaM,vUv0)) * frontColor * OutColor;
else
    fFragColor = backColor * InColor;


}