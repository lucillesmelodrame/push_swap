*This project has been created as part of the 42 curriculum by sonfong.*

## Description
This project involves making our own C library which includes the general useful standard functions to be applied in future projects.

It aims for students to learn how to implement said functions and how to use them effectively, allowing them to understand how they work. It also enables students to familiarise themselves with programming concepts such as iteration, recursion and linked lists.

## Instruction
To create the **libft.a** library, run the command `make all / make libft.a / make`.

To remove all object files (*.o) only, run the command `make clean`.

To remove **libft.a** and all object files, run the command `make fclean`. 

To remove all object files and **libft.a** library, then recreate the entire library again, run the command `make re`.

All functions should be (and are while testing) compiled with `cc -Wall -Werror -Wextra`. To use the library, compile the c file with the library. `cc -Wall -Wextra -Werror ft_split.c libft.a`.

## Resources
The behaviour of each function was implemented using resources such as:
* [W3Schools](https://www.w3schools.com/c/index.php) / [GeeksForGeeks](https://www.geeksforgeeks.org/c/c-programming-language/) / [42-cursus GitBook](https://42-cursus.gitbook.io/guide) / `man` pages — to understand new concepts and help with implementation.
* [Python Tutor](https://pythontutor.com/visualize.html#mode=edit) — to help with visualisation of difficult problems.
* My own peers on campus ૮₍´｡ᵔ ꈊ ᵔ｡`₎ა
### AI usage
AI was not used as source for solutions but only used for research for concepts and questions that could not be easily found from the resources mentioned above, and provided extra guidance.

## Details
### Part 1: Libc functions
These functions are reimplemented from the `libc`. They have the same prototypes and behaviours as the originals, only difference being their names that start with the prefix `ft_`.
#### Character Classification Functions — these return (1) if the character matches the tested class, and return (0) if it does not match.
* `ft_isalpha` — checks whether a character is an alphabet.
* `ft_isdigit` — checks whether a character is a digit.
* `ft_isalnum` — checks whether a character is an alphabet or a digit.
* `ft_isascii` — checks whether a character is an ASCII character.
* `ft_isprint` — checks whether a character is a printable character.
#### Return Value Functions — these functions return a value corresponding to the function's purpose
* `ft_strlen` — returns the amount of characters in a string, excluding the NULL terminator.
* `ft_toupper` — returns the uppercase alphabet of a character of a lowercase character. Returns the original character if not a lowercase character.
* `ft_tolower` — returns the lowercase alphabet of a character of an uppercase character. Returns the original character if not an uppercase character.
* `ft_strncmp` — compares the first (at most) `n` bytes of two strings. Returns (0) if two strings are equal, negative value if `s1` is less than `s2`, positive value if vice-versa.
* `ft_memcmp` — compares the first `n` bytes in memory of two strings, returns an int less than, equal to, or greater than 0 if the first `n` bytes of difference is found. Otherwise, returns (0).
* `ft_atoi` — returns an integer converted from the string given. Example: `char "-124"` returns `int 124`
#### Modified Parameter Functions — these functions modify the string/memory given to it as parameters
* `ft_memset` — fills the first `n` bytes of memory area pointed to by `s` with the constant byte `n`.
* `ft_bzero` — sets the first `n` bytes of the memory address given to zero.
* `ft_memcpy` — copies `n` bytes from memory area `src` to memory area `dest`. *Memory areas should not overlap.*
* `ft_memmove` — copies `n` bytes from memory area `src` to memory area `dest`. Copying takes place through copying `src` to a temporary array that does not overlap `src` or `dest`, then from the temporary array to `dest`.
* `ft_strlcpy` — copies up to `n - 1` characters from the NULL-terminated string `src` to `dest`, NULL-terminating the result.
* `ft_strlcat` — concatenates characters from `src` to `dest`. Appends at most `n - strlen(dst) - 1` bytes, NUL-terminating the result. 
#### Return Pointer Functions — these functions return a pointer corresponding to the functions purpose
* `ft_strchr` — returns a pointer to the first occurrence of the character `c` in string `s`, including NUL-terminator. Returns `NULL` if `c` is not found in `s`.
* `ft_strrchr` — returns a pointer to the last occurrence of the character `c` in string `s`, including NUL-terminator. Returns `NULL` if `c` is not found in `s`.
* `ft_memchr` — scans the first initial `n` bytes in the memory area pointed to by `s` and returns a pointer to the first instance of `c`.
* `ft_strnstr` —  locates  the  first occurrence of the null-terminated string `little` in the string `big`, where not more than `len` characters are searched. Characters that appear after `\0` are not searched. If `little` is empty, `big` is returned. If `little` is nowhere in `big`, `NULL` is returned; otherwise a pointer to the first character of the first occurrence of `little` is returned.
#### Memory Allocated Functions — these functions return a pointer to the allocated memory corresponding to the functions purpose using `malloc`
* `ft_calloc` — allocates memory for an array of `n` elements of `size` bytes each and returns a pointer to the allocated memory. The memory is set to 0.
* `ft_strdup` — returns a pointer to a new string which is duplicated from string `s`. Memory for the string is obtained with `malloc`.
### Part 2: Additional Functions
* `ft_substr` — returns a substring of `s` in a newly allocated address with `start` as its starting index and `len` as its length.
* `ft_strjoin` — returns a concatenated string of `s1` and `s2` in a newly allocated address
* `ft_strtrim` — returns a newly allocated address where `set` is removed from the beginning and the end of string `s1`
* `ft_split` — `s` is split by the delimiter `c` and copied into newly allocated array of strings, and is returned with the last array being `NULL`
* `ft_itoa` — returns the string version of an int. Example: `int -124` returns `char "-124"`
* `ft_strmapi` — returns the result of the function `f` applied to each character of the string `s`, where its index is the first argument and the character itself is the second argument, into a newly allocated address.
* `ft_striteri` — passes each character of `s` by address to function `f`, with its index as the first argument
#### File descriptor functions — these functions write its given arguments to its specified file descriptor
* `ft_putchar_fd` — writes `char c` to its specified file descriptor
* `ft_putstr_fd` — writes string `s` to its specified file descriptor
* `ft_putendl_fd` — writes string `s` to its specified file descriptor followed by a new line.
* `ft_putnbr_fd` — writes the string version of an int to its specified file descriptor.
### Part 3: Linked list functions
* `ft_lstnew` — allocates memory using `malloc` and returns a new node, where content is initialised with the given parameter and `NEXT` is initialised to `NULL`
* `ft_lstadd_front` — Adds the `new` node to the beginning of the list
* `ft_lstsize` — counts and returns the number of nodes in the list
* `ft_lstlast` — returns the last node of the list
* `ft_lstadd_back` — adds the `new` node at the end of the list
* `ft_lstdelone` — frees the content of the node received as a parameter, does not free the next node
* `ft_lstclear` — deletes and frees the given node and all of the next ones, sets the pointer to the list to `NULL`
* `ft_lstiter` — iterates through `lst` and applies the function `f` to each node
* `ft_lstmap` — iterates through `lst`, applies function `f` and creates a new list with all the successive applications of `f`, `del` deletes the content of a node if needed.

## Additional Instructions
I have created a `testers` branch in my git repo, with additional testing infrastructure that is not part of the graded submission but is available to test the library's behaviour directly.

To switch to the testers branch, run the command `git checkout testers`.

To switch back to the master branch, run the command `git checkout master`.
### What's inside the test branch
Besides the same thing as the master branch, the test branch also includes:
* `tester.h` — a shared header used by the test programs. It defines simple color macros (`RED`, `GREEN`, `RESET`) for readable pass/fail output, and a set of small structs (e.g. `t_memchr`, `t_strncmp`, `t_split`, etc.) used to bundle each test case's inputs and a descriptive label, so test cases can be organised as arrays of structs and looped over rather than written out one by one.
* Most `ft_*.c` files on this branch include their own `int main(void)` at the bottom, testing that specific function in isolation.
* Linked-list and _fd functions — since these are harder to test standalone (they rely on file descriptors or a full t_list chain), their tests live in separate dedicated .c files instead, each calling the relevant functions and printing results.
### Running the tests
Each test file can be compiled normally against the library, for example: `cc -Wall -Wextra -Werror ft_strlen.c libft.a`

For some files, compiling with the -lbsd flag will be helpful as I use strlcpy.
