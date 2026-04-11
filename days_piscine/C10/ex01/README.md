# Project Tracking: ft_cat (C 10 - ex01)

## 🎯 Objective
Build a utility that replicates the behavior of the Linux `cat` command. It must read files passed as arguments and print them to the standard output, handle errors flawlessly, and read from standard input (`stdin`) if no arguments are provided. All of this must be achieved using a fixed-size array without dynamically allocating memory (`malloc` is forbidden).

## 📂 Architecture & File Structure
* **`Makefile`**: Contains the mandatory rules (`all`, `clean`, `fclean`) and links the object files to compile the `ft_cat` executable.
* **`ft.h`**: The header file containing prototypes for all functions to ensure clean compilation without implicit declaration warnings.
* **`ft_cat.c`**: The entry point containing the `main` function. It directs the program flow:
  * If `argc < 2`: It passes `fd = 0` to read directly from the keyboard (`stdin`).
  * Otherwise, it loops through each argument, attempting to `open` the files. 
  * It strictly separates the file opening check from the reading check to avoid corrupting the `errno` variable.
* **`ft_display_content.c`**: The reading engine. It utilizes a `29696`-byte array (strictly keeping it slightly under the 30ko limit required by the subject). It returns `-1` if the `read` function fails, which is the primary mechanism for catching directory errors.
* **`ft_err_handling.c`**: The error management system. It uses `basename` to extract the program's exact execution name and `strerror(errno)` to print an error message that perfectly matches the native OS behavior.
* **`ft_puterror.c` & `ft_putstr_size.c`**: Helper functions designed to calculate string lengths and print data to either `stdout` (fd 1) or `stderr` (fd 2).

## ⚠️ Engineered Solutions for Edge Cases (Gotchas)
1. **The Directory Trap (EISDIR):** The `open` system call actually succeeds when opening directories! To catch this, the logic relies on the return value of `read` inside the display engine. If `read` returns `-1`, the program identifies the directory error and prints the correct message.
2. **The EBADF Trap (Bad File Descriptor):** If `open` fails (returns `-1`), passing that `-1` to `read` or `close` will prompt the OS to overwrite the original `errno` (e.g., "No such file") with a new error ("Bad file descriptor"). The architecture safely isolates the `-1` to prevent this corruption.
3. **The Sudden Exit Trap:** The authentic `cat` command does not die if a single file fails. Instead of using `return (1)` upon encountering an error, the program prints the error message and gracefully continues the loop to process the remaining files.

## 🚀 Usage
```bash
make
./ft_cat file1.txt file2.txt # Reads and concatenates multiple files
./ft_cat test_dir/           # Prints the directory error and continues
./ft_cat                     # Hangs, waiting for keyboard input (exit with Ctrl+D)
