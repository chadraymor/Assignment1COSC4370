
#version 330 core
out vec4 color;

in vec2 UV;
uniform sampler2D myTextureSampler;

void main()
{
    // TODO: pub with your code...
    //color of the texture at the uv

    // I was confused if we need the whole cube filled, i noticed that the dds file has 1-6 faces. i made it so there is only the 4 and 6
    // UV = vec2(UV.x, 1.0-UV.y) for the all the cube faces filled
    color = texture( myTextureSampler, UV);
}
