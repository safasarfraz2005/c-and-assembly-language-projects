INCLUDE EMU8086.INC     ;Including Library
org 100h
.data       ;Data Segment
msg_intro db '  1. Addition', 0dh,0ah, '  2. Subtraction', 0dh,0ah, '  3. Multiplication', 0dh,0ah, '  4. Division', 0dh,0ah, '  5. Negation', 0dh,0ah, '  6. Square', 0dh,0ah, '  7. Cube', 0dh,0ah, '  8. modulus ', 0dh,0ah,  '  9. factorial ', 0dh,0ah,  '  10. Square root ', 0dh,0ah,  '  11. Dec to binary ', 0dh,0ah , '  12. Binary to dec ', 0dh,0ah, '  13. Dec to hex ', 0dh,0ah, '  14. Dec to octal ', 0dh,0ah, '  15. Hex to dec ', 0dh,0ah, '  16. Octal to dec ', 0dh,0ah, '$'
msg_A db 'The SUM of two Numbers = $', 0dh,0ah       ;Printing Strings
msg_S db 'The SUBTRACTION of two Numbers = $', 0dh,0ah
msg_M db 'The MULTIPLICATION of two Numbers = $', 0dh,0ah
msg_D db 'The DIVISION of two Numbers = $', 0dh,0ah 
msg_N db 'The NEG value of Number = $', 0dh,0ah 
msg_SQ db 'The SQUARE of Number = $', 0dh,0ah 
msg_CB db 'The CUBE of Number = $', 0dh,0ah
msg_MD db 'The MODULUS of Two Numbers = $', 0dh,0ah             
msg_FC dw 'The FACTORIAL of Number = $', 0dh,0ah
msg_SQRT dw 'The SQUARE ROOT of Number = $', 0dh,0ah 
msg_DB dw 'The DECIMAL TO BINARY of Number = $', 0dh,0ah  
msg_BD dw 'The BINARY TO DECIMAL of Number = $', 0dh,0ah
msg_DH dw 'The DECIMAL TO HEXADECIMAL of Number = $', 0dh,0ah
msg_DO dw 'The DECIMAL TO OCTAL of Number = $', 0dh,0ah
msg_HD dw 'The HEXADECIMAL TO DECIMAL of Number = $', 0dh,0ah
msg_OD dw 'The OCTAL TO DECIMAL of Number = $', 0dh,0ah
cont db 10,13,'Do you want to Use Again ? $'
bye db '            ** Thank You !!!  :) ** $'     
val1 dw ?       ;Uninitialize
val2 dw ?       ;Uninitialize  
res dw ?
agn dw ?
.code       ;Code Segment
MAIN PROC    
MOV AX, @data
MOV DS, AX
Start:                  ;Start Lable
print '             ** CALCULATOR **    '  
printn      ;New Line
printn
MOV AH,9
MOV DX, OFFSET msg_intro
INT 21h                                          
printn
printn
print 'Select Any Option : '
CALL scan_num
printn
printn

CMP CX, 0
JE _Bye             ;Jumps to Exit Func if input is equal to 0             
CMP CX, 1
JE Addition         ;Jumps to Addition Func if input is equal to 1
CMP CX, 2
JE Subtraction      ;Jumps to Subtraction Func if input is equal to 2
CMP CX, 3
JE Multiplication   ;Jumps to Multiplication Func if input is equal to 3
CMP CX, 4
JE Division         ;Jumps to Division Func if input is equal to 4
CMP CX, 5
JE Negation         ;Jumps to Absolute Func if input is equal to 5
CMP CX, 6
JE Square           ;Jumps to Square Func if input is equal to 6
CMP CX, 7
JE Cube             ;Jumps to Cube Func if input is equal to 7
CMP CX, 8
JE Modulus          ;Jumps to Modulus Func if input is equal to 8
CMP CX,9
JE Factorial       
CMP CX,10
JE SquareRoot 
CMP CX,11
JE DecToBinary
CMP CX,12
JE BinaryToDec 
CMP CX,13
JE DecToHex
CMP CX,14
JE DecToOctal
CMP CX,15
JE HexToDec
CMP CX,16
JE OctalToDec

