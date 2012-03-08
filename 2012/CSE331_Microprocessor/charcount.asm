    .MODEL SMALL

    .DATA
    
    .CODE
    
    .STARTUP
    
     MOV AH, 1
     
     MOV DX, 0
     
     READ:
     
     INT 21h
   
     CMP AL, 0DH
     
     JE READ_END
     
     INC DX
     
     JMP READ
     
     READ_END:    
    
    .EXIT
    
    END                                       
    