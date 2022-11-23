CC = gcc
AR = ar
CFLAGS = -g -Wall
OBJECTS_LOOPS = advancedClassificationLoop.o basicClassification.o
OBJECTS_RECURSIVES = advancedClassificationRecursion.o basicClassification.o
OBJECTS_MAIN = main.c NumClass.h
BC = basicClassification.c
ACL = advancedClassificationLoop.c
ACR = advancedClassificationRecursion.c



all : mains maindloop maindrec

mains : loopd main.o  
	$(CC) $(CFLAGS) -o mains main.o recursives 
maindloop : loopd main.o
	$(CC) $(CFLAGS) -o maindloop main.o ./libclassloops.so

maindrec : recursived main.o

# Building static librarie for Loop functions
loops : libclassloops.a
libclassloops.a : $(OBJECTS_LOOPS)
	$(AR) -rc libclassloops.a $(OBJECTS_LOOPS)
advancedClassificationLoop.o : $(ACL)
	$(CC) $(CFLAGS) -c $(ACL)

# Building static librarie for Recursive functions
recursives :  libclassrec.a
libclassrec.a : $(OBJECTS_RECURSIVES)
	$(AR) -rc libclassrec.a $(OBJECTS_RECURSIVES)
advancedClassificationRecursion.o : $(ACR)
	$(CC) $(CFLAGS) -c $(ACR)


loopd : libclassloops.so
libclassloops.so : $(OBJECTS_LOOPS)
	$(CC) -shared -o ./libclassloops.so $(OBJECTS_MAIN)


basicClassification.o : $(BC)
	$(CC) $(CFLAGS) -c $(BC)

main.o : $(OBJECTS_MAIN)
	$(CC) $(CFLAGS) -c main.c




progmaind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o progmaind $(OBJECTS_MAIN) ./libmylib.so
libmylib.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmylib.so $(OBJECTS_LIB)


// recursived : 



// mains :

// maindloop :

// maindrec :

.PHONY: clean all

clean:
	rm -f *.exe *.o *.a *.so mains