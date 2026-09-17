*This project has been created as part of the 42 curriculum by `nisim` and `mbin-mus`*

# Description
push_swap is a project about sorting data on a stack, with a limited set of instructions, using
the lowest possible number of actions. The set of instructions and other specifications would be detailed below.

## Sorting and stack
- Sorting is to rearrange data so that they end up in a predetermined sequence that follows a certain order.
- A stack is a linear data structure that follows a Last-In, First-Out (LIFO) rule, meaning the last item added is the first one removed.
- Stacks are only 'open' at one end.

## Available instructions
The goal is to sort in ascending order numbers into stack a. Only these operations are allowed in this project:
- sa (swap a): Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.
- sb (swap b): Swap the first two elements at the top of stack b. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by one. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by one. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by one. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by one. The last element becomes the first one.
- rrr : rra and rrb at the same time.

## Algorithms and Data Structure


# Instructions

## Compile

1. Run `make`
2. will be generated

## Remove Object Files

1. Run `make clean`
2. `*.o` files will be removed

## Full Clean

1. Run `make fclean`
2. Object files (`*.o`), default output files (`*.out`) and `libftprintf.a` file will be removed

## Using ft_printf

### Using `main.c` with ft_printf

To compile and run the C file (e.g. `main.c`) with functions from the library:

1. Include the Libft header file inside `main.c` file using `#include "ft_printf.h"`
2. Run `cc main.c libftprintf.a -o output.out`
3. `output.out` file will be generated (if there are no compliation errors)
4. Run `./output.out` to run the program

# Resources

1. [C Standard Library](https://github.com/wuzhouhui/c_standard_lib)
	Repository containing source code to C Standard Library as defined by Plauger
2. [Claude](https://claude.ai/new)
	AI tool used for generating test cases and explaining bugs
3. [GeeksForGeeks](https://www.geeksforgeeks.org/c/linked-list-in-c/)
	Resource for learning about linked lists and C in general
4. [Markdown Live Preview](https://markdownlivepreview.com/)
	Reference for markdown file format
5. [Python Tutor](https://pythontutor.com/c.html#)
	Visualizer for C (and Python)
6. [C99 Standard Draft](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf)
	Draft for C99 Standard (actual C99 Standard could be purchased, this draft is near identical)