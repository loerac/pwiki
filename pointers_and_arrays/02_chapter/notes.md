## Ch2: Pointer types and Arrays

### 1.1 Arrays
Consider the following:
```c
            int my_array[] = {1, 23, 17,4, -5, 100};
```
We could access them via a pointer as follows:
```c
            int *ptr;
            ptr = &my_array[0];     // Point our pointer at the
                                    // first integer in our array
```
And then could print out our array either using the array notation or by dereferencing our pointer

#### Refer to main.c for example

In C, the standard states that wherever we might use ``&var_name[0]`` we can replace that with ``var_name``, thus in our code where we wrote
```c
            ptr = &my_array[0];
```
we can write:
```c
            ptr = my_array;
```
to achieve the same result. "The name of the array is the address of first element in the array" - Ted Jensen

We can write:
```c
            ptr = my_array;
```
We cannot write:
```c
            my_array = ptr;
```
because ``ptr`` is a variable, ``my_array`` is a constant. Te location at which the first element of ``my_array`` will be stored cannot be changed once ``my_array[]`` has been declared.

### 1.2 Constant Pointers
When we declare a variable we set aside a spot in memory to hold the value of the appropriate type.
Once that is done the name of the variable can be interpreted in one of two ways
    1. When used on the left side of the assignment operator, the compiler interprets it as the memory location to which to move that value resulting from evaluation of the right side of the assignment operator
    2. Used on the right side of the assignment operator, the name of a variable is interpreted to mean the contents stored at that memory address set aside to hold the value of that variable

```c
```
