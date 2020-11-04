# Lab Assignments for ICS4211: Compiler Construction

## Table of Contents
- [Lab One](#lab-one)
- [Lab Two](#lab-two)

## Lab One
__Activity__: Designing a simple lexical analyzer

__Bonus__: Use Flex to automatically create the lexer

---

The progam is in [SimpleLexer.cpp](Lab_One/SimpleLexer.cpp). It tokenizes sample code from [Program.txt](Lab_One/Pogram.txt).

You can run the already compiled executable file `SimpleLexer.exe`. The code was compiled on a Windows machine, if the executable errors, compile it using your system's C++ compiler, such as g++.

`simple_lexer.l` is a Flex file describing a similar lexer to the one in `SimpleLexer.cpp`. Incase you want to create a new executable of the Flex lexer, run:
```bash
gcc lex.yy.c
```

To demonstrate the tokenization run:
```bash
./a program.txt
```

<br/>

## Lab Two
__Activity__: Describe the output of a scanner

__Bonus__: Download and use Flex in any way

---

For this lab, it used a lexer defined using Flex as described in `lexer.l`.

To create a new executable of the lexer code:
```bash
gcc lex.yy.c
```

To show the description of the output from the scanner:
```bash
./a program.txt
```

A snippet of the output:
```
A keyword: function 
An identifier: compare_strings 
A symbol: ( 
An identifier: str_1 
A separator symbol: , 
An identifier: str_2 
A symbol: ) 
```

__The output explained:__

The snippet is from the piece of code in `function compare_strings(str_1, str_2)`. The scanner has identified several tokens based on regex rules defined in the lexer file. For instance, a valid identifier in this program is all lowercase letters and can include _ (underscore). The defined regex in the lexer is `[a-z_][a-z0-9_]*`
