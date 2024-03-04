# 42-pipex

This project is aimed at creating a program in C replicating the shell pipe operator.  
The program is executed as follows:
```c
./pipex file1 cmd1 cmd file2
```
and it must be hehave exactly as the following shell command:
```bash
< file1 cmd1 | cmd2 > file2

# Execute cmd1(command) on the file1(input) and redirect the output to cmd2
# --> Execute cmd2 on the output of cmd1
# --> Output on file2
```

Example of shell command outputs:
```bash
➜  pipex ls -a        
.  ..  file1.txt  file2.txt
➜  pipex cat file1.txt
Hello
Hello
Bonjour
Coucou
Hello
➜  pipex cat file2.txt
```
```bash
➜  pipex < file1.txt cat | wc -l                   
5
➜  pipex < file1.txt cat | wc -l > file2.txt       
➜  pipex cat file2.txt                      
5
# If there is no outfile, it's shown on stdout, else it's written on outfile(file2).
```
```bash
➜  pipex < file1.txt grep Hello | wc -l > file2.txt
➜  pipex cat file2.txt                             
3
```
```bash
➜  pipex < file1.txt cat | grep Hello > file2.txt 
➜  pipex cat file2.txt                            
Hello
Hello
Hello
```

## External functions

### access
```c
int access(const char *pathname, int mode)

/* pathname: A pointer to a null-terminated string containing the path to the file or directory whose accessibility is being checked. */  
/* mode: An integer representing the desired mode of access to be checked:
    F_OK (existence check),
    R_OK (read permission check),
    W_OK (write permission check),
    X_OK (execute permission check). */
```
It checks the accessibility of a file or directory, verifying whether the calling process has the specified permissions to perform the requested operation on the file. It returns __0__ if the requested access is granted and __-1__ if an error occurs.
  
Example:
```c
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    const char *file = "example.txt";

    /* Check read permission for 'file' */
    if (access(filename, R_OK) == 0)
        printf("File %s is readable.\n", filename);
    else
        perror("Error");
    return 0;
}
```

### dup
```c
int dup(int oldfd)
  
/* oldfd: The file descriptor to be duplicated. */
```
It creates a new file descriptor that refers to the same open file description as the original descriptor (oldfd).  
It returns __a new file descriptor__ if successful, and __-1__ if an error occurs.  

### dup2
```c
int dup2(int oldfd, int newfd)
```
It is s similar to `dup()`, but it allows to explicitly specify the target file descriptor for the duplication. This function is useful when we want to duplicate a file descriptor and assign it a specific file descriptor number.  
It returns __a new file descriptor__ if successful, and __-1__ if an error occurs. If `newfd` is already in use, `dup2()` closes it before performing the duplication.  

### execve
```c
int execve(const char *pathname, char *const argv[], char *const envp[])
```
It is used to execute a program. It replaces the current process image with a new one, loading a new program into the current process's memory. This is commonly used in conjunction with the __fork__ system call to create a new process, and then one of the exec family of functions to replace the program in the child process.  
The execve function __does not return__ if it is successful, instead, it replaces the current process image. If an error occurs, it returns __-1__.  


- const char *pathname: The path to the executable file. --e.g. {"/bin/ls", NULL} */  
- char *const argv[]: プログラムに渡すコマンドライン引数
    An array of pointers to null-terminated strings representing the program arguments.
    The last element of the array must be a NULL pointer. 
    --e.g. {"/bin/ls", "-l", NULL}	*/  
- char *const envp[]: An array of pointers to null-terminated strings representing the environment variables.
    The last element of the array must be a NULL pointer.
    We can use the 3rd argument of main (char **envp). */  
    
Example:
```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    /* Path to the executable program */
    const char *programPath = "/bin/ls";

    /* Command-line arguments for the program プログラムに渡すコマンドライン引数 */
    char *const arguments[] = { "/bin/ls", "-l", NULL };

    /* Environment variables 環境変数（不要な場合は NULL に設定できる） */
    char *const environment[] = { "LANG=en_US.UTF-8", NULL };

    /* Execute the program */
    if (execve(programPath, arguments, environment) == -1)
    {
        perror("execve");
        return 1;
    }

    /* This code is never reached if execve is successful */

    return 0;
}
```

### fork
```c
pid_t fork(void)
```
It creates a new process by duplicating the existing process. The new process is referred to as the child process, and the original process is referred to as the parent process. After a successful fork, both the parent and the child processes continue to execute independently after the fork call.  
This function returns  
* __the process ID (PID) of the child process__ to the parent
*  __0__ to the child
*  If an error occurs, it returns __-1__.  

