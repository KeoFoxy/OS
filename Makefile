all: clean
	@echo Enter VAR name
VAR6: 
	gcc keypad.c -o keypad_v6 -D VAR6 -lbcm2835
KeyPad_V8: 
	gcc ./KeyPad/keypad.c -o keypad_AS_SD -D VAR8 -lpigpio
VAR10: 
	gcc keypad.c -o keypad_v10 -D VAR10 -lbcm2835
RFID:
	gcc ./RF-ID-Reader/MFRC522.c ./RF-ID-Reader/spi.c ./RF-ID-Reader/gpio.c ./RF-ID-Reader/rfid_reader.c -o RFID_AS_SD
clean:
	rm -rf rfid_reader

bashMode:
	chmod +x Receiver.sh
	chmod +x Runner.sh
	chmod +x RunAll.sh

