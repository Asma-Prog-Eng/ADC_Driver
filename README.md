Bare metal implementation  of an ADC driver for STM32 development board 
## Features
ADC initialization with tested ADC rewsolution (6-bits, 8-bits) and peripheral clock = 8MHz.
## Requirements
### Hardware
- Nucleo STM32 development board (STM32F411x series)
- Multimeter (optional for debugging)
- Potentiometer
### Software
- STM32CubeIDE or compatible toolchain
## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/Asma-Prog-Eng/ADC_Driver
   
2. Import project into STM32CubeIDE:
File → Import... → Existing Projects into Workspace

3. Rebuild project dependencies

## Usage
Initialization : ADC1_init () ;

Receiving Data 


## Project Structure

├── Core<br />
├── Inc<br />  → uart.h <br />
├── Src<br /> → uart.c<br /> → main.c

## Troubleshooting

No data received:
- Verify baud rate settings
- Check TX/RX pin connections
- Ensure correct clock configuration

Garbage characters:
- Verify clock source accuracy
- Check voltage levels
- 
Overrun errors:
- Increase receive buffer size

## Known Limitations
Limited to 8-bit data words

## Contributing
Pull requests are welcome. For major changes, open an issue first.

## License
MIT License
Copyright (c) [2025] [Asma Askri]
