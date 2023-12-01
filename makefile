CXX=g++
CFLAGS=-I./inc -g -Wall -Werror -std=c++17 -O3
bin_dir = bin
obj_dir = obj

build: check_bin check_obj bin/enigma

bin/enigma: src/enigma.cpp obj/panel.o obj/reflector.o obj/rotor.o obj/parser.o obj/controller.o
	$(CXX) $(CFLAGS) $^ -o $@


obj/panel.o: src/panel.cpp inc/panel.h
	$(CXX) $(CFLAGS) -c $< -o $@
obj/reflector.o: src/reflector.cpp inc/reflector.h
	$(CXX) $(CFLAGS) -c $< -o $@
obj/rotor.o: src/rotor.cpp inc/rotor.h
	$(CXX) $(CFLAGS) -c $< -o $@
obj/parser.o: src/parser.cpp inc/parser.h
	$(CXX) $(CFLAGS) -c $< -o $@
obj/controller.o: src/controller.cpp inc/controller.h
	$(CXX) $(CFLAGS) -c $< -o $@


check_bin:
	[ -d $(bin_dir) ] || mkdir -p $(bin_dir)

check_obj:
	[ -d $(obj_dir) ] || mkdir -p $(obj_dir)

clean:
	rm -f obj/* bin/*