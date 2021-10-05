Errors i'm trying to solve:

gchurton@oucs1661lnx:~/242/Asgn2$ valgrind ./asgn2 -o -f test.dot < war-and-peace-20.txt
==9212== Memcheck, a memory error detector
==9212== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9212== Using Valgrind-3.16.0 and LibVEX; rerun with -h for copyright info
==9212== Command: ./asgn2 -o -f test.dot
==9212== 
Creating dot file 'test.dot'
==9212== Conditional jump or move depends on uninitialised value(s)
==9212==    at 0x4A1F95B: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401CFE: tree_output_dot (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x4015C1: main (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== Use of uninitialised value of size 8
==9212==    at 0x4A04EEB: _itoa_word (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A1F0F3: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401CFE: tree_output_dot (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x4015C1: main (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== Conditional jump or move depends on uninitialised value(s)
==9212==    at 0x4A04EFD: _itoa_word (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A1F0F3: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401CFE: tree_output_dot (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x4015C1: main (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== Conditional jump or move depends on uninitialised value(s)
==9212==    at 0x4A1FCB0: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401CFE: tree_output_dot (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x4015C1: main (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== Conditional jump or move depends on uninitialised value(s)
==9212==    at 0x4A1F263: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401CFE: tree_output_dot (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x4015C1: main (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== Conditional jump or move depends on uninitialised value(s)
==9212==    at 0x4A1F95B: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401CFE: tree_output_dot (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x4015C1: main (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== Conditional jump or move depends on uninitialised value(s)
==9212==    at 0x4A1FCB0: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401CFE: tree_output_dot (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x4015C1: main (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== Conditional jump or move depends on uninitialised value(s)
==9212==    at 0x4A1F263: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401CFE: tree_output_dot (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x4015C1: main (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== Conditional jump or move depends on uninitialised value(s)
==9212==    at 0x4A1F95B: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C80: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== Conditional jump or move depends on uninitialised value(s)
==9212==    at 0x4A1FCB0: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C80: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== Conditional jump or move depends on uninitialised value(s)
==9212==    at 0x4A1F263: __vfprintf_internal (in /usr/lib64/libc-2.30.so)
==9212==    by 0x4A0AC89: fprintf (in /usr/lib64/libc-2.30.so)
==9212==    by 0x401C45: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C80: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212==    by 0x401C56: tree_output_dot_aux (in /home/cshome/g/gchurton/242/Asgn2/asgn2)
==9212== 
==9212== 
==9212== HEAP SUMMARY:
==9212==     in use at exit: 488 bytes in 1 blocks
==9212==   total heap usage: 36,281 allocs, 36,280 frees, 897,715 bytes allocated
==9212== 
==9212== LEAK SUMMARY:
==9212==    definitely lost: 0 bytes in 0 blocks
==9212==    indirectly lost: 0 bytes in 0 blocks
==9212==      possibly lost: 0 bytes in 0 blocks
==9212==    still reachable: 488 bytes in 1 blocks
==9212==         suppressed: 0 bytes in 0 blocks
==9212== Rerun with --leak-check=full to see details of leaked memory
==9212== 
==9212== Use --track-origins=yes to see where uninitialised values come from
==9212== For lists of detected and suppressed errors, rerun with: -s
==9212== ERROR SUMMARY: 143014 errors from 11 contexts (suppressed: 0 from 0)
