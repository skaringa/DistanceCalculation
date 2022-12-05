.PHONY: clean, mrproper

PROJECT = DistanceCalculation

OBJS = $(addprefix $(OUTDIR)/,\
  DistanceCalculator.o \
  GeodDistanceCalculator.o \
  Point.o \
  Sample.o \
  )

INCLS = \
  DistanceCalculator.h \
  GeodDistanceCalculator.h \
  Point.h \
  ReallySimpleDistanceCalculator.h \
  SimpleDistanceCalculator.h \
  SphereDistanceCalculator.h \
  SphereDistanceHaversineCalculator.h

CC = g++
CFLAGS = -I .

OUTDIR = Release

BIN := $(OUTDIR)/$(PROJECT)

LDLIBS = 

SUFFIXES= .cpp .o
.SUFFIXES: $(SUFFIXES) .

all: $(BIN)

$(OUTDIR):
	mkdir $(OUTDIR)
	
$(OBJS): $(OUTDIR)/%.o: %.cpp $(INCLS)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) : $(OUTDIR) $(OBJS)
	$(CC) $(CFLAGS) $(LDFALGS) $(OBJS) $(LDLIBS) -o $(BIN)

clean:
	rm -rf $(OUTDIR)/*.o

mrproper: clean
	rm -rf $(BIN)
