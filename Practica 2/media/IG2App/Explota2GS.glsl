#version 330 core // archivo ExplotaGS.glsl
layout (triangles) in; // procesa un triángulo: recibe 1 triángulo y
layout (triangle_strip, max_vertices = 3) out; // emite 1 triángulo
in vec2 []Vuv0;
in vec3[] modelViewNormal; 
in vec3[] modelViewVertex;

out vec2 Guv0;
out vec3 GmodelViewNormal;
out vec3 GmodelViewVertex;

// los vértices no traen asociados atributos, solo las coordenadas
uniform float angle;
uniform float tiempo2pi;
uniform mat4 modelViewProjMat; // para pasar a Clip-Space
uniform float scale; // longitud del desplazamiento
const float scaleEffect=50;

vec3 baricentro(vec3 vertex[3]) { 
		vec3 a = vertex[0];
		vec3 b = vertex[1];
		vec3 c = vertex[2];
		vec3 n =vec3((a.x+b.x+c.x)/3,(a.y+b.y+c.y)/3,(a.z+b.z+c.z)/3);
		return normalize(n);
}

vec3 rotate(vec3 dir, float anglle){

	vec3 aux;
        for(int i=0;i<3;i++)
        {
            aux = dir*mat3(cos(anglle), 0, sin(anglle), 0,1,0,-sin(anglle),0, cos(anglle));
        }
    return aux;
}


void main() {
	vec3 vertices[3] = vec3[]( gl_in[0].gl_Position.xyz,
	gl_in[1].gl_Position.xyz,
	gl_in[2].gl_Position.xyz );

	vec3 dir = baricentro(vertices); 
 

	for (int i=0; i<3; ++i) 
	{ // para emitir 3 vértices
		vec3 posDes = vertices[i] + dir * scale*scaleEffect;

        posDes = rotate(posDes,tiempo2pi);

		// vértice desplazado (los 3 en la misma dirección)
		gl_Position = modelViewProjMat * vec4(posDes,1.0);
		// paso a Clip-Space
		Guv0=Vuv0[i];
        GmodelViewNormal = modelViewNormal[i];
        GmodelViewVertex = modelViewVertex[i];

		EmitVertex(); // al no declarar ninguna variable out, los vertices del
	// triángulo emitido no llevan asociados atributos, solo las coordenadas
	}
EndPrimitive();
}