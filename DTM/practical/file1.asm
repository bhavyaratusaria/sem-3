data segment
    n1 db 08H
    n2 db 03H
    sum db ?
data ends

code segment
    assume cs:code, ds:data

start:
    mov    ax, data
    mov    ds, ax
    mov    al, n1
    mov    bl, n2
    add    al, bl
    mov    sum, al
    mov    ah, 4ch
    int    21H

code ends
    end start