Addition:       ;Addition Func
print '     **--Addition--'
printn
printn
print 'Enter First Number: '
CALL scan_num       ;First no. input
MOV val1, CX        ;Moving first no. to val1   
printn 
print 'Enter Second Number: '
CALL scan_num       ;Second no. input
MOV val2, CX        ;Moving second no. to val2
printn
MOV AX, val1        ;Adding AX to val2
ADD AX, val2        
MOV res, AX         
printn
MOV AH,9
MOV DX, OFFSET msg_A    ;Displaying Message
INT 21h                 
MOV AX, res             
CALL print_num          
 JMP Con                                                   

Subtraction:        ;Subtraction Func
print '     **--Subtraction--'
printn
printn
print 'Enter First Number: '
CALL scan_num       
MOV val1, CX        
printn 
print 'Enter Second Number: '
CALL scan_num       
MOV val2, CX        
printn
MOV AX, val1        
SUB AX, val2        
MOV res, AX         
printn
MOV AH,9
MOV DX, OFFSET msg_S    
INT 21h                 
MOV AX, res             
CALL print_num          
JMP Con                 

Multiplication:        ;Multiplication Func
print '     **--Multiplication--'
printn  
printn
print 'Enter First Number: '
CALL scan_num       
MOV val1, CX        
printn 
print 'Enter Second Number: '
CALL scan_num       
MOV val2, CX        
printn
MOV AX, val1        
MUL val2            
MOV res, AX         
printn
MOV AH,9
MOV DX, OFFSET msg_M    
INT 21h                 
MOV AX, res             
CALL print_num          
JMP Con                

Division:        ;Division Func
print '     **--Division--' 
printn
printn
print 'Enter First Number: '
CALL scan_num       
MOV val1, CX        
MOV AX, val1        
printn 
print 'Enter Second Number: '
CALL scan_num       
MOV val2, CX        
MOV BX, val2
printn
CMP BX, 0      
JE Error        
MOV DX, 0           
DIV BX            
MOV res, AX         
printn
MOV AH,9
MOV DX, OFFSET msg_D    
INT 21h                 
MOV AX, res             
CALL print_num          
JMP Con                 

Negation:        ;Negation Func
print '     **--Negation--' 
printn
printn
print 'Enter Number: '
CALL scan_num       
MOV val1, CX        
printn 
MOV AX, val1        
NEG AX              
MOV res, AX         
printn
MOV AH,9
MOV DX, OFFSET msg_N    
INT 21h                 
MOV AX, res             
CALL print_num          
JMP Con                 

Square:             ;Square Func               
print '     **--Square--'
printn 
printn
print 'Enter Number: '
CALL scan_num       
MOV val1, CX        
printn 
MOV AX, val1
MUL AX
MOV res, AX
printn
MOV AH,9
MOV DX, OFFSET msg_SQ    
INT 21h                 
MOV AX, res
CALL print_num
JMP Con
   
Cube:             ;Cube Func               
print '     **--Cube--'
printn
printn
print 'Enter Number: '
CALL scan_num       
MOV val1, CX        
printn 
MOV AX, val1
MUL val1  
MUL val1
MOV res, AX
printn
MOV AH,9
MOV DX, OFFSET msg_CB    
INT 21h                 
MOV AX, res
CALL print_num
JMP Con

Modulus:
print '     **--Modulus--' 
printn
printn
print 'Enter First Number: '
CALL scan_num       
MOV val1, CX        
MOV AX, val1        
printn 
print 'Enter Second Number: '
CALL scan_num       
MOV val2, CX        
MOV BX, val2
printn
MOV DX, 0           
DIV BX            
MOV res, DX         
printn
MOV AH,9
MOV DX, OFFSET msg_MD    
INT 21h                 
MOV AX, res             
CALL print_num          
JMP Con                 
         
Factorial:
    print '     **--Factorial--'
    printn 
    printn
    print 'Enter Number: '
    CALL scan_num       ; First no. input
    MOV AX, CX          ; Move input value from CX to AX
    printn              ; New Line 

    ; Check if the number is greater than 5
    cmp AX, 5
    jg FactorialError   ; Jump to error message if greater than 5

    ; Calculate factorial for numbers between 0 and 5
    cmp AX, 0
    je FactorialZeroOne
    cmp AX, 1
    je FactorialZeroOne

    ; Initialize the result to 1 (Factorial of any number starts at 1)
    mov BX, AX          ; Copy input to BX (This is the number to calculate factorial for)
    mov AX, 1           ; Initialize AX to 1 (this will store the factorial result)
    mov CX, 1           ; Start with CX = 1 (loop counter)

