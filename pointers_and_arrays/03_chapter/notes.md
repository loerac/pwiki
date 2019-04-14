## Ch3: Pointers and Strings

### 3.1 Strings
By definition, strings are an array of characters terminated with a nul character (i.e. `\0`). For illustrivative purposes, figure 3.1 shows how strings are made in C.

**Figure 3.1**
```c
char my_string[10];

my_string[0] = 'H';
my_string[1] = 'E';
my_string[2] = 'L';
my_string[3] = 'P';
my_string[4] = '\0';
```

Figure 3.1 is not an ideal way of building a string, but the end result is a string in that it is an aray of characters **terminated with a nul character**. "nul" is **not** the same as "NULL".

* "nul" refers to a zero as defined by the escape sequence `\0`.
* "NULL" refers to the name of the macro used to initialize null pointers.

Since writing a string such as figure 3.1 is time consuming, C permits two alternative ways of achieving the same thing

**Figure 3.2**
```c
char ex_1[10] = {'H', 'E', 'L', 'P', '\0'};

char ex_2[10] = "HELP";
```

`ex_1` is good but it also takes more typing rather than `ex_2`. When the double quotes are used, the nul character is automatically appended to the end of the string.

## 3.2 Program Example
In program_3_1.c, we have two global character arrays defined of 80 characters each. Both of them have the nul terminater. `strA` has the first 42 characters initialized to a string in quotes.

There are two character pointers, `pA` and `pB`, where `strA` points to `pA`. Both strings are printed on the screen and shown the same result.

Then `pA` is copied into `pB`, a nul character is added to the end of `pB` and the result of `pB` is the same as `strA` and `pA`.

## 3.3 String Copy
In program_3_1.c, the while loop is the `strcpy` method that C comes with.

**Figure 3.3**
```c
char *my_strcpy(char *destination, const char *source) {
	char *p = destination;
	while (*source != '\0') {
		*p++ = *source++;
	}
	*p = '\0';

	return destination;
}
```
In figure 3.3, `*my_strcpy()` a pointer instead of the size.

**Figure 3.4**
```c
int my_strncpy(char *destination, const char *source, const int size) {
	int i = 0;
	char *p = destination;
	while ( (size > i++) &&
		(*source != '\0') ) {
		*p++ = *source++;
	}
	*p = '\0';

	return i;
}
```
In figure 3.4, `my_strncpy()` returns the size of characters copied.
