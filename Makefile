CC = gcc
CFLAGS = -Wall -g -std=c99
FLEX = flex
BISON = bison
BISON_FLAGS = -d -y

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

SOURCES = $(SRCDIR)/ast.c $(SRCDIR)/lexer.c $(SRCDIR)/parser.c
OBJECTS = $(OBJDIR)/ast.o $(OBJDIR)/lexer.o $(OBJDIR)/parser.o
HEADERS = $(INCDIR)/ast.h

TARGET = $(BINDIR)/sysy_compiler

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) -lm

$(OBJDIR)/ast.o: $(SRCDIR)/ast.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/lexer.o: $(SRCDIR)/lexer.c $(SRCDIR)/parser.tab.h | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/parser.o: $(SRCDIR)/parser.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(SRCDIR)/parser.c $(SRCDIR)/parser.tab.h: $(SRCDIR)/parser.y
	$(BISON) $(BISON_FLAGS) --defines=$(SRCDIR)/parser.tab.h -o $(SRCDIR)/parser.c $<

$(SRCDIR)/lexer.c: $(SRCDIR)/lexer.l $(SRCDIR)/parser.tab.h
	$(FLEX) -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)
	rm -f $(SRCDIR)/lexer.c $(SRCDIR)/parser.c $(SRCDIR)/parser.tab.h

test: $(TARGET)
	@echo "Testing compiler..."
	@if [ -f test/test1.sy ]; then \
		$(TARGET) test/test1.sy; \
	fi

