TARGETDIR = cd lib;
 
all :
	@for d in $(TARGETDIR)\
	do\
		$(MAKE) -C $$d;\
	done 
	gcc -o sharedArithmetic -I./lib -L./lib Arithmetic.c -Wl,--rpath=/home/inan/sysprogramming/lab2/lib -lArithmetic
	gcc -g -o dbg_sharedArithmetic -I./lib -L./lib Arithmetic.c -Wl,--rpath=/home/inan/sysprogramming/lab2/lib -lArithmetic
	gcc -o dlArithmetic -rdynamic dlArithmetic.c -ldl
	gcc -g -o dbg_dlArithmetic -rdynamic dlArithmetic.c -ldl

clean :
	@for d in $(TARGETDIR)\
	do\
		$(MAKE) -C $$d clean;\
	done 
	rm -rf dlArithmetic
	rm -rf dbg*