The `pid_t` (Process ID, PID) is a unique identifier assigned to each process running on a computer system. The PID is used by the operating system to distinguish and manage individual processes. It's a non-negative integer, and each process has a unique PID within the system.  
When a new process is created, such as through the fork system call in Unix-like operating systems, a new PID is assigned to the child process. The PID is used by the operating system to keep track of the process and is crucial for various process-related operations.  

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;

    /* Fork a new process */
    pid = fork();

    /* Error handling */
    if (pid == -1)
    {
        perror("fork");
        return (1);
    }

/* Code that runs in both the parent and the child processes. */
    printf("Fork successful\n");
    if (pid == 0)
    {
        /* Code that runs only in the child process */
        printf("Child process on going: pid = %d\n", pid);
    }
    else if (pid > 0)
    {
        /* Code that runs only in the parent process */
        printf("Parent process on going: pid = %d\n", pid);
    }
    return (0);
}

/* OUTPUT Example
Fork successful
Parent process on going: pid = 30913
Fork successful
Child process on going: pid = 0
*/
```

### pipe
```c
int pipe(int pipefd[2])  

/*
pipefd: An array of two integers where the file descriptors for the read and write ends of the pipe are stored.
pipefd[0]: the file descriptor for reading  
pipefd[1]: the file descriptor for writing  
*/
```
The pipe system call in Unix-like operating systems is used for creating  a unidirectional communication channel between two processes. It provides a way for one process to send data to another process.  
The pipe function creates a pipe, which is essentially a pair of file descriptors, where one descriptor is for reading (fd[0]) and the other is for writing (fd[1]). Data written to the write descriptor (fd[1]) can be read from the read descriptor (fd[0]).  

Example:
```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    int fd[2];
    pid_t pid;
    const char *message = "Hello, Child!";
    char buffer[20];

    /* Create a pipe */
    /* fd[0] --> read end of the pipe, fd[1] --> write end of the pipe */
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    /* Fork a new process */
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    /* ----------------- Child process ----------------- */
    if (pid == 0)
    {

        /* Close the write end of the pipe */
        close(fd[1]);

        /* Read data from the pipe */
        if (read(fd[0], buffer, sizeof(buffer)) == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        /* Display the received data */
        printf("Child received: %s\n", buffer);

        /* Close the read end of the pipe */
        close(fd[0]);

        exit(EXIT_SUCCESS);
    }
    /* ----------------- Child process ----------------- */


    /* ----------------- Parent process ----------------- */
    else {
        
        /* Close the read end of the pipe */
        close(fd[0]);

        /* Write data to the pipe */
        if (write(fd[1], message, strlen(message) + 1) == -1)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        /* Close the write end of the pipe */
        close(fd[1]);

        /* Wait for the child process to finish */
        wait(NULL);

        exit(EXIT_SUCCESS);
    }
    /* ----------------- Parent process ----------------- */
}
```

### unlink
```c
int unlink(const char *pathname)
```
The unlink function in C is used to remove a link to a file. It's typically used to delete a file by removing its directory entry, which decreases the file's link count. If the link count becomes zero, indicating that there are no more references to the file, the file's data blocks are deallocated, and the space is reclaimed.  
It returns __0__ on success and __-1__ on failure.  

Example:
```c
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    const char *filename = "example.txt";

    /* Create a file for demonstration purposes */
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error creating file");
        return (1);
    }
    fclose(file);

    /* Unlink (delete) the file */
    if (unlink(filename) == -1)
    {
        perror("Error unlinking file");
        return (1);
    }
    printf("File unlinked successfully.\n");
    return (0);
}
```
> [!CAUTION]
> After using `unlink` to delete a file, the file is no longer accessible through its original name. If the file was the last link to the actual data, the file is effectively deleted, and its storage is freed. If there are other links or the file is open by a process, the data is not immediately deallocated until all links and open instances are removed.  

### wait
```c
pid_t wait(int *status)

/* status: A pointer to an integer where the exit status of the terminated child process will be stored. */
```
It makes a parent process wait until one of its child processes terminates. It allows the parent process to synchronize its execution with that of its child processes.  
It returns __the process ID (PID) of the terminated child process__ on success. If an error occurs, it returns __-1__. If we are not interested in the exit status, we can pass a null pointer for status.  

Example:
```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t   child_pid;
    pid_t   terminated_child;
    int     status;

    /* Fork a new process */
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    /* Code that runs in the child process */
    if (child_pid == 0)
    {
        printf("Child process (PID=%d) is running.\n", getpid());
        exit(EXIT_SUCCESS);
    }
    /* Code that runs in the parent process */
    else
    {
        printf("Parent process (PID=%d) is waiting for the child to finish.\n", getpid());

        /* Wait for the child process to terminate */
        terminated_child = wait(&status);
        if (terminated_child == -1)
        {
            perror("wait");
            exit(EXIT_FAILURE);
        } 
        printf("Parent process: Child process (PID=%d) has terminated with status %d.\n", terminated_child, status);
    }
    return (0);
}

