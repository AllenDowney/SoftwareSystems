# Modify this line to contain the path to the directory that contains
# libmongo.a and src
LIB = mongo-c-driver/src


# The -I flag tells the compiler where to look for include files.

# To compile tutorial.c, I am following the example in the online
# tutorial at http://api.mongodb.org/c/current/tutorial.html

# There, they compile tutorial.c along with all of the source
# files in the MongoDB C driver.  A better option is to compile
# the MongoDB C driver into a library file (.a or .so), and then
# link tutorial.o with the library.  But for now we'll keep it simple.

tutorial: tutorial.c
	gcc --std=gnu99 -I$(LIB) $(LIB)/*.c tutorial.c -o tutorial

test_rand: test_rand.c
	gcc -O3 test_rand.c -o test_rand
