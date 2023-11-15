# # Compiler and flags
# CC = gcc
# CFLAGS = -no-pie

# # Libraries and includes
# LIBS = /usr/lib64/libXbgi.a -lX11 -lm

# # Source file
# SRC = program0.c

# # Output directory and file (with default values)
# OUT_DIR = output_directory
# OUT_FILE = output_program0

# # You can pass parameters as flags
# # Example: make OUT_DIR=my_output_directory OUT_FILE=my_output_program0
# ifdef OUT_DIR
#     OUT_DIR_FLAG = -DOUT_DIR=$(OUT_DIR)
# endif

# ifdef OUT_FILE
#     OUT_FILE_FLAG = -DOUT_FILE=$(OUT_FILE)
# endif

# all: $(OUT_DIR)/$(OUT_FILE)

# $(OUT_DIR)/$(OUT_FILE): $(SRC)
# 	$(CC) $(SRC) $(LIBS) $(CFLAGS) $(OUT_DIR_FLAG) $(OUT_FILE_FLAG) -o $(OUT_DIR)/$(OUT_FILE)

# clean:
# 	rm -f $(OUT_DIR)/$(OUT_FILE)
