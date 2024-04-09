//
//  main.cpp
//  Test
//
//  Created by João Paulo Arnold Barros on 12/06/23.
//
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int SCREEN_HEIGHT = 400;
int SCREEN_WIDTH  = 400;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    // Window Hint Context is returning null in mac, im disabling for this reason
    //    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to compile GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    gladLoadGL();

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    /* Loop until the user closes the window */
    
    float prev_time = float(glfwGetTime());
    float angle = 0.0f;

    while (!glfwWindowShouldClose(window))
    {
        float time = float(glfwGetTime());
        if (time - prev_time >= 0.1f){
            angle += 0.1f;
            prev_time = time;
        }
//        glClearColor(1.0f, 0.5f, 0.17f, 1.0f);
        glClearColor(sin(angle), cos(angle), tan(angle), 1.0f);
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
