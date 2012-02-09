
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h


lea si, arr1
lea di, arr2

inc di
inc di
inc di
inc di

mov al,[si]
mov [di],al
inc si
dec di

mov al,[si]
mov [di],al
inc si
dec di

mov al,[si]
mov [di],al
inc si
dec di

mov al,[si]
mov [di],al
inc si
dec di

mov al,[si]
mov [di],al
inc si
dec di

; add your code here

ret

arr1 db 1,2,3,4,5
arr2 db 5 dup(?)



