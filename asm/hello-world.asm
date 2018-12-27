section .data
    msg: db  "hello, world!\n"
    msg_len: equ $-msg

section .text
    global _start
_start:
    mov eax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, msg_len
    syscall

    mov eax, 60
    mov rdi, 20
    syscall
