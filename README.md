## Subdirectories for each project.

# EVEE_EXPO_CAR
### Built for EFM32HG222F64 MCU from Silicon Labs
Final code used in engineering expo

### app.c 
High level car controls, executes in while(1) loop, checks for new data from BLE, checks timers for timeout and battery send, and checks NFC reader.
Path is sent from model and received via USART peripheral connected to HM-18 BLE device. Path is then parsed and stored. See path.c for more info.

### path.c
Parses path and stores in a circular buffer array. Uses a read pointer and a write pointer to keep track of the indices to read and write from. Buffer is empty when read and write indices are the same. Buffer is full when write pointer is one behind read pointer. Original implementation used a linked list but the circular buffer allows us to avoid dynamic memory with malloc and free.

### max17043.c
Handles communication with max17043 fuel gauge. Communicates over i2c, depends on i2c.c.

### mfrc522.c
Handles protocols and communication with MFRC522. Communicates over usart peripheral with SPI protocol at 5 Mbit/s. Depends on usart.c driver.

### motor.c
Interprets path commands and sets pwm duty cycles to turn motors. Depends on timer.c and app_pwm_open() for timers to control DRV8212 motor driver.

#### EVEE_AT_DOCK
Code going into acceptance test.


#### EVEE_POC_PCB2
Includes most of EVEE_POC_PWM but with more emphasis on motor control

#### EVEE_POC_PWM
Contains code to communicate with NFC reader. Toggles LED based on ID of tag

#### EVEE_POC_PCB2.sls
This file is a good starting point for new projects (as of 1/20/22)

## To Flash MCU on Custom Hardware
To import: download/pull this file, open simplicity studio v5, go to file>import, browse to the directory where the sls is saved and hit open, the import wizard will now show the project under detected projects, finally hit next to proceed through import. Note: if you want to rename the project it is best to do it in the import menu before hitting finish. 


After import delete the src file within the project if one is auto generated.

See these links for how to configure SSv5.

Internal Team Doc:
https://docs.google.com/document/d/1ju000s5zF7HjwI6fxCQPvtVg8PwAd9hC_2gIVASs3nM/edit

External SI Doc:
https://community.silabs.com/s/article/debugging-an-efm32-product-on-a-custom-board?language=en_US   

