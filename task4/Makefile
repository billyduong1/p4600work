#The name of the program we are going to build
TARGET	  = program

#
CC		= gcc
CFLAGS	= -c -fno-stack-protector
LFLAGS	= 

#Specify build, include and source directories
BUILDDIR  = .
INCDIR    = ./Includes
SRCDIR    = ./Source

#Create a list of all the .c files in the source directory
SOURCES   = $(wildcard $(SRCDIR)/*.c)
#Make another list by replacing all the .c's from the sources list with .o's and change the directory to build
OBJECTS   = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))
#A list of all libraries to be used
LIBRARIES = m

#The gcc option to link an external libary is -l so prefix -l to each library in the list
LIBCMD    = $(addprefix -l,$(LIBRARIES))

#Build each object file from its associated .c source file
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ $<

#Link together the object files and libraries to create the final exectuable
$(TARGET): $(OBJECTS)
	$(CC) $(LFLAGS) -o $@ $^ $(LIBCMD)



