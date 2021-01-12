#version 330 core // archivo NormalesGS.glsl
layout (triangles) in; // procesa un triángulo
// genera una línea (vector normal) por cada vértice
layout (line_strip, max_vertices = 6) out;
// genera 3 líneas ‐> 3 primitivas cada una de 2 vértices
in vec3 gNormal[]; // 3 vectores normales provenientes del Vertex Shader
out vec3 vColor; // color para los vértices de la línea. Al declarar vColor out, cada vértice llevará asociado el color que contenga esta variable en el momento de emitirlo
const float SIZE = 50; // para la longitud de la línea
uniform mat4 modelViewProjMat; 
uniform float normals;

vec3 clampColor(vec3 c){

    if(c.r < 0) 
        c.r = 0;
    if(c.g < 0)
        c.g = 0;
    if(c.b < 0)
        c.b = 0;
    
    return c;
    }
void generateLine(int index) { // normal al vértice index (0, 1, 2)
    if(normals==1){
        vColor = abs(gNormal[index]);
        //vColor = clampColor(vColor);
        gl_Position = modelViewProjMat * gl_in[index].gl_Position;
        EmitVertex(); // 1º vértice de la línea con color y …
        vColor = abs(gNormal[index]);
        //vColor = clampColor(vColor);
        gl_Position = modelViewProjMat * (gl_in[index].gl_Position + vec4(gNormal[index],0) * SIZE);
        EmitVertex(); // 2º vértice de la línea con color y …
        EndPrimitive(); // línea formada por los 2 vértices emitidos
    }
    else 
    {
        vColor = vec3(1,0,0);
        gl_Position = modelViewProjMat * gl_in[index].gl_Position;
        EmitVertex(); // 1º vértice de la línea con color y …
        vColor = vec3(1,1,0);
        gl_Position = modelViewProjMat * (gl_in[index].gl_Position + vec4(gNormal[index],0) * SIZE);
        EmitVertex(); // 2º vértice de la línea con color y …
        EndPrimitive(); // línea formada por los 2 vértices emitidos 
    }
}
void main()
{
for (int i=0; i<3; ++i)
generateLine(i);
}