
# Custom C Utility Programs

This repository contains custom implementations of common Unix-like utilities in C. These utilities mimic the behavior of their standard counterparts (`cp`, `echo`, `mv`, and `pwd`) but with simplified logic and structure.

## Programs

### 1. `mycp.c`
This program is a custom implementation of the Unix `cp` command. It copies files from one location to another.

#### Usage:
```bash
./mycp source_file destination_file
```

#### Features:
- Copies the contents of the `source_file` to the `destination_file`.
- Supports basic file error handling.

### 2. `myecho.c`
This program is a custom implementation of the Unix `echo` command. It outputs the arguments provided to it.

#### Usage:
```bash
./myecho [arguments...]
```

#### Features:
- Prints the given arguments to the standard output.
- Supports multiple arguments and handles them as the standard `echo` does.

### 3. `mymv.c`
This program is a custom implementation of the Unix `mv` command. It moves or renames files.

#### Usage:
```bash
./mymv source_file destination_file
```

#### Features:
- Moves or renames the `source_file` to `destination_file`.
- Includes basic file handling for renaming and moving.

### 4. `mypwd.c`
This program is a custom implementation of the Unix `pwd` command. It prints the current working directory using the `getcwd()` function.

#### Code:
```c
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERR_RET -1
#define RET 0 
#define PATH_MAX 256

int main()
{
    char buf[PATH_MAX];
    if (getcwd(buf, PATH_MAX) == NULL)
    {
        printf("ERROR: Path name exceeds PATH_MAX\n");
        return ERR_RET;
    }
    printf("%s\n", buf);
    return RET;
}
```

#### Usage:
```bash
./mypwd
```

#### Features:
- Retrieves and prints the current working directory using `getcwd()`.
- Handles errors if the path exceeds `PATH_MAX`.

## Compilation
To compile these programs, use the following commands:

```bash
gcc -o mycp mycp.c
gcc -o myecho myecho.c
gcc -o mymv mymv.c
gcc -o mypwd mypwd.c
```

## Notes
- These programs are basic implementations and do not include all advanced features of the original Unix utilities.
- The `mypwd.c` program demonstrates how to retrieve and display the current working directory.
- They are designed for educational purposes or simple use cases.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
