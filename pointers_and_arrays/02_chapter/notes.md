## Ch2: Pointer types and Arrays

### 2.1 Arrays
**Figure 2.1**
```c
            int my_array[] = {1, 23, 17,4, -5, 100};
```
We can refer to an integer by means of subscripts to `my_array` (i.e. `my_arr[0]`). We could access them via a pointer such as in figure 2.2:

**Figure 2.2**
```c
            int *ptr;
            ptr = &my_array[0];     // Point our pointer at the
                                    // first integer in our array
```
And then could print out our array either using the array notation or by dereferencing our pointer. See 2_chapter.c for the example

In C, the standard states that wherever we might use `&var_name[0]` we can replace that with `var_name`, thus in our code where we wrote

**Figure 2.3**
```c
            ptr = &my_array[0];
```
we can write:

**Figure 2.4**
```c
            ptr = my_array;
```
to achieve the same result.

Thus as Ted Jensen states;
> "The name of the array is the address of first element in the array"

Meaning that We can write:

**Figure 2.5**
```c
            ptr = my_array;
```
but we cannot write:

**Figure 2.6**
```c
            my_array = ptr;
```
because `ptr` is a variable, `my_array` is a constant. The location at which the first element of `my_array` will be stored cannot be changed once `my_array[]` has been declared.

### 2.2 Constant Pointers
When we declare a variable we set aside a spot in memory to hold the value of the appropriate type. Once that is done the name of the variable can be interpreted in one of two ways

    1. When used on the left side of the assignment operator, the compiler interprets it as the memory location to which to move that value resulting from evaluation of the right side of the assignment operator
    2. Used on the right side of the assignment operator, the name of a variable is interpreted to mean the contents stored at that memory address set aside to hold the value of that variable

**Figure 2.7**
```c
	int i, k;
	i = 2;
```
In figure 2.7, `i` is a variable and the occupies space in the data portion of memory, `2` is a constant and it is imbedded directly in the code segment of memory. Writing `k = i` tells the compiler to create code which at run time will look at memory location `&i` to determine the value to be moved to `k`. This puts `2` in the code and there is no referencing of the data segment. Both `k` and `i` are objects but `2` is not an object.