FactorialLoop:
    mul CX              ; Multiply AX (current result) by CX (current number)
    inc CX              ; Increment CX (move to next number)
    cmp CX, BX          ; Compare CX with BX (input number)
    jle FactorialLoop   ; If CX <= BX, continue the loop

    ; The result is now in AX
    MOV res, AX         ; Store result in 'res'

    ; Display the message using INT 21h
    MOV AH, 09h
    MOV DX, OFFSET msg_FC   ; Address of the message string
    INT 21h                 ; Calling Interrupt to print the string

    MOV AX, res
    CALL print_num

    JMP Con

FactorialZeroOne:
    mov AX, 1           ; 0! and 1! both equal 1
    MOV res, AX
    jmp FactorialDone

FactorialDone:
    printn
    MOV AH, 9
    MOV DX, OFFSET msg_FC   ; Displaying Message
    INT 21h                 ; Calling Interrupt to print the string

    MOV AX, res
    CALL print_num
    ret

FactorialError:
    ; Display error message if input > 5
    MOV AH, 09h
    MOV DX, OFFSET msg_FC   ; Address of the error message
    INT 21h                          ; Calling interrupt to print the error message
    JMP Con                          ; Return to main menu or further functionality

SquareRoot:
    print '     **--Square Root--'
    printn 
    printn
    print 'Enter Number: '
    CALL scan_num       
    MOV AX, CX          
    MOV val1, AX        
    cmp AX, 0
    je SquareRootZero
    mov bx, ax           
    mov cx, ax           
    shr cx, 1            

SquareRootLoop:
    push ax              
    mov dx, 0            
    div cx               
    add ax, cx           
    shr ax, 1            
    mov dx, ax           
    cmp dx, cx           
    je SquareRootDone    
    mov cx, dx           
    pop ax               
    jmp SquareRootLoop

SquareRootZero:
    mov AX, 0            
    MOV res, AX
SquareRootDone:
    MOV res, CX          
    MOV AH, 09h
    MOV DX, OFFSET msg_SQRT
    INT 21h              
    MOV AX, res          
    CALL print_num       
    JMP Con
    
    DecToBinary:
    print '     **--Decimal to Binary--'
    printn
    printn
    print 'Enter Number: '
    CALL scan_num
    MOV AX, CX
    MOV BX, 2
    MOV CX, 0   ; Counter

BinaryConversionLoop:
    MOV DX, 0   ; Clear remainder
    DIV BX      ; Divide AX by 2, remainder in DX
    PUSH DX     ; Store remainder (binary digit)
    INC CX      ; Increment counter
    CMP AX, 0
    JNE BinaryConversionLoop

printn
print 'Binary Representation: '  
PrintBinaryLoop:
    POP DX
    ADD DL, '0'
    MOV AH, 02h
    INT 21h
    LOOP PrintBinaryLoop
printn
JMP Con
        
BinaryToDec:
    print '     **--Binary to Decimal--'
    printn
    printn
    print 'Enter a Binary Number: '
    CALL scan_num       
    MOV AX, CX          
    MOV BX, 0           
    MOV DX, 0           
BinaryLoop:
    SHL AX, 1           
    JC BinaryBitSet     
    JMP BinaryBitClear
BinaryBitSet:
    ADD BX, 1           
BinaryBitClear:
    SHL BX, 1           
    DEC DX              
    CMP DX, 0           
    JG BinaryLoop       
    MOV res, BX         
    printn
    MOV AH, 9
    MOV DX, OFFSET msg_BD    
    INT 21h
    MOV AX, res
    CALL print_num          
    JMP Con                 

DecToHex:
    print '     **--Decimal to Hexadecimal--'
    printn
    printn
    print 'Enter Decimal Number: '
    CALL scan_num       
    MOV AX, CX          
    printn
    printn
    MOV AH,9
    MOV DX, OFFSET msg_DH
    INT 21h
    CALL print_hex
    JMP Con

DecToOctal:
    print '     **--Decimal to Octal--'
    printn
    printn
    print 'Enter Decimal Number: '
    CALL scan_num
    MOV AX, CX
    printn
    printn
    MOV AH,9
    MOV DX, OFFSET msg_DO
    INT 21h
    CALL print_octal
    JMP Con

