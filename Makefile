TARGET   = libb64

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

SOURCES  := $(wildcard $(SRCDIR)/*.c)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

static: objs
	$(SLINKER) $(SLFLAGS) "$(LIBDIR)/$(TARGET).a" "$(OBJDIR)/b64.o"

shared: objs
	$(DLINKER) $(DLFLAGS) -o "$(LIBDIR)/$(TARGET).so" "$(OBJDIR)/b64.o"

objs:
	mkdir -p $(OBJDIR)
	mkdir -p $(LIBDIR)
	$(CC) $(CFLAGS) -o $(OBJECTS) -c $(SOURCES) 
