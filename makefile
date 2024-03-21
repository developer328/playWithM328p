CC = avr-gcc
OBJCPY = avr-objcopy
AVRDUDE = avrdude
AVRSIZE = avr-size
PROG = usbasp
MCU = atmega328p
F_CPU = 16000000UL

PORT = usb

CFLAGS = -mmcu=$(MCU) \
	 -F_CPU=$(F_CPU) \
	 -Os \

FILE = t0_norm
	
SRC = $(FILE).c

OBJ = $(FILE).o

HEX = hexFiles/$(FILE).hex

ELF = $(FILE).elf

$(HEX): $(ELF)
	$(OBJCPY) -O ihex $(ELF) $(HEX)

$(ELF): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(ELF)

upload: $(HEX)
	$(AVRDUDE) -p $(MCU) -c $(PROG) -P $(PORT) -b 115200 -U flash:w:$(HEX)

size: $(ELF)
	avr-size --format=avr --mcu=$(MCU) $(ELF)

.PHONY: clean
clean: 
	rm *.elf 