HexToDec:
    print '     **--Hexadecimal to Decimal--'
    printn
    printn
    print 'Enter Hexadecimal Number (0-9, A-F): '
    CALL hex_to_num     
    MOV res, AX
    printn
    MOV AH,9
    MOV DX, OFFSET msg_HD
    INT 21h
    MOV AX, res
    CALL print_num
    JMP Con

OctalToDec:
    print '     **--Octal to Decimal--'
    printn
    printn
    print 'Enter Octal Number (0-7): '
    CALL octal_to_num    
    MOV res, AX
    printn
    MOV AH,9
    MOV DX, OFFSET msg_OD
    INT 21h
    MOV AX, res
    CALL print_num
    JMP Con

Error:    
printn
print 'Cannot be divided by 0. ' 
printn
print 'Undefined Math Error'
printn    
printn
JMP Division

Con:            ;Continue Func
printn
MOV AH,9
MOV DX, OFFSET cont    
INT 21h                 
print '(Yes = 1 / No = 0) : '
CALL scan_num           
MOV agn, CX
printn
printn
CMP agn, 1
JE Start                
CMP agn, 0
JE _Bye             
printn
_Bye:       ;EXIT Func
printn
printn
MOV AH,9
MOV DX, OFFSET bye    
INT 21h                        
MAIN ENDP        

; Helper procedures
 print_hex:
    push ax
    push bx
    push cx
    push dx

    mov cx, 0
.hex_loop:
    cmp ax, 0
    je .hex_done
    mov dx, 0
    div bx
    push dx
    inc cx
    jmp .hex_loop

.hex_done:
    cmp cx, 0
    jne .print_hex_digits
    mov dx, '0'
    mov ah, 02h
    int 21h
    jmp .end_print_hex

.print_hex_digits:
    pop dx
    add dx, '0'
    cmp dx, '9'
    jbe .print_digit_hex
    add dx, 7  ; Adjust for A-F

.print_digit_hex:
    mov ah, 02h
    int 21h
    loop .print_hex_digits

.end_print_hex:
    pop dx
    pop cx
    pop bx
    pop ax
    ret

;--------------------------------------------------------

hex_to_num:
    push bx
    push cx
    push dx
    mov bx, 16
    mov cx, 0
get_char:
    mov ah, 01h  ; BIOS interrupt to read character
    int 21h      ; Read from standard input (AL will contain the character)
    ret

.read_char_hex:
    call get_char
    cmp al, 0Dh
    je .done_hex

    cmp al, '0'
    jb .error_hex
    cmp al, '9'
    jbe .convert_digit_hex
    cmp al, 'A'
    jb .error_hex
    cmp al, 'F'
    ja .error_hex
    sub al, 'A' - 10
    jmp .store_digit_hex

.convert_digit_hex:
    sub al, '0'

.store_digit_hex:
    push ax
    mov ax, cx
    mul bx
    pop bx
    add ax, bx
    mov cx, ax
    jmp .read_char_hex

.error_hex:
    mov cx, -1

.done_hex:
    pop dx
    pop cx
    pop bx
    ret

;--------------------------------------------------------

print_octal:
    push ax
    push bx
    push cx
    push dx

    mov cx, 0
.octal_loop:
    cmp ax, 0
    je .octal_done
    mov dx, 0
    div bx
    push dx
    inc cx
    jmp .octal_loop

.octal_done:
    cmp cx, 0
    jne .print_octal_digits
    mov dx, '0'
    mov ah, 02h
    int 21h
    jmp .end_print_octal

.print_octal_digits:
    pop dx
    add dx, '0'
    mov ah, 02h
    int 21h
    loop .print_octal_digits

.end_print_octal:
    pop dx
    pop cx
    pop bx
    pop ax
    ret

;--------------------------------------------------------

octal_to_num:
    push bx
    push cx
    push dx
    mov bx, 8
    mov cx, 0

.read_char_octal:
    call get_char
    cmp al, 0Dh
    je .done_octal

    cmp al, '0'
    jb .error_octal
    cmp al, '7'
    ja .error_octal
    sub al, '0'
    jmp .store_digit_octal

.store_digit_octal:
    push ax
    mov ax, cx
    mul bx
    pop bx
    add ax, bx
    mov cx, ax
    jmp .read_char_octal

.error_octal:
    mov cx, -1

.done_octal:
    pop dx
    pop cx
    pop bx
    ret

DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
END main