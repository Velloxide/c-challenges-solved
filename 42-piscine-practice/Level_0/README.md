<div align="center">

# Level 0 - Fundamentals

*Basic I/O & Command-Line Foundations*

[![Difficulty](https://img.shields.io/badge/Difficulty-Beginner-brightgreen?style=flat-square)]()
[![Status](https://img.shields.io/badge/Status-Complete-success?style=flat-square)]()
[![Exercises](https://img.shields.io/badge/Exercises-11/11-blue?style=flat-square)]()
[![Progress](https://img.shields.io/badge/Progress-100%25-success?style=flat-square)]()

</div>

---

## 📋 Overview

Level 0 focuses on the absolute fundamentals of C programming. These exercises build a solid foundation in basic I/O operations, character manipulation, and understanding how programs interact with the command line.

**Focus Areas:** Basic Output | Character Operations | Command-Line Arguments

---

## 📚 Exercise Catalog

### Complete List (11 Exercises)

<details open>
<summary><b>📝 Basic Output (4 exercises)</b></summary>

| Exercise | Description | Concepts |
|:---------|:------------|:---------|
| `aff_a.c` | Display the character 'a' | Basic output with write() |
| `aff_z.c` | Display the character 'z' | Basic output |
| `hello.c` | Display "Hello World!" | String output |
| `only_z.c` | Display only 'z' characters | Character filtering |

</details>

<details open>
<summary><b>🔢 Number Printing (2 exercises)</b></summary>

| Exercise | Description | Concepts |
|:---------|:------------|:---------|
| `ft_countdown.c` | Print countdown from 9 to 0 | Loops, digit output |
| `ft_print_numbers.c` | Print digits 0 to 9 | Loops, character conversion |

</details>

<details open>
<summary><b>📋 Command-Line Arguments (2 exercises)</b></summary>

| Exercise | Description | Concepts |
|:---------|:------------|:---------|
| `aff_first_param.c` | Display first command-line argument | argc/argv, parameter handling |
| `aff_last_param.c` | Display last command-line argument | Array indexing, argc |

</details>

<details open>
<summary><b>🔤 Alphabet Manipulation (3 exercises)</b></summary>

| Exercise | Description | Concepts |
|:---------|:------------|:---------|
| `maff_alpha.c` | Print alphabet (alternating case) | ASCII manipulation, loops |
| `maff_revalpha.c` | Print reverse alphabet (alternating) | Reverse iteration, case control |
| `only_a.c` | Display only 'a' from input | Character filtering |

</details>

---

## 🎯 Learning Objectives

### Technical Skills
- ✅ `write()` system call mastery
- ✅ Command-line argument handling
- ✅ Character operations & ASCII
- ✅ Loop control structures
- ✅ Basic string output

### Problem-Solving
- ✅ Understanding program structure
- ✅ Edge case handling (empty input)
- ✅ Clean code practices
- ✅ Following compilation standards

---

## 🛠️ Compilation & Testing

### Standard Compilation

```bash
gcc -Wall -Wextra -Werror exercise.c -o exercise
```

### Exercise Types

**1. Basic Output Programs** (aff_a, aff_z, hello)

```bash
gcc -Wall -Wextra -Werror hello.c -o hello
./hello
# Output: Hello World!
```

**Testing Tips:**
- Verify exact output
- Check for newline handling
- No extra spaces or characters

**2. Number Printing** (ft_countdown, ft_print_numbers)

```bash
gcc -Wall -Wextra -Werror ft_countdown.c -o ft_countdown
./ft_countdown
# Output: 9876543210

gcc -Wall -Wextra -Werror ft_print_numbers.c -o ft_print_numbers
./ft_print_numbers
# Output: 0123456789
```

**Testing Tips:**
- Check order is correct
- Verify newline at end
- No spaces between digits

**3. Command-Line Arguments** (aff_first_param, aff_last_param)

```bash
gcc -Wall -Wextra -Werror aff_first_param.c -o aff_first_param
./aff_first_param Hello World
# Output: Hello

./aff_first_param
# Output: (newline only)
```

**Testing Tips:**
- Test with no arguments
- Test with multiple arguments
- Test with empty strings
- Test with special characters

**4. Alphabet Manipulation** (maff_alpha, maff_revalpha)

```bash
gcc -Wall -Wextra -Werror maff_alpha.c -o maff_alpha
./maff_alpha
# Output: aBcDeFgHiJkLmNoPqRsTuVwXyZ

gcc -Wall -Wextra -Werror maff_revalpha.c -o maff_revalpha
./maff_revalpha
# Output: zYxWvUtSrQpOnMlKjIhGfEdCbA
```

**Testing Tips:**
- Verify case alternation
- Check alphabet order
- Confirm newline handling

---

## 💡 Key Concepts

### Using `write()` System Call

**Core Understanding:**
- `write()` is a low-level I/O function
- Format: `write(fd, buffer, count)`
- `fd = 1` for standard output

**Example:**
```c
#include <unistd.h>

write(1, "Hello", 5);  // Write 5 bytes to stdout
write(1, "\n", 1);     // Write newline
```

### Command-Line Arguments

**Essential Concepts:**
- `argc` = argument count
- `argv` = argument vector (array of strings)
- `argv[0]` = program name
- `argv[1]` = first argument

**Example:**
```c
int main(int argc, char **argv)
{
    if (argc > 1)
        // argv[1] is first argument
    return (0);
}
```

### Character & ASCII Operations

**Key Points:**
- Characters are numbers (ASCII values)
- `'0'` has ASCII value 48
- `'A'` = 65, `'a'` = 97
- Case conversion: `'A' + 32 = 'a'`

**Example:**
```c
char digit = 5 + '0';  // Convert 5 to '5' (ASCII 53)
char lower = 'A' + 32; // Convert 'A' to 'a'
```

---

## 📊 Complexity Analysis

| Exercise | Time | Space | Notes |
|:---------|:----:|:-----:|:------|
| aff_a | O(1) | O(1) | Single character output |
| hello | O(1) | O(1) | Fixed string output |
| ft_countdown | O(1) | O(1) | Fixed 10 iterations |
| ft_print_numbers | O(1) | O(1) | Fixed 10 iterations |
| aff_first_param | O(n) | O(1) | n = argument length |
| maff_alpha | O(1) | O(1) | Fixed 26 letters |

*n = string length*

---

## ✅ Quality Standards

| Standard | Status |
|:---------|:------:|
| No warnings with `-Wall -Wextra -Werror` | ✅ |
| 42 Norminette compliant | ✅ |
| Proper error handling | ✅ |
| Edge cases covered | ✅ |
| Clean, readable code | ✅ |

---

## 🎯 Common Patterns

### Pattern 1: Single Character Output

```c
#include <unistd.h>

int main(void)
{
    write(1, "a\n", 2);
    return (0);
}
```

### Pattern 2: Loop-Based Output

```c
#include <unistd.h>

int main(void)
{
    char c = '0';
    
    while (c <= '9')
    {
        write(1, &c, 1);
        c++;
    }
    write(1, "\n", 1);
    return (0);
}
```

### Pattern 3: Argument Handling

```c
#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    
    if (argc > 1)
    {
        while (argv[1][i])
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
```

---

## 🚀 Next Steps

After Level 0:
- **Level 1** → String functions & algorithms
- **Level 2** → Advanced string manipulation
- **Level 3** → Complex algorithms & data structures

---

## 💡 Tips for Success

### Study Strategies
1. **Understand `write()`**
   - Master the low-level I/O function
   - Know the three parameters
   - Practice with different outputs

2. **Practice ASCII**
   - Know how to convert numbers to characters
   - Understand character values
   - Learn case conversion tricks

3. **Test Edge Cases**
   - Empty strings
   - No arguments
   - Special characters
   - Boundary values

### Best Practices
1. **Start Simple**
   - Understand basics thoroughly
   - Don't rush to complex solutions
   - Build confidence gradually

2. **Read Man Pages**
   - `man write` for system calls
   - `man ascii` for character values
   - Understanding is key

3. **Debug Systematically**
   - Use printf for debugging
   - Check each step
   - Understand each error

---

## 📚 Resources

| Resource | Link |
|:---------|:----:|
| 🔗 write() System Call | [man7.org](https://man7.org/linux/man-pages/man2/write.2.html) |
| 🔗 ASCII Table | [asciitable.com](https://www.asciitable.com/) |
| 🔗 Command-Line Args | [cppreference.com](https://en.cppreference.com/w/c/language/main_function) |
| 🔗 C Basics | [learn-c.org](https://www.learn-c.org/) |

---

## 📄 Exercise Subjects

All exercise requirements and specifications:

📥 **[Download Level 0 Subjects (PDF)](level_0.pdf)**

---

## 🎉 Level 0 Complete!

**Congratulations!** You've built a strong foundation in C fundamentals.  
Ready for Level 1! 🚀

---

### Navigation

[⬆️ 42 Piscine](../README.md) | [➡️ Level 1](../level_1/README.md)

*Last Updated: October 2025*

</div>
