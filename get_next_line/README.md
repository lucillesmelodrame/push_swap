*This project has been created as part of the 42 curriculum by sonfong.*

## Description
This project involves students to make our own implementation of the function `get_next_line`, which returns a line read from a file descriptor, and can be included in our [libft](https://github.com/lucillesmelodrame/libft) project once completed.

It aims for students to learn about and familiarise with file descriptors, how `read()` works, static variables and careful memory management.

## Instructions
This project does not require a Makefile. When testing with a `main.c` file, include the header `get_next_line.h` and compile with `cc -Wall -Wextra -Werror`, the `-D BUFFER_SIZE=n` flag, and the source files.

Example: `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c`  

*`BUFFER_SIZE` is the number of bytes each `read()` call fetches. If the `-D BUFFER_SIZE=n` flag is not given, it defaults to `42`, which is defined in `get_next_line.h`.*

`get_next_line(fd)` is meant to be called in a loop until it returns `NULL`. The caller must `free` every line it receives.

## Resources
This function was implemented using resources such as:
* [Medium (LAnnur-S)](https://medium.com/@lannur-s/gnl-c3cff1ee552b) — an article guiding step-by-step on how to implement `get_next_line`
* [DEV.to (Aymen Errfig)](https://dev.to/aerrfig/get-next-line-a-42-project-to-learn-how-to-deal-with-file-descriptors-and-io-of-system-3652) — helped in understanding more of file descriptors and how read() works
* [Gitbook](https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line) — MY LIBFT SAVIOUR !! broke down the functions i could use to implement `get_next_line`
* [42 Docs](https://harm-smits.github.io/42docs/projects/get_next_line) — helped me understand how get_next_line should be implemented
* `man` pages — to understand the concept of read().
* [Python Tutor](https://pythontutor.com/visualize.html#mode=edit) — to help with visualisation of difficult problems.
* My own peers on campus !! ٩(^ᗜ^ )و ´-⁾⁾**#shoutout to my uni friends who witnessedme crashout over this project (╯` ᴖ ´）╯︵┻━┻**
### AI usage
AI was not used as source for solutions but only used for research for concepts and questions that could not be easily found from the resources mentioned above, and provided extra guidance.

## Details
### Algorithm & data structure
My interpretation of `get_next_line` itself is a loop that reads the file descriptor in chunks of `BUFFER_SIZE` bytes into a static `stash` until `stash` contains a `\n` (or the file ends), and then splits `stash` into the line to return and the leftover tail that is kept for the next call.
 
`get_next_line.c` contains `get_next_line`. All the helper functions are in `get_next_line_utils.c`, as required by the subject.
 
* `get_next_line` — returns the next line read from `fd`, including its `\n` unless it is the last line of a file that does not end with one. Returns `NULL` if there is nothing left to read or if an error occurred.
* `read_to_stash` — reads from `fd` into a temporary buffer of `BUFFER_SIZE` bytes and appends it to `stash`, until `stash` contains a `\n` or there is nothing left to read. Returns the updated `stash`, or `NULL` if an error occurred.
* `my_strjoin` — returns a newly allocated string made of `s1` followed by the first `len` bytes of `s2`. It frees `s1`, including when its own allocation fails, so the old block can never be lost.
* `find_newline` — returns a pointer to the first `\n` in a string, or `NULL` if there is none (or if the string is `NULL`).
* `my_strdup` — returns a pointer to a newly allocated copy of a string.
* `my_strlen` — returns the number of characters in a string, excluding the NUL terminator. Returns 0 for `NULL`.

**The static `stash`**
 
`stash` holds what has been read from the file descriptor but not yet returned. For example, after `"hello\n"` is returned from `"hello\nwo"`, `stash` holds `"wo"`.
 
* *A `malloc`'d block survives when a function returns, but a local variable would lose the pointer to it. The block would still exist with nobody able to reach it (a memory leak), and the leftover text would be gone. A static pointer keeps the address it points to between calls, so the next call can still find the block.*
* *Whenever that block is freed, the static pointer must be set to `NULL`. Otherwise it would point to freed memory (a dangling pointer), and using it is undefined behavior: it can crash or silently read garbage.*

**Reading until a newline**
 
In `read_to_stash`, a new chunk is read into `buf` and `my_strjoin` joins the old `stash` and the new chunk together. `my_strjoin` allocates a brand-new larger block, copies both into it and frees the old `stash`, and the new block becomes `stash`.
 
The loop is `while (ret > 0 && !find_newline(stash))`, so it keeps going while both are true and stops as soon as either one fails:
* *`stash` already contains a `\n`. If the leftover from the previous call already holds a full line, the loop does not run at all, so no `read()` happens.*
* *`read()` returns 0, which means the end of the file. `ret` is set to 1 before the loop so the first check lets it start.*

Errors leave through the `if (ret == -1 || !stash)` inside the loop: either `read()` returned `-1`, or the `malloc` in `my_strjoin` failed. `if (!buf)` covers the `malloc` of `buf`. Each of them frees what it owns and returns `NULL`.
 
**Returning the line**
 
When `read_to_stash` returns, `stash` holds a complete line and maybe some leftover text. `get_next_line` splits it. For `stash = "hello\nwo"`:
 
```c
n1 = find_newline(stash);   // n1 points at the '\n'
line = stash;               // line and stash point to the same block
stash = my_strdup(n1 + 1);  // copies the tail "wo" into a new block, which stash now points to
n1[1] = '\0';               // cuts the old block right after the '\n'
return (line);              // the old block now reads "hello\n"
```
 
* *The order matters: `n1[1]` is the first character of the tail, so cutting the block before copying the tail would destroy it.*
* *`line` is not freed in `get_next_line` because it is returned to the caller. If it were freed before returning, the caller would receive a dangling pointer.*

**The last line without a `\n`**
 
For a file that ends with `world` and no `\n`, `read_to_stash` reads until `read()` returns 0, so `stash` is `"world"` and `find_newline` returns `NULL`. In `get_next_line`, `if (!n1)` sets `n1 = stash + my_strlen(stash) - 1`, which points at the last character. Then `my_strdup(n1 + 1)` copies the terminator position, which is an empty string, and `n1[1] = '\0'` rewrites a `'\0'` that was already there. The line comes back as `"world"` with no `\n`, and `stash` is `""`.
 
On the next call, `read_to_stash` gets `""` and `read()` returns 0. Back in `get_next_line`, the first check `if (!stash || stash[0] == '\0')` frees it, sets `stash = NULL` (a static variable keeps its value between calls) and returns `NULL`. That same check is what makes an empty file return `NULL`.
 
**Who frees what**
* *The caller frees every line it receives (`free(line)` in `main`).*
* *`my_strjoin` frees the old `stash`, at the end and in its `if (!str)` branch where its own `malloc` failed.*
* *`read_to_stash` frees `buf` at the end. On errors it frees `stash` and `buf` (`ret == -1` or `!stash`), or only `stash` if `buf` could not be allocated.*
* *`get_next_line` frees `stash` and sets it to `NULL` when there is nothing left (end of file or empty input). If `my_strdup` fails to copy the tail, it frees `line`.*
* *If the caller stops reading before the end of the file, the leftover text stays in the static `stash` and the program cannot free it. The static pointer still points to it, and the OS reclaims it when the process exits.*

**`BUFFER_SIZE`**
 
`read()` reads up to `BUFFER_SIZE` bytes from the file descriptor into `buf`. The output is the same for any size because the loop never assumes that a chunk ends where a line ends: everything read after the `\n` simply stays in `stash` for the next call. The size only changes how many rounds the loop needs. `get_next_line` does not read until the end of the file, it only reads until `stash` contains a `\n`.

**Why this design**

* *A static `stash`: the text that has been read but not yet returned has to survive between calls, and it has nowhere else to go. Global variables are forbidden, `read()` cannot give back bytes it has already taken, `lseek` is forbidden so the file cannot be re-read, and the prototype `char *get_next_line(int fd)` has no parameter that lets the caller carry state. A static variable keeps its value between calls but can only be seen inside the function.*
* *Stopping at the first `\n`: the subject asks to read as little as possible and not to read the whole file first. It is also needed for standard input, because from a terminal `read()` only returns 0 when the input ends, so reading until the end of the file would block before the first line was ever returned.*
* *Returning the old `stash` block as the line, and copying only the tail: this avoids allocating and copying the line a second time. It needs one allocation fewer per call, and it also helped keep the functions within the Norm's limits.*
* *Joining with `my_strjoin`: only `read`, `malloc` and `free` are allowed, so there is no `realloc`, and growing `stash` means allocating a new block and copying. I chose this because it is simple and needs no extra bookkeeping (like a separate length or capacity) while keeping within five functions and 25 lines per function. The trade-off is the speed cost explained in Limitations.*
* *`my_strjoin` frees the old `stash` itself, so the old block cannot be lost when the pointer is replaced, and `read_to_stash` stays short.*

### Limitations ( ;´ - `;)
In `read_to_stash`, every round `find_newline(stash)` scans `stash` again from index 0, and `my_strjoin` measures the old `stash` with `my_strlen`, allocates a new block and copies all of it. So the work per round grows with the length of `stash`, and with `BUFFER_SIZE=1` this happens once per character.  
Therefore, reading a very long line with a small `BUFFER_SIZE` is slow, and doubling the length of the line makes it about four times slower.

`get_next_line` has a similar cost: `my_strdup(n1 + 1)` copies the whole leftover text on every call. With a `BUFFER_SIZE` as big as the file, the leftover is the entire rest of the file, so a file with many short lines is also slow.

The function still works, and all the tests are correct, only the speed suffers in these cases. (´∀｀；)

The static `stash` also keeps the leftover text if the caller stops reading before the end of the file. The function cannot free it by itself, because it cannot know that the caller is done, and the OS reclaims it when the process exits.