#include <stdio.h>

// Global variables
unsigned int myEbp = 0;
char buffSource[800];
char buffDest[4800];

int main()
{
    // Read input file
        FILE *fp;
        FILE *out;
        fopen_s(&fp,"file.exe.new", "rb");

        if(fp == NULL)
        {
             printf("\nCannot open file or file does not exist.");
             exit(0);
        }

        fseek(fp, 0x32A, SEEK_CUR);
        fread(buffSource, 0x61A - 0x32A, 1, fp);
		
    __asm {
        
            mov     [myEbp], ebp

            lea     esi, buffSource
            lea     edi, buffDest

            cld
            mov     dl, 80h
            xor     ebx, ebx

        loc_13141095:
            movsb
            mov   bl, 2

        loc_13141098:
            call    sub_1314110A
            jnb     short loc_13141095
            xor     ecx, ecx
            call    sub_1314110A
            jnb     short loc_131410C4
            xor     eax, eax
            call    sub_1314110A
            jnb     short loc_131410D4
            mov     bl, 2
            inc     ecx
            mov     al, 10h

        loc_131410B6:
            call    sub_1314110A
            adc     al, al
            jnb     short loc_131410B6
            jnz     short loc_13141100
            stosb
            jmp     short loc_13141098

        loc_131410C4:
            call    sub_13141116
            sub     ecx, ebx
            jnz     short loc_131410DD
            call    sub_13141114
            jmp     short loc_131410FC

        loc_131410D4:
            lodsb
            shr     eax, 1
            jz      short loc_13141126
            adc     ecx, ecx
            jmp     short loc_131410F9

        loc_131410DD:
            xchg    eax, ecx
            dec     eax
            shl     eax, 8
            lodsb
            call    sub_13141114
            cmp     eax, 7D00h
            jnb     short loc_131410F9
            cmp     ah, 5
            jnb     short loc_131410FA
            cmp     eax, 7Fh
            ja      short loc_131410FB

        loc_131410F9:
            inc     ecx

        loc_131410FA:
            inc     ecx

        loc_131410FB:
            xchg    eax, ebp

        loc_131410FC:
            mov     eax, ebp
            mov     bl, 1

        loc_13141100:
            push    esi
            mov     esi, edi
            sub     esi, eax
            rep     movsb
            pop     esi
            jmp     short loc_13141098

        sub_1314110A:
            add     dl, dl
            jnz     short locret_13141113
            mov     dl, [esi]
            inc     esi
            adc     dl, dl

        locret_13141113:
            retn

        sub_13141114:
            xor     ecx, ecx

        sub_13141116:
            inc     ecx

        loc_13141117:
            call    sub_1314110A
            adc     ecx, ecx
            call    sub_1314110A
            jb      short loc_13141117
            retn

        loc_13141126:    
            mov     ebp, [myEbp]
    }

   {  
       
        // Write decrypted file    
        fopen_s(&out, "decryptedFile.exe.new", "wb");
        fseek(out, 0x61C, SEEK_CUR);
        fwrite(buffDest, 0x61C+0x12C, 1, out);
        fclose(fp);
        fclose(out);

    }
}
