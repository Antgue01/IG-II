#version 330 core 
in vec2 vUv0;
uniform sampler2D RTT0; // textura con la escena
out vec4 fFragColor;
uniform float kernel[9];

void main() 
{
   ivec2 texSize = textureSize(RTT0, 0);
   float incS = 1. / float(texSize.s);
   float incT = 1. / float(texSize.t);

   vec2 incUV[9] = vec2[]( // incrementos para acceder a
                    vec2(-incS, incT), // top‐left
                    vec2(0,incT) , // top‐center
                    vec2(incS,incT) , // top‐right
                    vec2(-incS,0) , // center‐left
                     vec2(0,0) , // center‐center
                     vec2(incS,0) , // center‐right
                     vec2(-incS,-incT) , // bottom‐left
                     vec2(0,-incT) , // bottom‐center
                     vec2( incS, -incT) // bottom‐right
                     );

   float sumTotal=0;
   for(int i=0;i<9;i++)
   {
      sumTotal+=kernel[i];
   }
 

   vec4 color = vec4(0.0);
   for(int i = 0; i < 9; i++) 
   {
      vec4 col = texture(RTT0,vUv0+incUV[i]);
      color += col * kernel[i]/sumTotal;
   }
   fFragColor = color;

}