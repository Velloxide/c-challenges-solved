<div align="center">

# Level 2 - Advanced Manipulation

*Data Processing & String Algorithms*

[![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate%2B-orange?style=flat-square)]()
[![Status](https://img.shields.io/badge/Status-In%20Progress-yellow?style=flat-square)]()
[![Exercises](https://img.shields.io/badge/Exercises-9-blue?style=flat-square)]()
[![Progress](https://img.shields.io/badge/Progress-60%25-yellow?style=flat-square)]()

</div>

---

## 📋 Overview

Level 2 introduces more advanced data manipulation, complex string algorithms, and mathematical operations. These exercises build upon string fundamentals and require deeper understanding of algorithm design and data processing.

**Focus Areas:** String Comparison | Number Conversion | Character Operations | String Functions

---

## 📚 Exercise Catalog

### Complete List (9 Exercises)

<details open>
<summary><b>🔤 String Comparison & Search (4 exercises)</b></summary>

| Exercise | Description | Methods | Concepts |
|:---------|:------------|:-------:|:---------|
| `ft_strcmp.c` | String comparison | 2 | Character-by-character comparison |
| `ft_strcspn.c` | Complement span of charset | 2 | Character search in set |
| `ft_strpbrk.c` | Locate character in string | 2 | Pointer to first match |
| `ft_strspn.c` | Get span of charset | 1 | Count matching characters |

</details>

<details open>
<summary><b>🔧 String Manipulation (2 exercises)</b></summary>

| Exercise | Description | Methods | Concepts |
|:---------|:------------|:-------:|:---------|
| `ft_strrev.c` | Reverse string in-place | 1 | String reversal, pointers |
| `ft_strdup.c` | Duplicate string | 1 | Memory allocation, string copy |

</details>

<details open>
<summary><b>🔢 Number Conversion (2 exercises)</b></summary>

| Exercise | Description | Methods | Concepts |
|:---------|:------------|:-------:|:---------|
| `ft_atoi.c` | ASCII to integer | 2 | String to number conversion |
| `do_op.c` | Calculator operations | 2 | Operator handling |

</details>

<details open>
<summary><b>🪞 Character Transformation (1 exercise)</b></summary>

| Exercise | Description | Methods | Concepts |
|:---------|:------------|:-------:|:---------|
| `alpha_mirror.c` | Mirror alphabet | 4 | Character transformation |

</details>

---

## 🎯 Learning Objectives

### Technical Skills
- ✅ Advanced string comparison algorithms
- ✅ String search and span functions
- ✅ Dynamic memory allocation
- ✅ Number parsing and conversion
- ✅ Character transformation techniques
- ✅ In-place string manipulation

### Problem-Solving
- ✅ Efficient string processing
- ✅ Memory management strategies
- ✅ Numeric parsing logic
- ✅ Multiple algorithm approaches
- ✅ Edge case management

---

## 🛠️ Compilation & Testing

### Standard Compilation

```bash
gcc -Wall -Wextra -Werror exercise.c -o exercise
```

### Exercise Types

**1. String Comparison Functions** (ft_strcmp, ft_strcspn, ft_strpbrk, ft_strspn)

```bash
gcc -Wall -Wextra -Werror ft_strcmp.c test_main.c -o test_strcmp
./test_strcmp
```

**Testing Tips:**
- Test equal strings
- Test different strings
- Test empty strings
- Test with special characters
- Test NULL cases

**2. String Manipulation** (ft_strrev, ft_strdup)

```bash
gcc -Wall -Wextra -Werror ft_strdup.c test_main.c -o test_strdup
./test_strdup
```

**Testing Tips:**
- `ft_strdup`: Test memory allocation, verify copy
- `ft_strrev`: Test in-place reversal
- Always free allocated memory
- Test with empty strings

**3. Number Conversion** (ft_atoi)

```bash
gcc -Wall -Wextra -Werror ft_atoi.c test_main.c -o test_atoi
./test_atoi
```

**Testing Tips:**
- Positive numbers: `"123"` → 123
- Negative numbers: `"-456"` → -456
- With spaces: `"  789"` → 789
- Invalid input: `"abc"` → 0

**4. Operator Functions** (do_op)

```bash
gcc -Wall -Wextra -Werror do_op.c -o do_op
./do_op 10 + 5
# Output: 15
```

**Testing Tips:**
- Test all operators: +, -, *, /, %
- Division by zero handling
- Negative numbers
- Invalid operators

**5. Character Transformation** (alpha_mirror)

```bash
gcc -Wall -Wextra -Werror alpha_mirror.c -o alpha_mirror
./alpha_mirror "abc"
# Output: zyx
```

**Testing Tips:**
- Lowercase: `"abc"` → `"zyx"`
- Uppercase: `"ABC"` → `"ZYX"`
- Mixed case and numbers
- Non-alphabetic characters

---

## 💡 Key Concepts

### String Comparison

**ft_strcmp:**
```c
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}
```

### String Search Functions

**ft_strcspn:** Length of initial segment not containing charset
**ft_strpbrk:** Find first occurrence of any character from set
**ft_strspn:** Length of initial segment containing only charset

### Memory Allocation

**ft_strdup:**
```c
char *ft_strdup(char *src)
{
    char *dup;
    int len = 0;
    
    while (src[len])
        len++;
    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    // Copy and return
}
```

### Number Parsing

**ft_atoi:**
- Skip whitespace
- Handle sign
- Convert digits
- Stop at non-digit

### Character Transformation

**alpha_mirror:**
- Mirror: `a ↔ z`, `b ↔ y`
- Formula: `'z' - (char - 'a')`
- Preserve case and non-letters

---

## 📊 Complexity Analysis

| Exercise | Time | Space | Notes |
|:---------|:----:|:-----:|:------|
| ft_strcmp | O(n) | O(1) | Linear comparison |
| ft_strcspn | O(n·m) | O(1) | n=str, m=charset |
| ft_strpbrk | O(n·m) | O(1) | Search in set |
| ft_strspn | O(n·m) | O(1) | Count matches |
| ft_strrev | O(n) | O(1) | In-place reversal |
| ft_strdup | O(n) | O(n) | Allocates new string |
| ft_atoi | O(n) | O(1) | Single pass |
| do_op | O(1) | O(1) | Constant operations |
| alpha_mirror | O(n) | O(1) | Single pass |

*n = string length, m = charset length*

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

**Why Multiple Methods?**

Each method demonstrates different approaches:
- **Method 1:** Usually most straightforward
- **Method 2:** Alternative logic or optimization
- **Method 3+:** Different perspectives

**Benefits:**
- Compare efficiency
- Learn different strategies
- Practice refactoring
- Understand trade-offs

---

## 🚀 Next Steps

After Level 2:
- **Level 3** → Advanced algorithms & recursion
- **Level 4** → List operations & complex data
- **Level 5** → Advanced structures & final challenges

---

## 💡 Tips for Success

### Study Strategies
1. **Understand Memory Management**
   - malloc/free usage
   - Avoid memory leaks
   - Test with valgrind

2. **Compare Implementations**
   - Study all methods
   - Which is clearest?
   - Which is most efficient?

3. **Test Thoroughly**
   - Create comprehensive tests
   - Try boundary values
   - Check error conditions

### Best Practices
1. **Master String Functions**
   - Understand standard library
   - Recreate from scratch
   - Compare your implementation

2. **Optimize Code**
   - Measure performance
   - Compare approaches
   - Document learnings

---

## 📚 Resources

| Resource | Link |
|:---------|:----:|
| String Functions | [cppreference.com](https://en.cppreference.com/w/c/string/byte) |
| Memory Management | [cppreference.com](https://en.cppreference.com/w/c/memory) |
| Algorithm Analysis | [wikipedia.org](https://en.wikipedia.org/wiki/Algorithm) |
| Number Parsing | [cppreference.com](https://en.cppreference.com/w/c/string/byte/atoi) |

---

<div align="center">

## Level 2 In Progress

You're tackling more complex challenges.  
Keep practicing and refining your skills!

---

### Navigation

[⬅️ Level 1](../level_1/README.md) | [⬆️ 42 Piscine](../README.md) | [➡️ Level 3](../level_3/)

*Last Updated: October 2025*

</div>
