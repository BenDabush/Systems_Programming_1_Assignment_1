CC = gcc
AR = ar
CFLAGS = -g -Wall
ALL_OBJFILES = mains maindloop maindrec loops recursives recursived loopd
OBJECTS_LOOPS = advancedClassificationLoop.o basicClassification.o
OBJECTS_RECURSIVES = advancedClassificationRecursion.o basicClassification.o
OBJECTS_MAIN = main.c NumClass.h
BC = basicClassification.c
ACL = advancedClassificationLoop.c
ACR = advancedClassificationRecursion.c


all : $(ALL_OBJFILES)

mains : libclassrec.a main.o  
	$(CC) $(CFLAGS) -o mains main.o libclassrec.a 
maindloop : libclassloops.so main.o
	$(CC) $(CFLAGS) -o maindloop main.o libclassloops.so
maindrec : libclassrec.so main.o
	$(CC) $(CFLAGS) -o maindrec main.o libclassrec.so


# Building static librarie for Loop functions
loops : libclassloops.a
libclassloops.a : $(OBJECTS_LOOPS)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOPS)
advancedClassificationLoop.o : $(ACL)
	$(CC) $(CFLAGS) -c $(ACL)


# Building static librarie for Recursive functions
recursives :  libclassrec.a
libclassrec.a : $(OBJECTS_RECURSIVES)
	$(AR) -rcs libclassrec.a $(OBJECTS_RECURSIVES)
advancedClassificationRecursion.o : $(ACR)
	$(CC) $(CFLAGS) -c $(ACR)


#Building a dynamic library for loop functions
loopd : libclassloops.so
libclassloops.so : $(OBJECTS_LOOPS)
	$(CC) -shared -o ./libclassloops.so $(OBJECTS_LOOPS)


# Building a dynamic library for recursive functions
recursived : libclassrec.so
libclassrec.so : $(OBJECTS_RECURSIVES)
	$(CC) -shared -o ./libclassrec.so $(OBJECTS_RECURSIVES)


# Building basicClassification and main
basicClassification.o : $(BC)
	$(CC) $(CFLAGS) -c $(BC)
main.o : $(OBJECTS_MAIN)
	$(CC) $(CFLAGS) -c main.c


.PHONY: clean all

clean:
	rm -f *.a *.o *.so $(ALL_OBJFILES) 