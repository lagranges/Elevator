
EXE=Make/levator

all:$(EXE)

$(EXE):
	$(MAKE) -C src/ 

clear:
	$(MAKE) -C src/ $@ 

run:
	./src/elevator
