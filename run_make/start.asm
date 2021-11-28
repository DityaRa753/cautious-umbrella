global      _start
extern      test
section     .text
_start:     call test
            add esp, 8
            mov ebx, eax
            mov eax, 1
            int 80h
            
