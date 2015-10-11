;=========================================================
; PRIME NUMBER CHECKER                    
; Complexity: O(sqrt(n))
; Author: Sudipto Chandra                                 
;=========================================================

include 'emu8086.inc'

org 100h  

start:

    call    CLEAR_SCREEN
    
    call    PrimeChecker  
        
    ; check if user wants to continue           
    
    printn
    print   "Coninue?-(y/n): "    
    
    continue_check:
    
    mov     ah, 07h
    int     21h   
                                                                        
    cmp     al, 'y'
    je      start
    
    cmp     al, 'n'
    je      stop 
              
    mov     ah, 0Ah
    mov     cx, 1
    int     10h           
    
    jmp     continue_check   
        
stop: 

    call    CLEAR_SCREEN
    
    printn  "Thanks for your time."  
    
ret                            

;=========================================================
; Takes a number from the console and
; tells whether it is a prime number or not.
; If prime, shows the first of its factors.

PrimeChecker PROC            
               
    print   "Number: "
    call    SCAN_NUM                 
    printn
    
    call    IsPrime
    
    cmp     bx, 0
    jne     not_prime  
                   
    ; tells that the number is prime                   
    printn  "It is a prime number."
    jmp     end_check                                                                                                
                                    
    not_prime:                          
    ; tells that the number is not prime      
    printn  "It is not a prime number."             
    
    ; show lowest factor         
    call    PRINT_NUM                  
    print   " x "   
    
    mov     ax, bx     
    call    PRINT_NUM          
    print   " = "    
    
    mov     ax, cx     
    call    PRINT_NUM      
    printn  "."
    
    end_check:             
    ret                      

PrimeChecker ENDP
                               
                               
;=========================================================
; Checks if the given number is prime or not.
; input : cx = number to check.
; output:
;   if bx = 0, it is prime.
;   otherwise, ax * bx = cx.
;      ax is the lowest factor which divides cx.                                                             
                               
IsPrime PROC                          
    
    ;first take absolute of the number
    
    cmp     cx, 0
    jge     inverse_skip
        
    sub     cx, 1
    not     cx
    
    inverse_skip:             
    
    ;check if number is below 2             
    mov     ax, cx
    mov     bx, 1
    cmp     cx, 1
    jbe     stopIsPrime
    
    ;start loop from bx = 2                                                   
    mov     bx, 2
                                            
    startIsPrime:    
    mov     al, bl
    imul    bl
        
    cmp     ax, cx
    ja      prime     ; break at sqrt(num)
          
    mov     dx, 0
    mov     ax, cx    
    idiv    bx 
    
    cmp     dx, 0
    je      notprime  ; bx divides the number
    
    inc     bx 
    jmp     startIsPrime ; loop next       
    
    notprime:     
    mov     dx, ax
    mov     ax, bx
    mov     bx, dx      ; ax * bx = cx 
    jmp     stopIsPrime 
    
    prime:          
    mov     bx, 0   ; if bx == 0 it is prime                 
    
    stopIsPrime:               
    ret    
    
IsPrime ENDP 


;=========================================================

DEFINE_SCAN_NUM 
DEFINE_PRINT_NUM 
DEFINE_PRINT_NUM_UNS
DEFINE_CLEAR_SCREEN

end