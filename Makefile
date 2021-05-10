CC=gcc
SOURCE=
CFLAGS=
main: task1.o mySem.o
	$(CC) -o main task1.o mySem.o
	rm *.o
task1.o: task1.c
	$(CC) -c task1.c
mySem.o: mySem.c
	$(CC) -c mySem.c

msgS: msgServer.o msgCom.o mySem.o
	$(CC) -o msgS msgServer.o msgCom.o mySem.o
	rm *.o

msgC: msgClient.o msgCom.o mySem.o
	$(CC) -o msgC msgClient.o msgCom.o mySem.o
	rm *.o

shm: shm.o mySem.o 
	$(CC) -o shm shm.o mySem.o
	rm *.o

.c.o:
	$(CC) -c $*.c

clean:
	rm main
	rm msgS
	rm msgC
