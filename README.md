*This project has been created as part of the 42 curriculum by arsierra and uelizegi.*

# minishell

A minimal shell implementation written in C as part of the 42 curriculum.
The goal of this project is to reproduce the core behavior of `bash` while strictly following the subject requirements, without aiming for a byte-to-byte clone.

---

## Description

The project focuses on understanding how a Unix shell works internally, including
process creation, pipes, redirections, parsing, and environment handling.

It provides a functional command interpreter capable of executing programs,
handling pipelines, managing signals, and expanding environment variables.

---

## Features

### Command execution
- Execution of external commands (`ls`, `cat`, etc.)
- PATH resolution
- Proper use of `fork`, `execve`, and `wait`

### Pipes
- Support for single and multiple pipelines (`|`)
- Correct process and file descriptor management

### Redirections
- Input redirection `<`
- Output redirection `>`
- Append mode `>>`
- Heredoc `<<`

### Expansions
- Environment variables (`$HOME`, `$PATH`, etc.)
- `$?` expansion
- Concatenations (`hello$HOME`, `a"$HOME"b`)
- Correct quote handling

### Parser & lexer
- Tokenization of operators (`|`, `<`, `>`, `<<`, `>>`)
- Syntax error detection
- Unclosed quotes handling

### Signals & errors
- Handling of `Ctrl+C`, `Ctrl+D`, `Ctrl+\`
- Proper exit status management
- Clean program termination

---

## Instructions

### Compilation

`make`

## Run

./minishell

## Memory check

valgrind \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-fds=yes \
  --suppressions=readline.supp \
  ./minishell

## Resources

### Documentation
- 42 minishell subject
- man pages
- GNU Bash documentation

## AI usage
AI tools were used for:
- Concept clarification
- Reviewing design decisions
- Improving documentation

All implementation decisions and code were fully understood and validated by the authors.

## Authors
- arsierra
- uelizegi
