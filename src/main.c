#include <stdio.h>
#include <GLFW/glfw3.h>

#include "tcc/libtcc.h"
#include "resource.h"

int main(int argc, char** argv) {
    printf("Hello, World!\n");

    load_manifest("include");

    glfwInit();

    TCCState *s;

    s = tcc_new();

    return 0;
}
