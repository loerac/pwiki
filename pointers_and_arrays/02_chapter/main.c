#include <stdio.h>

int *ptr;
int my_array[] = {1, 23, 17, 4, -5, 100};

int main( void ) {
    int i;
    //ptr = &my_array[0];
    ptr = my_array;         // Point our pointer to the
                            // first element of the array

    printf("\n\n");
    for (i = 0; i < 6; i++) {
        //printf("    ptr + %d = %d\n", i, *(ptr + i));      // <-- B
        //printf("    ptr + %d = %d\n", i, *ptr++);          // <-- B
        printf("    ptr + %d = %d\n", i, *(++ptr));        // <-- B
        printf("my_array[%d] = %d\n\n", i, my_array[i]);     // <-- A
    }

    return 0;
}
