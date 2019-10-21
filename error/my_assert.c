#include <stdio.h> 
#include <assert.h> 
#include <stdlib.h>

char *name;

void my_assert(int expression){
	if(expression == 0){
		printf("%s: %s: %d: %s: '((num >= 0) && (num <= 100))' failed.\n" \
		, name,__FILE__, __LINE__, __func__);
		abort();
	}
}
 
void foo(int num) { 
	my_assert( ((num >= 0) && (num <= 100)) ); 
	
	printf("foo: num = %d\n", num); 
} 
	
main(int argc, char *argv[]){ 
	int num; 
	name = argv[0];
		
	if (argc < 2) { 
		fprintf(stderr, "Usage: assert_test aNumber\n (0 <= aNumber <= 100)\n");
		exit(1); 
	} 
		
	num = atoi(argv[1]); 
	foo(num);
}
