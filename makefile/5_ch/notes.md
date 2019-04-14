# Chapter 5: Variables

## 5.1 Referencing a Variable
- Variables are used by a dollar sign ($) and then enclosed by a parentheses (()) or curly braces ({})

**Figure 5.1**
```make
x = hello
y = $(x)
# y now contains the value "hello"
y = ${x}
# Parenthese and curly braces are treated exactly the same
```
- If a variable is only one character long, the parentheses/braces can be omitted (i.e. `$x`)
	* Not recommened due to bad practice

## 5.2 Simply-Exapnded Variables
- The expression on the right-hand side is evaluated and the result is stored in the left-hand (variable)
- If the right-hand contains a variable reference, that variable is expanded before the assignment takes place

**Figure 5.2**
```make
x := hello
y := $(x)
# Both $(x) and $(y) will now yield "hello"
x := world
# $(x) now yields "world" and $(y) yields "hello"
```
- An alternative form is to use double-colon assignment

**Figure 5.3**
```make
x ::= hello
```
- Single- (and) doubel-colon assignment are equivalent
- The POSIX *make* standard only mentions the `::=` form so implementations with strict standards compliance may not support the single-colon version

## 5.3 Recursively-Expanded Variables
- When defining a recursively-expanded variable, the contents of the right-hand side are stored as is
- If a variable reference is present, the reference itself is stored (not the value of the variable)
- *make* waits to expand the variable references until the variable is actually used
- In Figure 5.2, the definition of `y` is recursive
	* The reference to `$(x)` doesn't get expanded utnil `$(y)` is expanded
	* This means that whenever the value of `x` is changed, the value of `y` will change as well
- Recursively-exanded variables can be used to create constructs that resemble templates or functions, or even to automatically generate portions of a makefile

## 5.4 Automatic Variables
- *make* automatically defines a number of special variables
- These variables can have a different value for each rule in a makefile and are designed to make writing rules simpler

**Table 5.1 - *make* Special Variables**
Variables | Description
:---: | ---
`$@` | File name of the rule's target
`$%` | The target member's name, if the rule's target is an archive
`$<` | File name of the first prerequisites
`$^` | List of all prerequisites
`$?` | List of all prerequisites that are newer than the target
`$*` | The "stem" of an implicit or pattern rule
- ***NOTE:*** These variables can only be used in the recipe portion of a rule

- Figure 5.4 uses automatic variables to generate a generic rule

**Figure 5.4**
```make
%.o: %.c
	cc -Wall $^ - c $@
```
- This instructs *make* how to construct a `.o` file out of a `.c` file with the same name
- Since we don't know the specific name of the affected file, we use `$@` as a placeholder for the output file's name and `$^` as a placeholder for the prerequisites list

## 5.5 Conditional Variable Assignment
- The `?=` operator is an extention that behaves like `=`, except that the assignment *only* occurs if the variable is not already set

**Figure 5.5**
```make
x = hello
x ?= world
# $(x) yields "hello"
```

## 5.6 Appending Text To an Existing Varaible
- The `+=` operatore is a common extension that adds the specified contents to the end of the varaible, separated by a space
```make
x = hello
x += world
# $(x) yields "helloworld"
```
- Variable references in the right-hand side will be expandeded if and only if the original variable was defined as a simply-expanded variable (Section 5.2)
