My take on the solder fume extractor. It has no filter as it don't trust those anyway - so keep that window open while you solder! 

INFO
 PC-FAN 4-Wire Pinout: https://www.techpowerup.com/forums/attachments/4-pin-fan-wiring-diagram-basic-electronics-wiring-diagram-jpg.159557/

BOM - search on Ali and youl find plenty of options :)
 RP2040 Board (Color: RP2040 TYPE-C 4MB) -> yes this is overkill but i whanted to use a RP2040 for a project...
 Switch momentary:     https://de.aliexpress.com/item/4000164264475.html?spm=a2g0o.order_list.order_list_main.107.3d625c5fIIlSB3&gatewayAdapt=glo2deu
 Potentiomieter 10k:
 Battery 18650
 TP4065 Charger
 Transistor 2N2222 (may not be necessary when using a 5V board, as the signal to the PC-FAN is 5V, didn't test it with 3.3V)
 Resistor 1K
 PC-FAN 90/92mm 4-Wire (3 used -> 12V, GND, PWM)
 Convertter 12V to 5V L7805CV (there may be a design that works without this but i find it convenient to switch power only after the charger module)
 Booster 5V to 12V
 USB-C Power Connector
 6x M5 Screws 6-14mm should work fine
