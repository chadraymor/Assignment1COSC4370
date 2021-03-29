
#version 330 core
out vec4 color;

in vec3 FragPos;  
in vec3 Normal;  
  
uniform vec3 lightPos; 
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    // TODO: Replace with your code...
    // If gl_Position was set correctly, this gives a totally red cube
    color = vec4(vec3(1.f,0.f,0.f), 1.0f);

    //ambient lighting (.1 is the strength of the lighting)
    vec3 ambient = 0.1 * lightColor;

    //diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDirection = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDirection), 0.0);
    vec3 diffuse = diff * lightColor;

    //specular
    vec3 viewDirection = normalize(viewPos - FragPos);
    vec3 reflectDirection = reflect(-lightDirection, norm);  
    float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), 32);
    vec3 specular = 0.7 * spec * lightColor;  

    //combined all into phong shader
    vec3 result = vec3(0.0,0.0,0.0);
    result = ambient + diffuse + specular;
    color = vec4(result * objectColor, 1.0);


} 


