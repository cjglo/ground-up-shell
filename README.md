# Ground-Up Shell
A Unix Shell built in C without external libraries.

## How to Use 

### Reading from file

Currently this project has just passed its 0.1 version.  It can currently forks a process and executes any binary in your PATH variable but only from an input file.  Run the following Makefile commands to run the shell:


Insert the file where $(arg) is 
```
make build
make run $(arg)
```

## Current & Planned Features:

- [X] Accepts file input with commands of arbitary length and creates processes to execute, then exits parent process
- [ ] Running commands from interactive user input
- [ ] Setting/retrieving environment variables
- [ ] Support for pipes (including stdin/stdout redirection)
- [ ] Built-in functionality that is often part of a *nix shell (such as implementations of common utilities like cd), other than what has been outlined above
- [ ] The ability to change directories or anything else of the like
- [ ] Quoting/escaping of characters in arguments/program names
- [ ] Running programs in the background
