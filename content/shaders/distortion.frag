/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#version 120

uniform sampler2D texture;
uniform sampler2D hmap;

void main()
{ 
    vec4 pixel2 = texture2D(hmap, gl_TexCoord[0].xy);
	vec2 coord = gl_TexCoord[0].xy +(pixel2.r/50);	
    vec4 pixel = texture2D(texture, coord);
	gl_FragColor = pixel;	
}