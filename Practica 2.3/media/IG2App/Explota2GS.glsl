#version 330 core // archivo ExplotaGS.glsl
layout (triangles) in; // procesa un triángulo: recibe 1 triángulo y
layout (triangle_strip, max_vertices = 3) out; // emite 1 triángulo
in vec2 []Vuv0;
out vec2 Guv0;
// los vértices no traen asociados atributos, solo las coordenadas
uniform float angle;
uniform float scale;
uniform mat4 modelViewProjMat; // para pasar a Clip-Space

vec3 baricentro(vec3 vertex[3]) { 
		vec3 a = vertex[0];
		vec3 b = vertex[1];
		vec3 c = vertex[2];
		vec3 n =vec3((a.x+b.x+c.x)/3,(a.y+b.y+c.y)/3,(a.z+b.z+c.z)/3);
		return normalize(n);
 } // vector normal al triángulo
vec3[] rotate(vec3 vertex[], float anglle){
			vec3 a =vec3(vertex[0].x + cos(anglle),vertex[0].y,vertex[0].z + sin(anglle));
		vec3 b =vec3(vertex[1].x + cos(anglle),vertex[1].y,vertex[1].z + sin(anglle));
		vec3 c = vec3(vertex[2].x + cos(anglle),vertex[2].y,vertex[2].z + sin(anglle));
		
		return vec3[](a,b,c);

}
void main() {
	vec3 vertices[3] = vec3[]( gl_in[0].gl_Position.xyz,
	gl_in[1].gl_Position.xyz,
	gl_in[2].gl_Position.xyz );
	vec3 dir = baricentro(vertices); 
	yaw(vertices,angle);
	
	// dir=rotate(dir,angle);
	for (int i=0; i<3; ++i) 
	{ // para emitir 3 vértices
		vec3 posDes = vertices[i] + dir * scale;
		vertices[i]=posDes;
		// vértice desplazado (los 3 en la misma dirección)
		// paso a Clip-Space
	}
	vec3[] rotados=rotate(vertices,angle);
	for (int i=0; i<3; ++i) 
	{	
		gl_Position = modelViewProjMat * vec4(rotados[i],1.0);
		Guv0=Vuv0[i];
		EmitVertex(); // al no declarar ninguna variable out, los vertices del
EndPrimitive();
}