#include <stdio.h>

int main(int argc, char** argv, char** envp) {
    // Prints all passed environment variables
    for(int i=0; envp[i] != NULL; ++i) {
        printf("%s\n", envp[i]);
    }
}
