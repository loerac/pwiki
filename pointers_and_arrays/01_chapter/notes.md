# Ch1: What is a pointer?

### 1.1 Variables
- A variable is something with a value which can vary
Each variable is assigned a specific block of memory within the computer to hold the vlue of that variable
- Size of that block depends on the range over which the variable is allowed to vary
- Variables contain two things:
    - **NAME** of the variable
    - **TYPE** of the variable
```c
                int k;
```
- Compiler sets aside 2 bytes of memory when seeing ``int`` in statement and sets up a symbol table
    - Adds the symbol ``k`` and the relative address in memory where those 2 bytes were set
```c
                k = 2;
```
- The value of ``2`` will be placed in that memory location for the storage of the value of ``k``
    - In C, variables are an _**object**_
- Two "values" associated with the object ``k``
    1. Value of the integer stored there
        - ``2`` in the above example
    2. Memory location
        - Address of ``k``

### 1.2 lvalue and rvalue
- lvalue:
    - The value permitted on the left side of the assignment operator '='
        - The address where the result of evaluation of the right side ends up
- rvalue:
    - Which is on the right side of the assignment statement
        - The ``2`` above
    - Cannot be used on the left side of the assignment statement
```c
                2 = k;  // **ILLEGAL**
```
- "An _**object**_ is a named region of storage; an _**lvalue**_ is an expression referring to an object" - K&R II (page 197)

- Consider:
```c
                int j, k;
                k = 2;
                j = 7;  // Line #1
                k = j;  // Line #2
```
- The compiler interprets the ``j`` in line #1 as the address of the variable ``j`` (the lvalue)
    - Creates code to copy the value ``7`` to that address
- In line #2, the ``j`` is interpreted as its rvalue
    - Since it is on the right hand side of the assignment operator
- ``j`` refers to the value _**stored**_ at the memory location set aside for ``j``, in this case ``7``
    - ``7`` is copied to the addres designated by the lvalue of ``k``

### 1.3 Pointer Variable
- Define a pointer variable with a preceeding asterisk (``*``)
- Pointers also need a type to refer to the data stored at the address we will be storing in our pointer
```c
                int *ptr;
```
- ``*ptr`` is the name of our variabe
- The ``*`` informs the compiler that we want a pointer variable
    - i.e. to set aside however many bytes is required to store an address in memory
- The ``int`` says that we intend to use our pointer variable to store the address of an integer
    - Such a pointer is said to "point to" an integer
- ``ptr`` has no value
    - No address has been stored in it
    - A pointer initialized in this manner is called a ``NULL`` pointer
- ``NULL`` is a macro that sets the value of a pointer to be a null pointer
```c
                ptr = NULL;
```
- We can test for a null pointer using
```c
                if (NULL == ptr) {
                    // ptr is NULL
                }
```
- To store the address of integer variable ``k`` into ``ptr``, we use the unary ``&`` operatore and write
```c
                ptr = &k;
```
- What the ``&`` operator does is retrieve the lvalue (address) of ``k`` and copies that to the contents of our pointer ``ptr``
    - ``ptr`` is said to "point to" ``k``
- "Dereferencing operator" is the asterisk and used as follows:
```c
                *ptr = 7;
```
``7`` is copied into the address pointer to by ``ptr``
- Thus if ``ptr`` "points to" ``k``, the above statement will set the value of ``k`` to ``7``
    - When we use the ``*`` this way we are referring to the value of that which ``ptr`` is pointing to, not the value of the pointer itself
- Similarly, we could write:
```c
                printf("%d\n", *ptr);
```
to print to the screen the integer value stored at the address pointed to by ``ptr``

#### Refer to program_1_1.c for a reference program


### To review:
- A variable is declared by giving it a type and a name (i.e. ``int k;``)
- A pointer variable is declared by giving it a type and a name (i.e. ``int *ptr``) where the asterisk tells the compiler that the variable named *ptr* is a pointer variable and the type tells the compiler what type the pointer is to point to (integer in this case)
- Once a variable is declared, we can get its address by preceding its name with the unary ``&`` operator as in ``&k``
- We can "dereference" a pointer (i.e. refer to the value of that which it points to) by using the ``*`` operator as in ``*ptr``
- An "lvalue" of a variable is the value of its address (i.e. where it is stored in memory)
- An "rvalue" of a variable is the value stored in that variable (i.e. at that address)
