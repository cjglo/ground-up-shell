
C_SOURCE_FILES := src/main.c src/modes/read_from_file.c src/utils/fork_and_exec.c

build: ${C_SOURCE_FILES}
	gcc ${C_SOURCE_FILES} -o shell.out

run: shell.out
	./shell.out $(arg)

clean:
	rm shell.out

all:
	make build
	printf "\n\n"
	make run $(arg)
	make clean

all_test:
	make build
	printf "\n\n"
	make run arg=input.test
	make clean