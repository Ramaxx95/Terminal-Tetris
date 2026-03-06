# CONFIGURACION
################

# Nombre del ejecutable.
target = tetris

# CONFIGURACION "AVANZADA"
###########################

# Opciones para el compilador C/C++ para tratamiento de errores y warnings.
CFLAGS += -Wall -Werror -pedantic -pedantic-errors -fstack-protector

# -O3: optimiza el binario, posiblemente revelando bugs sutiles
# -O0: no optimiza el binario pero lo hace debuggeable
ifdef optimize
CFLAGS += -O3
else
CFLAGS += -O0
endif

# Para valgrind o debug
CFLAGS += -ggdb -DDEBUG -fno-inline

# Opciones del enlazador.
LDFLAGS =

# Estandar de C++ a usar
CXXSTD = c++17

# Estandar POSIX que extiende C/C++. En teoria los grandes
# sistemas operativos incluyendo Windows son POSIX compliant
CFLAGS += -D _POSIX_C_SOURCE=200809L

# Si se quiere compilar estaticamente, descomentar la siguiente linea
#static = si

# VARIABLES CALCULADAS A PARTIR DE LA CONFIGURACION
####################################################

ifdef static
LDFLAGS += -static
endif

# Se reutilizan los flags de C para C++ también
CXXFLAGS += $(CFLAGS)

CXXFLAGS += -std=$(CXXSTD)
LD = $(CXX)
COMPILER = $(CXX)
COMPILERFLAGS = $(CXXFLAGS)

# Agrego librerias externas.
# CXXFLAGS += -Isrc/extlib/include
LIBS += -lncurses

# Directorios
SRCDIR = src
OBJDIR = bin

# Si no especifica archivos, tomo todos.
srcfiles = $(shell find $(SRCDIR) -name '*.cpp')
srcdirs = $(shell find $(SRCDIR) -type d | sed 's/$(SRCDIR)/./g')
objs = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(srcfiles))

# REGLAS
#########

.PHONY: all clean

all: $(target)

$(target): buildrepo $(objs) # buildrepo $(objs)
	@echo "### Linking project ###"
	$(LD) $(objs) $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "### Compiling source file $< ###" 
	$(COMPILER) $(COMPILERFLAGS) -c $< -o $@
	@echo
	
clean-obj:
	$(RM) -f $(objs)

clean: clean-obj
	$(RM) -f $(target)

buildrepo:
	@$(call make-repo)

# Create obj directory structure
define make-repo
	mkdir -p $(OBJDIR)
	for dir in $(srcdirs); \
	do \
		mkdir -p $(OBJDIR)/$$dir; \
	done
endef