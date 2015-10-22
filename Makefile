objects = como_main.o como_memory_manager.o como_value_functions.o
CCFLAGS = -Wall -Wextra -Wpedantic

como_main : $(objects)
	cc $(CCFLAGS) -o main $(objects)
.PHONY : clean
clean:
	rm -f main $(objects)
