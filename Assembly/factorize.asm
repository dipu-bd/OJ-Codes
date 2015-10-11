;=====================================================
; FACTORIZE
; Complexity: O(sqrt(n))
; Author: Sudipto Chandra
       
org 100h

include "emu8086.inc"
 
begin_main:
        
    call CLEAR_SCREEN
            
    call RunProgram
    
     
    ;check if continue
    
    printn
    print "Continue?-(y/n): "
    
    cont_inp:
        mov ah, 07h
        int 21h
        
        cmp al, 'y'   
        je begin_main        
        
        cmp al, 'n'       
        je end_main
                    
        mov ah, 0Ah
        mov cx, 1
        int 10h            
        jmp cont_inp
      
end_main:
ret 

;=====================================================
;Take input, call factorize procedure and show output.

RunProgram PROC  
    
    print "Number: "    
    call SCAN_NUM    
    printn
              
    mov ax, cx
    call PRINT_NUM
    print " = " 
    
    call Factorize                     
                                           
    lea bx, arr                                       
    mov ax, w.[bx]
    
    call PRINT_NUM                
    inc bx
    inc bx
            
    show_num:                          
        
        cmp [bx], -1                        
        je exit_program                                   
                                    
        print " x "
        mov ax, [bx]
        call PRINT_NUM
 
        inc bx
        inc bx
        jmp show_num
            
    exit_program:
    printn    
    ret
 
RunProgram ENDP


;=====================================================
; Factorize a number stored in CX.
; number are save in the [arr] variable.
; -1 indicates that the list is terminated.

Factorize PROC  
    
    lea bx, arr ;array pos
    mov dx, 2   ;index  
    
    ;handle zero
    cmp cx,1
    jg  facto_loop 
    mov [bx], cx
    inc bx
    inc bx
    jmp exit_factorize
    
    facto_loop:                      
        
        ;check if sqr index greater than the number                     
        cmp dx, cx 
        ja  exit_facto_loop                                                                               
                       
        facto_inloop:              
                                   
            push cx
                                                            
            ;divide number by index            
            mov ax, cx 
            mov cx, dx              
            mov dx, 0
            div cx     
            
            ;check if mod = 0            
            cmp dx, 0h 
            jne facto_inloop_out            
                         
            ;save current index
            mov [bx], cx
            inc bx
            inc bx           
            
            ;store new number            
            mov dx, cx       
            pop cx
            mov cx, ax
            jmp facto_inloop                        
                                
        facto_inloop_out:                                   
            mov dx, cx
            pop cx                                            
            inc dx                                
            jmp facto_loop
        
    exit_facto_loop:   
        
        cmp cx, 1
        jle exit_factorize
        
        mov [bx], cx
        inc bx
        inc bx
              
    exit_factorize:                  
        mov [bx], -1         
                
    ret
    
Factorize ENDP

DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
DEFINE_CLEAR_SCREEN

arr DW 100 DUP(-1)

end