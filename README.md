# Lab 9 System Calls
## info.c: 
- This file demonstrates maintenance system calls
- This will get the time, hostname, operating system, cpu architecture, processors, physical memory, free bytes, and the version and release of the operating system
## pinfo.c: 
- This demonstrates process control system calls
- This will take a pid number as an argument and will find it's priority and scheduling method, if no arguments are provided it will find this information on itself
## pmod.c: 
- This demonstrates altering processes in linux
- This will give itself a niceness of 10, moving its priority down 10, and then it will sleep for just under 2 seconds
## finfo.c: 
- this will display information on a given file
- this will find what kind of file we have, it's permission, owner, size, and date of last modification
