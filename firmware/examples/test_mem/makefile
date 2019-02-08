PROJECT = test_mem

OUTDIR = out
SRCDIR = src

INCDIRS = $(SRCDIR)

CC = sdcc
CFLAGS = -mmcs51 $(addprefix -I, $(INCDIRS))
LDFLAGS = --code-loc 0x0000 --code-size 0x3000 --xram-loc 0x8000 --xram-size 0x8000

############################################################################

SOURCES = $(shell find $(SRCDIR) -name '*.c')

TARGET_IHX = $(OUTDIR)/$(PROJECT).ihx
TARGET_HEX = $(OUTDIR)/$(PROJECT).hex

OBJECTS = $(addprefix $(OUTDIR)/, $(SOURCES:.c=.rel))
DIRS = $(OUTDIR) $(addprefix $(OUTDIR)/, $(sort $(dir $(wildcard $(SRCDIR)/*/))))

.PHONY: all clean

all: $(DIRS) $(TARGET_HEX)

clean:
	@echo "[Cleaning]"
	@rm -rf $(OUTDIR)

$(DIRS):
	@mkdir -p $@

$(TARGET_HEX): $(TARGET_IHX)
	packihx $< > $@

$(TARGET_IHX): $(OBJECTS)
	@echo "[Linking]" $@
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	

$(OUTDIR)/%.rel: %.c
	@echo "[Compiling]" $@
	$(CC) $(CFLAGS) -c $< -o $@

