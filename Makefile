TARGET   = b64

CC       = gcc
CFLAGS   = -std=c99 -Wall -I.

LINKER   = gcc
LFLAGS   = -Wall -I. -lm

CC       = gcc
CFLAGS   = -fPIC

DLINKER   = gcc
DLFLAGS   = -shared 

SLINKER   = ar
SLFLAGS   = -rcs

SRCDIR   = src
OBJDIR   = obj
LIBDIR   = lib
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

all:
	$(CC) $(CFLAGS) -o "$(OBJDIR)/b64.o" -c "$(SRCDIR)/b64.c"
	$(DLINKER) $(DLFLAGS) -o "$(LIBDIR)/$(TARGET).so" "$(OBJDIR)/b64.o"
	$(SLINKER) $(SLFLAGS) "$(LIBDIR)/lib$(TARGET).a" "$(OBJDIR)/b64.o"
#
# $(BINDIR)/$(TARGET): $(OBJECTS)
# 	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
# 	@echo "Linking complete!"
#
# $(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
# 	@echo "Compiled "$<" successfully!"
#
# .PHONY: clean
# clean:
# 	@$(rm) $(OBJECTS)
# 	@echo "Cleanup complete!"
#
# .PHONY: remove
# remove: clean
# 	@$(rm) $(BINDIR)/$(TARGET)
# 	@echo "Executable removed!"
