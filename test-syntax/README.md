# Syntax Testing Files

This directory contains comprehensive syntax test files for various programming languages to help you test and validate your Modern Zed Theme's syntax highlighting.

## Overview

Each file demonstrates a wide range of syntax elements for its respective programming language, including:

- **Keywords** (if, for, while, class, function, etc.)
- **Data types** (primitives, collections, custom types)
- **Strings** (literals, templates, raw strings, escape sequences)
- **Numbers** (integers, floats, hex, binary, scientific notation)
- **Comments** (single-line, multi-line, documentation)
- **Functions** (declarations, calls, lambdas, closures)
- **Control structures** (loops, conditionals, exception handling)
- **Classes and objects** (inheritance, polymorphism, interfaces)
- **Modern language features** (generics, async/await, pattern matching)
- **Operators** (arithmetic, logical, bitwise, comparison)
- **Variables** (declarations, assignments, scope modifiers)

## Files Included

| Language   | File          | Description                                    |
|------------|---------------|------------------------------------------------|
| Rust       | `test.rs`     | Comprehensive Rust syntax with modern features|
| Go         | `test.go`     | Go syntax including goroutines and channels   |
| Python     | `test.py`     | Python with type hints and modern features    |
| JavaScript | `test.js`     | Modern JavaScript/ES6+ with async/await       |
| Java       | `Test.java`   | Java with recent language features            |
| C++        | `test.cpp`    | Modern C++ with templates and STL             |
| C          | `test.c`      | C syntax with various standards (C99, C11)    |

## How to Test Your Theme

### Method 1: Open Individual Files
1. Open Zed
2. Navigate to this directory (`modern-zed-theme/test-syntax/`)
3. Open any of the test files (e.g., `test.rs`, `test.py`, etc.)
4. Switch between your theme variants:
   - **Cmd + Shift + P** → "theme selector: toggle"
   - Or go to Settings → Theme

### Method 2: Open Multiple Files
1. Open the entire `test-syntax` directory as a project in Zed
2. Use the file explorer to quickly switch between different language files
3. Test both light and dark theme variants

### Method 3: Split View Testing
1. Open two different language files
2. Use **Cmd + \\** (macOS) to split the editor
3. Compare syntax highlighting across languages side-by-side

## What to Look For

When testing your theme, pay attention to:

### ✅ **Good Syntax Highlighting Should Have:**
- **Distinct colors** for different syntax elements
- **Good contrast** between text and background
- **Consistent styling** across similar elements in different languages
- **Readable comments** (usually muted/grayed out)
- **Prominent keywords** that stand out from regular text
- **Clear string highlighting** with escape sequence visibility
- **Distinguishable numbers** from text
- **Visible function/method names**
- **Appropriate error/warning colors**

### ⚠️ **Common Issues to Watch For:**
- Colors that are too similar (poor distinction)
- Text that's hard to read due to low contrast
- Inconsistent highlighting between languages
- Missing syntax highlighting for certain elements
- Colors that strain the eyes

## Testing Checklist

- [ ] **Keywords** are clearly highlighted and distinct
- [ ] **Strings** have appropriate colors and escape sequences are visible
- [ ] **Comments** are muted but still readable
- [ ] **Numbers** stand out from regular text
- [ ] **Functions/methods** are clearly identifiable
- [ ] **Types/classes** have distinct styling
- [ ] **Variables** are appropriately colored
- [ ] **Operators** are visible and clear
- [ ] **Both light and dark variants** work well
- [ ] **Different file types** have consistent styling
- [ ] **Long code blocks** remain readable
- [ ] **Nested structures** (brackets, braces) are clear

## Making Adjustments

If you find issues with the syntax highlighting:

1. **Edit your theme**: Modify `themes/modern-zed.json`
2. **Reload the theme**: **Cmd + Shift + P** → "zed: reload extensions"
3. **Test again**: Re-open the syntax test files to see changes
4. **Iterate**: Repeat until you're satisfied with the highlighting

## Syntax Element Reference

### Common syntax categories to test:
- `keyword` - if, for, while, class, function, etc.
- `string` - "text", 'text', `template`, r"raw"
- `string.escape` - \n, \t, \", \\, etc.
- `comment` - // single line, /* multi line */
- `comment.doc` - /// doc comments, /** JSDoc */
- `number` - 42, 3.14, 0xFF, 1e10
- `boolean` - true, false
- `constant` - CONSTANTS, final values
- `function` - function names and calls
- `variable` - variable names
- `type` - int, String, custom types
- `property` - object.property
- `constructor` - new ClassName()
- `tag` - HTML/XML tags (in supported contexts)
- `attribute` - HTML attributes, decorators
- `embedded` - code within other code (SQL in strings, etc.)

## Tips for Theme Development

1. **Start with one language** and get it right before testing others
2. **Use high contrast** for better readability
3. **Test in different lighting conditions** (bright room, dark room)
4. **Consider accessibility** - avoid red/green combinations for colorblind users
5. **Keep it simple** - too many colors can be distracting
6. **Be consistent** - similar elements should have similar colors across languages

Happy theme testing!
