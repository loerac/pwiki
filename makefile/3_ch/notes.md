# Chapter 3: Advanced Makefile

## 3.1 Building From Different Source Folders to a Different Target Folder
- Main features of this Makefile
	* Automatic detection of C sources in specified folders
	* Multiple source folders
	* Multiple corresponding target folder for object and dependency files
	* Automatic rule generation for each target folder
	* Creation of target folders when they don't exist
	* Dependency management with *gcc*: Build only what is necessary
	* Works on *Unix* and *Dos* systems
	* Written for GNU Make
- This *Makefile* can be used to build a project with this kind of structure
```terminal
./Project
	|_./Source
		|_./Folder0
			|_./main.c
		|_./Folder1
			|_./file1_1.c
			|_./file1_1.h
		|_./Folder2
			|_./file2_1.c
			|_./file2_1.h
			|_./file2_2.c
			|_./file2_2.h
	|_./Build
		|_./Makefile
		|_./myApp.exe
		|_./Folder0
			|_./main.d
			|_./main.o
		|_./Folder1
			|_./file1_1.d
			|_./file1_1.o
		|_./Folder2
			|_./file2_1.d
			|_./file2_1.o
			|_./file2_2.d
			|_./file1_2.o
```
- Look inside Build/ for the *makefile*
- Run *make* inside of Build/ and the output myApp.exe will output
```terminal
$ ./myApp.exe
Hello world
Hello from file 1
Hello from file 2 section 1
Hello from file 2 section 2
```

## 3.2 Zipping lists
- This *pairmap* function takes three arguments:
	1. A function name
	2. First space-separated list
	3. Second space-separated list
- For each zipped tuple in the lists it will call the function with the following arguments
	1. Tuple element from the first list
	2. Tuple element from the second list
- It will expand to a space-separated list of the function expansions
```make
list-rem = $(wordlist 2,$(words $1),$1)
pairmap = $(and $(strip $2),$(strip $3),$(call \
	$1,$(firstword $2),$(firstword $3)) $(call \
	pairmap,$1,$(call list-rem,$2),$(call list-rem,$3)))
```
- For example, this:
```make
LIST1 := foo bar koo
LIST2 := 1 2 3

func = $1-$2

all:
	@echo $(call pairmap,func,$(LIST1),$(LIST2))

.PHONY: all
```
will print `foo-1 bar-2 baz-3`.
