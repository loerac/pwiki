# Chapter 2: .PHONY target

### 2.1 Using .PHONY for non-files targets
- Use `.PHONY` to specify the targets that are not files (i.e. `clean` or `all`)
```make
.PHONY: clean
clean:
	rm *.o *.c temp
```

### 2.2 Using .PHONY for recursive invocations of 'make' command
- Using *make* as a command within a *makefile*
- Used for large projects containing sub-directories, where each sub-directory has their own *makefile*
```terminal
./main
	|_Makefile
	|_./foo
		|_Makefile
		|_ ... // other files
	|_./bar
		|_Makefile
		|_ ... // other files
	|_./koo
		|_Makefile
		|_ ... // other files
```
- To recurse each sub-directory, the main *makefile* would have a list of the sub-directories
```make
SUBDIRS=foo bar koo

subdirs:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done
```
- This method fails on two parts
	1. Any error detected in a sub-make is ignored by this rule, so it will continue to build the rest of the directories even when one fails
	2. Make's ability to perform Parallel execution of multiple build targets is not utilized since only one rule is used

- By declaring the sub-directories as .PHONY targets, these problems can be overcomed
```make
SUBDIRS=foo bar koo

.PHONY:subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@
```
