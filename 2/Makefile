# Компилятор
comp = gcc

# Флаги
CFLAGS = -Wall -fPIC
LDFLAGS_STATIC = -static
LDFLAGS_DYNAMIC = -L. -Wl,-rpath,.

# Папки
pref_cfiles = ./cfiles/
pref_objectfiles = ./objects/
pref_lib = ./lib/

# Общие исходные файлы (исключая commands_vector.c и commands_node.c)
base_cfiles = $(filter-out $(pref_cfiles)commands_vector.c $(pref_cfiles)commands_node.c, \
              $(wildcard $(pref_cfiles)*.c))

# Имена библиотек
LIB_A = libcommands_vector.a
LIB_A_SO = libcommands_vector.so
LIB_B = libcommands_node.a
LIB_B_SO = libcommands_node.so

# Цели по умолчанию
all: static dynamic

# --- Статическая линковка ---
static: program_a_static program_b_static

program_a_static: $(patsubst $(pref_cfiles)%.c, $(pref_objectfiles)%.o, $(base_cfiles)) $(pref_lib)$(LIB_A)
	$(comp) $^ -o $@ $(LDFLAGS_STATIC)

program_b_static: $(patsubst $(pref_cfiles)%.c, $(pref_objectfiles)%.o, $(base_cfiles)) $(pref_lib)$(LIB_B)
	$(comp) $^ -o $@ $(LDFLAGS_STATIC)

# --- Динамическая линковка ---
dynamic: program_a_dynamic program_b_dynamic

program_a_dynamic: $(patsubst $(pref_cfiles)%.c, $(pref_objectfiles)%.o, $(base_cfiles)) $(pref_lib)$(LIB_A_SO)
	$(comp) $^ -o $@ $(LDFLAGS_DYNAMIC) -lcommands_vector

program_b_dynamic: $(patsubst $(pref_cfiles)%.c, $(pref_objectfiles)%.o, $(base_cfiles)) $(pref_lib)$(LIB_B_SO)
	$(comp) $^ -o $@ $(LDFLAGS_DYNAMIC) -lcommands_node

# --- Библиотеки ---
# Статические
$(pref_lib)$(LIB_A): $(pref_objectfiles)commandsa.o
	ar rcs $@ $^

$(pref_lib)$(LIB_B): $(pref_objectfiles)commandsb.o
	ar rcs $@ $^

# Динамические
$(pref_lib)$(LIB_A_SO): $(pref_objectfiles)commandsa.o
	$(comp) -shared $^ -o $@

$(pref_lib)$(LIB_B_SO): $(pref_objectfiles)commandsb.o
	$(comp) -shared $^ -o $@

# --- Общие объектные файлы ---
$(pref_objectfiles)%.o: $(pref_cfiles)%.c
	$(comp) $(CFLAGS) -c $< -o $@

# --- Специальные объектные файлы ---
$(pref_objectfiles)commandsa.o: $(pref_cfiles)commands_vector.c
	$(comp) $(CFLAGS) -c $< -o $@

$(pref_objectfiles)commandsb.o: $(pref_cfiles)commands_node.c
	$(comp) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf $(pref_objectfiles)*.o $(pref_lib)*.a $(pref_lib)*.so program_a_* program_b_*

.PHONY: all static dynamic clean
