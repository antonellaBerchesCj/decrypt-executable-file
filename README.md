# decrypt-executable-file
C and ASM

About output file.exe.new:
- Contains buffer1, if decrypted it is placed in buffer2 (already have memory allocated)
- Buffer2 contains a path to iexplore.exe and a root link
- The file contains now buffer1 and buffer2 and I have changed the file size (coff explorer -> sections header-> raw size get value of virtual size)
