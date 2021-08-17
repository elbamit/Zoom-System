Output: Lazy_Room.o Lazy_Student.o main.o Responsible_Student.o Room.o Student.o Worker_Room.o Worker_Student.o ZoomSys.o
	g++ Lazy_Room.o Lazy_Student.o main.o Responsible_Student.o Room.o Student.o Worker_Room.o Worker_Student.o ZoomSys.o -o output


main.o: main.cpp Student.h Error.h Lazy_Student.h Responsible_Student.h Worker_Student.h Room.h Lazy_Room.h Worker_Room.h ZoomSys.h
	g++ -c main.cpp


ZoomSys.o: ZoomSys.cpp ZoomSys.h Responsible_Student.h Student.h Error.h Worker_Student.h Lazy_Student.h Room.h
	g++ -c ZoomSys.cpp
	
	
Room.o: Room.cpp Room.h Student.h Error.h Lazy_Room.h Worker_Room.h
	g++ -c Room.cpp
	
	
Lazy_Room.o: Lazy_Room.cpp Lazy_Room.h Room.h Student.h Error.h
	g++ -c Lazy_Room.cpp
	
Worker_Room.o: Worker_Room.cpp Worker_Room.h Room.h Student.h Error.h
	g++ -c Worker_Room.cpp
	
	
Student.o: Student.cpp Student.h Error.h
	g++ -c Student.cpp

Lazy_Student.o: Lazy_Student.cpp Lazy_Student.h Student.h Error.h Room.h
	g++ -c Lazy_Student.cpp


Responsible_Student.o: Responsible_Student.cpp Responsible_Student.h Student.h Error.h Room.h
	g++ -c Responsible_Student.cpp
	
	
Worker_Student.o: Worker_Student.cpp Worker_Student.h Student.h Error.h Room.h
	g++ -c Worker_Student.cpp



clean:
	rm -f *.o 

