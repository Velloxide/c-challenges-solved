<div align="center">

# Level 1 - Core Concepts

*String Operations & Algorithm Foundations*

[![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-orange?style=flat-square)]()
[![Status](https://img.shields.io/badge/Status-Complete-success?style=flat-square)]()
[![Exercises](https://img.shields.io/badge/Exercises-23/23-blue?style=flat-square)]()
[![Progress](https://img.shields.io/badge/Progress-100%25-success?style=flat-square)]()

</div>

---

## 📋 Overview

Level 1 builds upon Level 0 fundamentals and introduces **string manipulation**, **algorithm implementation**, and **cipher techniques**. This level emphasizes understanding pointers, recreating standard library functions, and exploring multiple solution approaches.

**Focus Areas:** String Functions | Algorithms | Ciphers | Pointers

---

## 📚 Exercise Catalog

### Complete List (23 Exercises)

<details open>
<summary><b>🔤 String Functions (6 exercises)</b></summary>

| Exercise | Description | Concepts |
|:---------|:------------|:---------|
| `first_word.c` | Extract first word from string | String parsing, whitespace |
| `ft_putstr.c` | Implement string output | String iteration, write() |
| `ft_strcpy.c` | Implement string copy | Pointers, string manipulation |
| `ft_strlen.c` | Implement string length | Pointer arithmetic |
| `search_and_replace.c` (md_1) | Replace character in string | Character search & replace |
| `search_and_replace.c` (md_2) | Alternative implementation | Different approach |

</details>

<details open>
<summary><b>🎲 Algorithms (2 exercises)</b></summary>

| Exercise | Description | Concepts |
|:---------|:------------|:---------|
| `fizzbuzz.c` | Classic FizzBuzz algorithm | Conditionals, modulo |
| `ft_swap.c` | Swap two integers | Pointers, pass-by-reference |

</details>

<details open>
<summary><b>🔐 Ciphers (8 exercises)</b></summary>

| Exercise | Description | Concepts |
|:---------|:------------|:---------|
| `rot_13.c` (md_1) | ROT13 cipher - Method 1 | Character rotation |
| `rot_13.c` (md_2) | ROT13 cipher - Method 2 | Alternative approach |
| `rotone.c` (md_1) | ROT1 cipher - Method 1 | Character shifting |
| `rotone.c` (md_2) | ROT1 cipher - Method 2 | Different implementation |
| `rotone.c` (md_3) | ROT1 cipher - Method 3 | Third approach |
| `ulstr.c` (md_1) | Toggle case - Method 1 | Case manipulation |
| `ulstr.c` (md_2) | Toggle case - Method 2 | Alternative method |
| `ulstr.c` (md_3) | Toggle case - Method 3 | Third variant |

</details>

<details open>
<summary><b>🔄 String Manipulation (9 exercises)</b></summary>

| Exercise | Description | Concepts |
|:---------|:------------|:---------|
| `repeat_alpha.c` (md_1) | Repeat alphabet chars - Method 1 | Character repetition |
| `repeat_alpha.c` (md_2) | Repeat alphabet chars - Method 2 | Alternative logic |
| `repeat_alpha.c` (md_3) | Repeat alphabet chars - Method 3 | Third approach |
| `rev_print.c` (md_1) | Reverse print - Method 1 | String reversal |
| `rev_print.c` (md_2) | Reverse print - Method 2 | Different reversal |
| `rev_print.c` (md_3) | Reverse print - Method 3 | Third method |
| (3 more variations across different exercises) | | |

</details>

---

## 🎯 Learning Objectives

### Technical Skills
- ✅ String manipulation mastery
- ✅ Pointer operations & memory management
- ✅ Standard library function recreation
- ✅ Cipher algorithm implementation
- ✅ Multiple solution approaches

### Problem-Solving
- ✅ Algorithm design patterns
- ✅ Edge case handling
- ✅ Code optimization techniques
- ✅ Debugging strategies
- ✅ Testing methodologies

---

## 🛠️ Compilation & Testing

### Standard Compilation

```bash
gcc -Wall -Wextra -Werror exercise.c -o exercise
```

### Exercise Types

**1. Function Implementations** (ft_strlen, ft_strcpy, ft_putstr, ft_swap)

These implement functions without a main. Create your own test file:

```bash
gcc -Wall -Wextra -Werror ft_strlen.c test_main.c -o test
./test
```

**Testing Tips:**
- Test empty strings: `""`
- Test normal cases: `"Hello"`
- Test edge cases: long strings, NULL
- Compare with standard library

**2. Command-Line Programs** (first_word, rot_13, rotone, etc.)

```bash
gcc -Wall -Wextra -Werror first_word.c -o first_word
./first_word "Hello World"
./first_word "   spaces"
```

**Testing Tips:**
- Test with no arguments
- Test with empty string
- Test special characters
- Test boundary conditions

**3. Standalone Programs** (fizzbuzz)

```bash
gcc -Wall -Wextra -Werror fizzbuzz.c -o fizzbuzz
./fizzbuzz
```

---

## 💡 Key Concepts

### String Operations

**Core Understanding:**
- Strings are null-terminated: `"Hi"` → `['H','i','\0']`
- Always check for `\0`
- Mind buffer boundaries

**Common Pattern:**
```c
while (str[i])
    i++;
```

### Pointers

**Essential Concepts:**
- `int *ptr` → pointer to integer
- `*ptr` → dereference (get value)
- `&var` → get address
- Pass-by-reference enables modification

**Example:**
```c
void ft_swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

### Cipher Algorithms

**ROT13:** Rotate by 13 positions
- Encryption = Decryption
- `A → N`, `N → A`

**ROT1:** Rotate by 1 position
- Simple Caesar cipher
- `a → b`, `z → a`

---

## 📊 Complexity Analysis

| Exercise | Time | Space | Notes |
|:---------|:----:|:-----:|:------|
| ft_strlen | O(n) | O(1) | Linear scan |
| ft_strcpy | O(n) | O(1) | Single pass |
| ft_swap | O(1) | O(1) | Constant |
| fizzbuzz | O(1) | O(1) | Fixed 100 iterations |
| repeat_alpha | O(n·m) | O(1) | m = repetition count |
| rot_13 | O(n) | O(1) | Single pass |
| search_replace | O(n) | O(1) | Single pass |

*n = string length*

---

## ✅ Quality Standards

| Standard | Status |
|:---------|:------:|
| No warnings with `-Wall -Wextra -Werror` | ✅ |
| 42 Norminette compliant | ✅ |
| Memory leak free | ✅ |
| Edge cases handled | ✅ |
| Multiple test scenarios | ✅ |

---

## 🎯 Multiple Solutions Philosophy

**Why 3 methods (md_1, md_2, md_3)?**

Each method demonstrates different approaches:
- **Method 1:** Usually most straightforward
- **Method 2:** Alternative logic or optimization
- **Method 3:** Different perspective

**Benefits:**
- 🧠 No single "right" way
- ⚡ Compare efficiency
- 🎓 Learn different strategies
- 🔄 Practice refactoring

---

## 🚀 Next Steps

After Level 1:
- **Level 2** → Complex algorithms & data manipulation
- **Level 3** → Advanced concepts & recursion
- **Beyond** → Data structures & system programming

---

## 💡 Tips for Success

### Study Strategies
1. **Understand Before Coding**
   - Read requirements carefully
   - Plan your approach
   - Consider edge cases

2. **Test Thoroughly**
   - Create comprehensive tests
   - Try boundary values
   - Check error conditions

### Optimization Tips
1. **Compare Your Methods**
   - Study md_1, md_2, md_3
   - Which is more efficient?
   - Which is more readable?

2. **Learn from Mistakes**
   - Debug systematically
   - Use printf/gdb
   - Understand each error

---

## 📚 Resources

| Resource | Link |
|:---------|:----:|
| 🔗 Pointers in C | [cppreference.com](https://en.cppreference.com/w/c/language/pointer) |
| 🔗 String Functions | [cppreference.com](https://en.cppreference.com/w/c/string/byte) |
| 🔗 Caesar Cipher | [Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher) |
| 🔗 ROT13 | [Wikipedia](https://en.wikipedia.org/wiki/ROT13) |
| 🔗 FizzBuzz | [Wikipedia](https://en.wikipedia.org/wiki/Fizz_buzz) |

---

## 📄 Exercise Subjects

All exercise requirements and specifications:

📥 **[Download Level 1 Subjects (PDF)](level_1.pdf)**

---

## 🎉 Level 1 Complete!

You now have a solid foundation in string manipulation, pointers, and algorithms.  
Ready for Level 2! 💪

---

### Navigation

[⬅️ Level 0](../level_0/README.md) | [⬆️ 42 Piscine](../README.md) | [➡️ Level 2](../level_2/)

*Last Updated: October 2025*

</div>
