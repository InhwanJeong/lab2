OBJS = add.o subtract.o multiply.o divide.o

Arithmetic : Arithmetic.o add.o subtract.o multiply.o divide.o libArithmetic.a libArithmetic.so
	gcc -o ../makeArithmetic *.o
	cd ..;gcc -o staticArithmetic -I./lib -L./lib/a Arithmetic.c -lArithmetic
Arithmetic.o : Arithmetic.c
	gcc -c Arithmetic.c
add.o : add.c
	gcc -c add.c	
subtract.o : subtract.c
	gcc -c subtract.c	
multiply.o : multiply.c
	gcc -c multiply.c	
divide.o : divide.c
	gcc -c divide.c	
libArithmetic.a : $(OBJS)
	ar rcs libArithmetic.a $(OBJS)
	mv libArithmetic.a a
libArithmetic.so :
	gcc -shared -Wl,-soname,libArithmetic.so.1 -o libArithmetic.so.1.0.1 $(OBJS)
	ln -s libArithmetic.so.1.0.1 libArithmetic.so.1
	ln -s libArithmetic.so.1.0.1 libArithmetic.so
clean :
	rm -f *.o *.a *.so*;
	rm -f ../makeArithmetic
	rm -f ../staticArithmetic
	rm -f ../sharedArithmetic
	rm -f ./a/libArithmetic.a
