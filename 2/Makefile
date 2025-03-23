target = test
comp =  gcc
pref_cfiles = ./cfiles/
pref_objectfiles = ./objects/
cfiles = $(wildcard $(pref_cfiles)*.c)
objectfiles = $(patsubst $(pref_cfiles)%.c, $(pref_objectfiles)%.o, $(cfiles))
$(target) : $(objectfiles)
	$(comp) $(objectfiles) -o $(target)
$(pref_objectfiles)%.o : $(pref_cfiles)%.c
	$(comp) -c $< -o $@
