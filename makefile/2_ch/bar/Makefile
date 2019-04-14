TARGET: bar

.PHONY: all clean
$(TARGET): %.c
	gcc $< -c $@

clean:
	rm -rf $(TARGET)
