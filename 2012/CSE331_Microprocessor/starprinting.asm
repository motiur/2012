    .MODEL SMALL

    .DATA
    
    .CODE
    
    .STARTUP
    
      
    MOV BX, 0
    
    MOV AH, 1
    
    AGAIN:
    
    INT 21h  
    
    CMP AL,0DH
    
    JE END_AGAIN
             
    INC BX   
    
    LOOP AGAIN
          
    END_AGAIN:    
    
    .EXIT
    
    END                                       
    