CC = g++

DEBUG = -g -O0 -Wall
CFLAGS += $(DEBUG) 

STEPGENLIB = -lbcm2835 -lm -pthread

PYTHONCFLAGS = -I/usr/include/python3.5m -I/usr/include/python3.5m  -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.5-6waWnr/python3.5-3.5.3=. -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall -Wstrict-prototypes
PYTHONLDLAGS = -L/usr/lib/python3.5/config-3.5m-arm-linux-gnueabihf -L/usr/lib -lpython3.5m -lpthread -ldl  -lutil -lm  -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions

./sample_app: ./bin/sample_app.o
	$(CC) $(CFLAGS) $<  ./bin/libClearPathMotorSD.so -o $@  $(STEPGENLIB) 

./bin/sample_app.o: ./Sample/SingleAxisDemo.cpp ./bin/libClearPathMotorSD.so
	$(CC) $(CFLAGS) -c  $< -o $@  $(STEPGENLIB)

./bin/libClearPathMotorSD.so:./bin/ClearPathMotorSD.o ./bin/ClearPathMotorSD_wrap.o
	$(CC) -shared ./bin/ClearPathMotorSD.o ./bin/ClearPathMotorSD_wrap.o  -o ./bin/libClearPathMotorSD.so  $(PYTHONLDLAGS) -Wl,--whole-archive  $(STEPGENLIB) -Wl,--no-whole-archive
	rm -f ./bin/ClearPathMotorSD.o 
	rm -f ./bin/ClearPathMotorSD_wrap.o

./bin/ClearPathMotorSD_wrap.o : ./ClearPathMotorSD/ClearPathMotorSD_wrap.cxx
	$(CC) $(CFLAGS) -O2 -c -fPIC  $<  -o $@  $(STEPGENLIB) $(PYTHONCFLAGS)

./bin/ClearPathMotorSD.o : ./ClearPathMotorSD/ClearPathMotorSD.cpp
	$(CC) $(CFLAGS) -c -fPIC $<  -o $@  $(STEPGENLIB)



	
clean :
	rm -f ./bin/*.* 
	rm -f ./bin/*
	rm -f ./sample_app