/*
------ Output example  ------ 
Parent process (PID=12991) is waiting for the child to finish.
Child process (PID=12992) is running.
Parent process: Child process (PID=12992) has terminated with status 0.
*/
```

### waitpid
```c
pid_t waitpid(pid_t pid, int *status, int options)

/* pid: The process ID of the child process to wait for. If pid is -1, waitpid waits for any child process. */
/* status: A pointer to an integer where the exit status of the terminated child process will be stored. */
/* options: Additional options that control the behavior of the waitpid function. The commonly used option is WCONTINUED to request notification of a stopped child process that is continued. */
```
It is similar to the `wait` function and is used to make a parent process wait until __a specific child process__ terminates.    

### Error handling
#### perror
```c
void perror(const char *str)
```
It prints an error message on stderr: message defined in str followed by a colon and a blank, then an error message corresponding to the errno and a newline.

#### strerror
```c
char *strerror(int errnum)
```
It is used to retrieve a pointer to the textual representation of the current errno value, providing a human-readable description of the last error that occurred in the program. This string is usually generated by the C library.  
`int errnum` is an integer representing the error number for which we want to obtain the error message.

#### Example
```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    FILE *file = fopen("nonexistent_file.txt", "r");
    
    if (file == NULL)
    {
        perror("Error opening file");
        /* OUTPUT: Error opening file: No such file or directory */
        printf("Error message: %s\n", strerror(errno));
        /* OUTPUT: Error message: No such file or directory */
    }
    else
        fclose(file);
    return (0);
}
```

## envp
envp(environment pointer) is the 3rd parameter of `main` function in C.
```c
int main(int argc, char **argv, char **envp)
```

It is not part of the standard C language definition, but a common extension provided by many implementations, especially in Unix-like systems.

- `envp` is used to pass information about the environment variables to the program.  
- `char **envp` is a pointer to an array of strings, where each string is of the form "name=value". The last element of the array is typically a null pointer, indicating the end of the list.  

In pipex, we use `envp` to get a full-path to command (The line begins with "PATH="; in the example below, 25th element).  
  
Example:  
```c
int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	(void)argc;
    	(void)argv;
	while (envp[i])
	{
		printf("envp[%d]: %s\n", i, envp[i]);
		i++;
	}
	return 0;
}
  
/* Example of output
envp[0]: GJS_DEBUG_TOPICS=JS ERROR;JS LOG  
envp[1]: USER=yusengok  
.  
.  
envp[5]: HOME=/home/yusengok
.  
.  
.  
envp[25]: PATH=/home/yusengok/apps/VSCode/bin:/home/yusengok/bin:/home/yusengok/apps/VSCode/bin:/home/yusengok/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
*/
```
```bash
PATH=/home/yusengok/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin

# PATH shows the list of dorectories divided by ':'.
# For example:
# - /home/yusengok/bin
# - /usr/local/sbin
# - /usr/local/bin
# ... etc.
```

## Some test cases
```bash
./pipex file1.txt 'grep Hello' 'sed 's/Hello/Goodbye/g'' outfile.txt
```
```bash
./pipex file1.txt "tr ex ' X'" "tr pi 'P '" outfile.txt
```

```bash
./pipex /dev/urandom cat "head -1" outfile.txt

# The first command 'cat /dev/urandom' makes an infinite loop without any other commands.
```

```bash
./pipex file1.txt "grep Hello" "awk '{count++} END {print count}'" outfile.txt

# This should properly work.
```

```bash
./pipex file1.txt "grep Hello" "awk "{count++} END {print count}"" outfile.txt

# Invalid number of arguments without bonus / Error with bonus
```

```bash
./pipex file1.txt "grep Hello" "awk '\"{count++} END {print count}\"'" outfile.txt  
  
# '"{count++} END {print count}"' --> 2nd command is ignored
```

```bash
./pipex file1.txt "grep Hello" "awk \"'{count++} END {print count}'\"" outfile.txt
  
# "'{count++} END {print count}'" --> ERROR
```

```bash
./pipex file1.txt cat 'awk "{count++} END {printf \\"count: %i\\" , count}"' outfile.txt

# Must do like :
# < file1.txt cat | awk "{count++} END {printf \"count: %i\" , count}" > outfile.txt
```
>[!important]
> Be sure to close all fds before exit the program.  
> To check it : valgrind --track-fds=yes

## References

https://42-cursus.gitbook.io/guide/rank-02/pipex  
https://www.codequoi.com/en/pipe-an-inter-process-communication-method/  
https://zenn.dev/wake/scraps/9bc89fbe8cafd4  
https://jp-seemore.com/iot/11360/  
http://www.coins.tsukuba.ac.jp/~syspro/2005/No3.html  

### Testers
https://github.com/gmarcha/pipexMedic  
https://github.com/vfurmane/pipex-tester  
