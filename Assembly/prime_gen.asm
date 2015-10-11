;----------------------------------------------------
; PRIME NUMBER GENERATOR
; Complexity: O(n * log(n) * log(n))
; Author: Sudipto Chandra

org 100h      

include "emu8086.inc"                        

SIZ EQU 100 

call MakeSieve                          
              
call ShowPrimes             
                                                                                                          
ret           


;----------------------------------------------------


ShowPrimes PROC
    
    print "Showing primes from 1 to "
    mov ax, SIZ
    call PRINT_NUM                                  
    printn " :"  
    printn
    
    lea bx, arr
    mov cx, 0  
    mov dx, 0
        
    show_next:  
      
        cmp [bx], 1
        jne skip
                     
        mov ax, cx                
        call PRINT_NUM_UNS
        print " "
        
        inc dx
    
    skip:           
           
        inc cx     
        inc bx          
               
        cmp cx, SIZ
        jb show_next    
    
    printn  
    printn                          
    print "Total primes found : "
    mov ax, dx
    call PRINT_NUM 
    printn
           
    ret    
    
ShowPrimes ENDP


;----------------------------------------------------


MakeSieve PROC 
    
    printn "Running sieve... "
                
    mov cx, 2  
    mov arr[0], 0
    mov arr[1], 0    
            
    outer_loop:
        
        mov al, cl
        mul cl
        cmp ax, SIZ
        ja break_outer
        
        lea bx, arr
        add bx, cx
        cmp [bx], 1
        jne break_inner
                                
        inner_loop:   
                
            lea bx, arr
            add bx, ax  
            mov [bx], 0              
            add ax, cx                  
            
            cmp ax, SIZ
            jb inner_loop                                                  
           
        break_inner:
                                                              
        inc cl                                                            
        jmp outer_loop         
        
    break_outer:    
                                   
    ret                                                   
    
MakeSieve ENDP      

;----------------------------------------------------

DEFINE_CLEAR_SCREEN
DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS

arr DB SIZ DUP(1) ; pre-allocate array with 1

end
EN
DEFINE_SCAN_NUM
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS

arr DB SIZ DUP(1) ; pre-allocate array with 1

end
