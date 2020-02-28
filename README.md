# decrypt-executable-file
C and ASM

About output file.exe.new:
- The file contains buffer1 allocated for buffer2 which contains the first buffer decryption
- Buffer2 contains a path to iexplore.exe and a root link
- The file contains now buffer1 and buffer2 and I have changed the file size (coff explorer -> sections header-> raw size get value of virtual size)
