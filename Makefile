.POSIX:
.PHONY: all test run clean fmt

all: test

test:
	@./run all

run:
	@./run $(f)

fmt:
	@find coding_interviews computer_science -name "*.rs" -exec rustfmt {} +
	@find coding_interviews computer_science -name "*.c" -exec clang-format -i {} +

clean:
	@rm -rf .build *.out *.o *.dSYM target
