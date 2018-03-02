## Stack buffer overflow 2

Basic demonstration of a stack buffer overflow. This example is compiled to a 32-bit program, and has stack protection disabled.

```
gcc -o stack stack.c -m32 -fno-stack-protector
```

## Goal

Using the file **stack**, you need to get through the function **answer** and have the message **It worked!** printed. No file modification is allowed.

## Solution

This exploit is about the function fgets. Our array is 10 bytes long and the function fgets is looking for up to 15 bytes. Thus, by giving more than 10 bytes to the standard input, we are going to overrun the buffer's boundary and overwrite an adjacent memory location (in our case, the function exploit which is located just under our array).

First, you need to find the memory address of the function answer :

```
gdb -q ./stack
disas answer
```

Here you can find the memory address <X> for the function answer

Using python :

```
python -c "print 'A'*10+'<X>'" | ./stack
```
