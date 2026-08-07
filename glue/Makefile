TARGET   = payload
SRC      = src
INC      = include
LIB      = lib
OBJ      = obj
DEP      = dep
GEN      = $(DEP)/jit/genesis.S
DEP_C    = $(patsubst $(SRC)/%.m,%,$(wildcard $(SRC)/*.m))
DEP_CXX  = $(patsubst $(SRC)/%.mm,%,$(wildcard $(SRC)/*.mm))
IGXX     = xcrun -sdk iphoneos clang++ -arch arm64
FLAGS   ?= -Wall -O3 -fobjc-arc -miphoneos-version-min=10.0 $(CFLAGS)
LFLAGS  ?= -Wl,-x -Wl,-dead_strip -flto -L$(wildcard $(DEP)/curl-*)/lib/.libs -lcurl -L$(DEP)/Meridian -lMeridian -L$(DEP)/doubleH3lix -ldoubleH3lix -L$(LIB) -loffsetfinder64 -limg4tool -lplist++ -lplist -lcompression -lz -larchive -F. -framework IOKit -framework Security $(LDFLAGS)
LFLAGS  += -Wl,-exported_symbols_list,keep.txt
FILES   := $(addsuffix .o, $(addprefix $(OBJ)/c/, $(DEP_C))) $(addsuffix .o, $(addprefix $(OBJ)/c++/, $(DEP_CXX))) $(OBJ)/c/avail_stub.o

.PHONY: all clean distclean

all: $(TARGET)

$(TARGET): $(wildcard $(DEP)/curl-*)/lib/.libs/libcurl.a $(DEP)/doubleH3lix/libdoubleH3lix.a $(DEP)/Meridian/libMeridian.a $(FILES)
	$(IGXX) -o $@ $(FLAGS) $(GEN) $(FILES) $(LFLAGS)

$(OBJ)/c/avail_stub.o: src/avail_stub.c | $(OBJ)/c
	$(IGXX) -c -o $@ $(FLAGS) -xobjective-c -std=gnu11 $< -I$(INC)

$(OBJ)/c/%.o: $(SRC)/%.m | $(OBJ)/c
	$(IGXX) -c -o $@ $(FLAGS) -xobjective-c -std=gnu11 $< -I$(INC)

$(OBJ)/c++/%.o: $(SRC)/%.mm | $(OBJ)/c++
	$(IGXX) -c -o $@ $(FLAGS) -xobjective-c++ -std=gnu++14 $< -I$(INC)

$(OBJ)/c:
	mkdir -p $@

$(OBJ)/c++:
	mkdir -p $@

$(DEP)/doubleH3lix/libdoubleH3lix.a:
	$(MAKE) -C $(DEP)/doubleH3lix headless

$(DEP)/Meridian/libMeridian.a:
	$(MAKE) -C $(DEP)/Meridian all

$(wildcard $(DEP)/curl-*)/lib/.libs/libcurl.a:
	cd $(DEP)/curl-* && ./configure --enable-static --disable-shared --host=aarch64-apple-darwin --without-ssl --with-darwinssl CC='xcrun -sdk iphoneos clang -arch arm64' CFLAGS='-miphoneos-version-min=10.0'
	$(MAKE) -C $(DEP)/curl-* all

clean:
	rm -rf $(TARGET) $(OBJ)

distclean: clean
	$(MAKE) -C $(DEP)/doubleH3lix clean
	$(MAKE) -C $(DEP)/Meridian clean
ifneq (,$(wildcard $(DEP)/curl-*/Makefile))
	$(MAKE) -C $(DEP)/curl-* distclean
endif
