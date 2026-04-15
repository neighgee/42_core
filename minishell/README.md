*This project has been created as part of the 42 curriculum by mwin, smariapp.*

# Minishell

## Description
Minishell is a small Unix-like shell written in C, built to match the 42 subject's
mandatory requirements. It displays a prompt, keeps history, resolves commands
via PATH or absolute/relative paths, and runs them with correct process and signal
handling. It supports quotes, environment expansion (including `$?`), pipes, and
redirections (`<`, `>`, `<<`, `>>`), and implements the required builtins (`echo -n`,
`cd`, `pwd`, `export`, `unset`, `env`, `exit`). The project emphasizes parsing,
file-descriptor management, and Bash-like interactive behavior for `Ctrl-C/D/\\`.

## Instructions
### Build
```bash
make
```

### Rebuild
```bash
make re
```

### Run
```bash
./minishell
```

### Clean
```bash
make clean
make fclean
```

### Notes
- This project uses `readline`, so the library must be available on your system.
- Builtins implemented include: `cd`, `echo`, `env`, `export`, `pwd`, `unset`, `exit`.

## Resources
- GNU Bash Reference Manual (official docs for shell behavior and builtins): https://www.gnu.org/software/bash/manual/bash.html
- Writing Your Own Shell (Purdue Systems Programming Book, Chapter 5): https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf
- Readline (man3): https://man7.org/linux/man-pages/man3/readline.3.html
- Understanding Bash redirection with file descriptors: https://medium.com/@pash4stud2/understanding-bash-redirection-with-file-descriptors-0ea510dc411f
- GNU Bash Manual - Redirections: https://www.gnu.org/software/bash/manual/html_node/Redirections.html
- How to use heredoc in shell scripting (GeeksforGeeks): https://www.geeksforgeeks.org/linux-unix/how-to-use-heredoc-in-shell-scripting/

### AI Usage
AI was used for debugging and for breaking tasks into smaller modular steps. It was
also used to understand Bash behavior, especially command execution details and
error handling. No AI-generated code was copied directly into the project; AI was
used as a support tool for reasoning and troubleshooting. AI also helped draft and
structure this `README.md`.





