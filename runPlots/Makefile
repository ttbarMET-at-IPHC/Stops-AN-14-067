ObjSuf        = o
SrcSuf        = cc
ExeSuf        = 
DllSuf        = so
OutPutOpt     = -o
HeadSuf       = h

ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs) 

# Linux with egcs
DEFINES       = 

CXX           = g++
CXXFLAGS      = -O -Wall -fPIC $(DEFINES) -Wno-unused-result
CXXFLAGS      += $(ROOTCFLAGS) -I./

LD            = g++ 
LDFLAGS       = -g -O -Wall -fPIC -Wl,--no-undefined 
LDFLAGS       += $(ROOTLIBS)  -lEG -l:`pwd`/../vectorDictionary_C.so -lTMVA

SOFLAGS       = -shared
LIBS          = 

#------------------------------------------------------------------------------
SOURCES       = $(wildcard src/*.cc)
OBJECTS       = $(SOURCES:.$(SrcSuf)=.$(ObjSuf))
#------------------------------------------------------------------------------

all:	runPlots MakeBDTtree_bkg

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $<

%: %.o
	$(LD) $(LDFLAGS) -o $@ $< $(LIBS) 

clean:
	@echo "Cleaning..."
	@rm -f $(OBJECTS)

.SUFFIXES: .$(SrcSuf) .C .o .so
