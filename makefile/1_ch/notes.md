# Chapter 1: Getting started with makefile

## 1.1 Quick Start:
### 1.1.1 Rule
- Describes when and how certain files are created
- Update a target file if any of the files required for its creation are newer than the target
```make
targets: prerequisites
	<commands>
```
*targets*: the rule

*prerequisites*: files needed for the *target*

### 1.1.2 Execute Rule
- Run the *make* command in the terminal from the same directory as the *Makefile* recipe
- Running *make* without a specific *target* will execute the first ruel defined in the *Makefile*
- First run in the *Makefile* is often the *default* rule
	* ***NOTE:*** This is a convenctional rule that the *targets* prerequsites are all valid

### 1.1.3 Out-of-date
- *make* only executes the rule if the *target* is out-of-date
	* Target doesn't exist
	* Modification time is older than any of its prerequisites

## 1.2 Pattern Rules
- Pattern rules are used to specify multiple *targets* and construct *prerequisite* names from *target* names
- Each *target* can have its own *prerequisites*
- *target* and *prerequisites* relationship are built based on prefixes including path names and suffixes (or both)
```make
foo.o: foo.c
	cc -c $< -o $@

bar.o: bar.c
	cc -c $< -o $@
```
***NOTE:*** $< stands for the source files (foo.c and bar.c), $@ stands for the target

- Due to the targets sharing the same suffix, the two rules above can be re-written to the following pattern:
```make
%.o: %.c
	cc -c $< -o $@
```
***NOTE:*** % is the suffix pattern. In this case, we have a double-suffix. %.o is the target. %.c is the source files

## 1.3 Implicit Rules
### 1.3.1 Implicit Rules
- Tells *make* how to use customary methods to build certian types of target files
- *make* uses the target file name to determine which implict rule to invoke

### 1.3.2 Generic Rule to gzip a file
- A gzip file can be created by using the *gz* suffix pattern
```makefile
%.gz: %
	gzip $<
```
- Then running the make command with the *Makefile*
```shell
$ make -f Makefile example.txt.gz
```
- The *Makefile* consist of only one rule that instructs *make* how to create a file whose name end with .gz if there is a file with the same name but the .gz suffix

### 1.3.3 makefile Hello World
- In the *Makefile*, add this line
```make
helloWorld:
	echo hello world
```
- In the terminal, run
```shell
$ make helloWorld
echo hello world
hello world
```
