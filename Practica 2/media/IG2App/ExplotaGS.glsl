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
uniform float tiempo;
uniform mat4 modelViewProjMat; // para pasar a Clip-Space
const float VD = 50; // longitud del desplazamiento

vec3 normalVec(vec3 vertex[3]) { 
		vec3 a = vertex[0];
		vec3 b = vertex[1];
		vec3 c = vertex[2];
		vec3 n = normalize(cross(b - a, c - a));
		return n;
 } // vector normal al triángulo

void main() {
	vec3 vertices[3] = vec3[]( gl_in[0].gl_Position.xyz,
	gl_in[1].gl_Position.xyz,
	gl_in[2].gl_Position.xyz );
	vec3 dir = normalVec(vertices) * tiempo; 
	for (int i=0; i<3; ++i) 
	{ // para emitir 3 vértices
		vec3 posDes = vertices[i] + dir * VD;
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