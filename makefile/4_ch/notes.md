# Chapter 4: GNU Pattern Rules

## 4.1 Basic Pattern Rule
- Pattern rule is indicated by a single `%` character in the target
- **stem** (%) matches a non-empty string
- The stem is then substitued for every `%` that appears in the prerequisite list
- The following
```make
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```
will match any target ending in `.o`
- Example:
	* Target is `foo.o`
	* The stem would the be `foo`
	* `foo.c` would be compiled to `foo.o`

## 4.2 Targets matching multiple Pattern Rules
- If a target matches multiple pattern rules, *make* will use te one whose prerequisites exist or can be built. For example
```make
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@
```
will compile `foo.c` to `foo.o` or assemble `foo.s` to `foo.o` (depending on if `foo.c` or `foo.s` exist)
- If multiple rules have prerequisites that exist or can be built, make will use the rule that matches to the shortest stem. For example
```make
f%r:
	@echo Stem is: $*
fo%r:
	@echo Stem is: $*
```
will use the second rule to make the target `foo.bar`, echoing `Stem is: o.ba`
- If multiple rules match to the shortest stem, make will use the first one in the Makefile

## 4.3 Directories in Pattern Rules
- If the target pattern doesn't contain slashes, make will remove the directory part from the target it's trying to build before matching
- The directory will then be put in front of the stem
- When the stem is used to build the target name and prerequisites, the directory part is stripped from it, the stem is substitued in place of `%` and finally the directory is put in front of the string
```make
foo%.o: %.c
	$(CC) $(CLFAGS) -c $< -l $@
```
- This example will match `lib/foobar.o` with:
	* Stem (`$*`): `lib/bar`
	* Target name (`$@`): `lib/foobar.o`
	* Prerequisites (`$<,$^`): `lib/foobar.c`
- In this example, a `lib/foo%.o` rule would take precedence over the `foo%.o` rule because it matches to a shorter stem

## 4.4 Pattern Rules with Multiple Targets
- Pattern rules can have multiple targets but, unlike normal rules, the recipe is responsible for making all the targets
```make
debug/%.o release/%.o: %.c
	$(CC) $(CFLAGS_DEBUGS) -c $< -o debug/$*.o
	$(CC) $(CFLAGS_RELEASE) -c $< -o release/$*.o
```
- This example will build both debug and release objects when one of them has to be built
```make
debug/%.o release/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```
- This example would only work when only one of `debug/*.o` or `release/*.o` is built, but it would only build the fist target and consider the second one to be up-to-date when both have to be built
