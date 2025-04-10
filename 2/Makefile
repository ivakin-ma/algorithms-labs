# Компилятор
comp = gcc

# Папки
pref_cfiles = ./cfiles/
pref_objectfiles = ./objects/

# Общие исходные файлы (исключая commandsa.c и commandsb.c)
base_cfiles = $(filter-out $(pref_cfiles)commands_vector.c $(pref_cfiles)commands_node.c, \
              $(wildcard $(pref_cfiles)*.c))

# Правила сборки
program_a: $(patsubst $(pref_cfiles)%.c, $(pref_objectfiles)%.o, $(base_cfiles)) $(pref_objectfiles)commandsa.o
	$(comp) $^ -o $@

program_b: $(patsubst $(pref_cfiles)%.c, $(pref_objectfiles)%.o, $(base_cfiles)) $(pref_objectfiles)commandsb.o
	$(comp) $^ -o $@

# Правило для общих объектных файлов
$(pref_objectfiles)%.o: $(pref_cfiles)%.c
	$(comp) -c $< -o $@

# Правило для commandsa.o (только для program_a)
$(pref_objectfiles)commandsa.o: $(pref_cfiles)commands_vector.c
	$(comp) -c $< -o $@

# Правило для commandsb.o (только для program_b)
$(pref_objectfiles)commandsb.o: $(pref_cfiles)commands_node.c
	$(comp) -c $< -o $@

clean:
	rm -f $(pref_objectfiles)*.o program_a program_b
