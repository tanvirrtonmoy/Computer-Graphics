#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include<windows.h>

const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec2 aPos;
out vec2 fragCoord;
void main()
{
    fragCoord = aPos;
    gl_Position = vec4(aPos, 0.0, 1.0);
}
)";

const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;
in vec2 fragCoord;

uniform vec2 u_resolution;

void main()
{
    vec2 uv = fragCoord * 0.5 + 0.5;
    vec2 pos = (fragCoord * u_resolution);

    vec3 rayOrigin = vec3(0.0, 0.0, 1.0);
    vec3 rayDir = normalize(vec3(fragCoord, -1.0));

    vec3 sphereCenter = vec3(0.0, 0.0, 0.0);
    float radius = 0.5;

    // Ray-sphere intersection
    vec3 oc = rayOrigin - sphereCenter;
    float b = dot(oc, rayDir);
    float c = dot(oc, oc) - radius * radius;
    float h = b * b - c;

    if(h < 0.0)
    {
        FragColor = vec4(0.0, 0.0, 0.0, 1.0); // No hit
    }
    else
    {
        h = sqrt(h);
        float t = -b - h;
        vec3 hit = rayOrigin + rayDir * t;
        vec3 normal = normalize(hit - sphereCenter);

        vec3 lightDir = normalize(vec3(-0.5, 0.5, 1.0));
        float diff = max(dot(normal, lightDir), 0.0);

        vec3 color = vec3(1.0, 0.3, 0.2) * diff;
        FragColor = vec4(color, 1.0);
    }
}
)";

// Fullscreen quad vertices
float quadVertices[] = {
    -1.0f, -1.0f,
     1.0f, -1.0f,
    -1.0f,  1.0f,
     1.0f,  1.0f,
};

unsigned int compileShader(GLenum type, const char* source) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    return shader;
}

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 800, "Basic Ray Tracing", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vs);
    glAttachShader(shaderProgram, fs);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    unsigned int vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glUniform2f(glGetUniformLocation(shaderProgram, "u_resolution"), (float)width, (float)height);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
