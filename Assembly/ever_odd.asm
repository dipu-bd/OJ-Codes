org 100h  

include "emu8086.inc"


start: 

call clear_screen

; gets a number

print "Insert a number : "                   
call scan_num                                         
mov ax, cx                                            
printn     

call print_num                                           
    
;tell if the number is even or odd

and ax, 01h
cmp ax, 0h         
          
if:
    jne elseif
    printn " is even."
    jmp endif

elseif:
    printn " is odd."  
    
endif:               
    
; check if user wants to continue
    
printn
print "Coninue?-(y/n): "    

continue_check:

mov ah, 07h
int 21h   
                                                                    
cmp al, 'y'
je start

cmp al, 'n'
je stop 
          
mov ah, 0Ah
mov cx, 1
int 10h           

jmp continue_check

stop:

call clear_screen
printn "Thank you for using my program ^_^"

RET

DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
DEFINE_CLEAR_SCREEN

END
    
