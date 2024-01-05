INCLUDE:=-I../../kubernetes/include -I../../kubernetes/model -I../../kubernetes/api -I../../kubernetes/config
LIBS:=-L../../kubernetes/build -lkubernetes -lyaml -lwebsockets -L/usr/local/lib
CFLAGS:=-g -fPIC
BIN:=libkube_operations.so  # The output will be a shared library

SRC:=kube_operations.c

.PHONY: all clean

all: $(BIN)

$(BIN): $(SRC)
	gcc -shared $(SRC) $(CFLAGS) $(INCLUDE) $(LIBS) -o $(BIN)

clean:
	rm -f $(BIN)