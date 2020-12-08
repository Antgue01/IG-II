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

in vec2 vUv0; 
in vec3 vXxxNormal; 
in vec4 vXxxVertex; 
out vec4 fFragColor;
float diff(vec3 cVertex, vec3 cNormal)
{
  vec3 lightDir = lightPosition.xyz;

  if(lightPosition.w == 1) lightDir = lightPosition.xyz - cVertex;

  return max(dot(cNormal,normalize(lightDir)),0.0);
}


void main() 
{

vec4 frontColor;
vec4 backColor;


// ambient
vec3 ambient = lightAmbient * materialDiffuse;
// diffuse en view space
vec3 viewVertex = vec3(modelViewMat * vXxxVertex);
vec3 viewNormal = normalize(vec3(normalMat * vec4(vXxxNormal,0)));
vec3 diffuse = diff(viewVertex, viewNormal) * lightDiffuse * materialDiffuse;

//frontColor = ambient + diffuse; // + specular
frontColor = vec4(ambient + diffuse,1.0);

diffuse = diff(viewVertex,-viewNormal) * lightDiffuse * materialDiffuse;

//backColor = ambient + diffuse; // + specular
backColor = vec4(ambient + diffuse,1.0);


vec3 textColor = vec3(texture(texturaL, vUv0)); 
if(textColor.r < 0.5)
    discard;
if(gl_FrontFacing)    
    fFragColor = vec4(texture(texturaM,vUv0)) * frontColor * OutColor;
else
    fFragColor = backColor * InColor;


}