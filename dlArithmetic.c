#include<stdio.h>
#include<dlfcn.h>

int main(){
    void *handle;
    int (*add)(int, int), (*subtract)(int, int);
    int (*multiply)(int, int), (*divide)(int, int);
    char *error;
    handle = dlopen ("./lib/libArithmetic.so", RTLD_LAZY);
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }
    add = dlsym(handle, "add"); 
    if ((error = dlerror()) != NULL) { 
        fprintf (stderr, "%s", error); 
        exit(1); 
    }
    subtract = dlsym(handle, "subtract");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s", error);
        exit(1);
    }
    multiply = dlsym(handle, "multiply");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s", error);
        exit(1);
    }
    divide = dlsym(handle, "divide");
    if ((error = dlerror()) != NULL) {
        fprintf (stderr, "%s", error);
        exit(1);
    }
    printf("add(20,4) = %d\n", add(20,4));
    printf("subtract(20,4) = %d\n", subtract(20,4));
    printf("multiply(20,4) = %d\n", multiply(20,4));
    printf("divide(20,4) = %d\n", divide(20,4));
    
    dlclose(handle);
    return 0;
}
