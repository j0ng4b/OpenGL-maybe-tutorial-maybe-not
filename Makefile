CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
INCLUDE_DIRS = include $(wildcard src/external/**/include)
CPPFLAGS = -MMD -MP $(foreach path,$(INCLUDE_DIRS),-I$(path))

LDLIBS = -lglfw -lm
LDFLAGS = -Wl,--no-undefined

SOURCES = $(wildcard src/*.c) \
          $(wildcard src/external/**/src/*.c)
OBJECTS = $(addprefix build/,$(SOURCES:.c=.o))
DEPENDENCIES = $(OBJECTS:.o=.d)
TARGET = opengl

-include $(DEPENDENCIES)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) $(LDLIBS) -o $@

build/%.o: %.c
	mkdir -p $(@D)
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

run: $(TARGET)
	./$(TARGET)

.PHONY: clean
clean:
	rm -rf build/
	rm -f $(TARGET)

