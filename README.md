# **System Clock**, **NVIC**, **DIO**, **PORT** drivers Implementation on TivaC kit (TM4C123GXL ARM® Cortex®-M4F Based MCU)
This repository is intended for the [Sprints Automotive Software Bootcamp](https://sprints.ai/events/automotive-software-bootcamp-wave-8/) project task of implementing **System Clock**, **NVIC**, **DIO**, **PORT** drivers for the TivaC kit.

## Prerequisites
* You must have gnu gcc compiler to build all the project files.
* Recommended: to download and install [code composer studio](https://software-dl.ti.com/ccs/esd/documents/ccs_downloads.html) as it's the best fit for the TM4C123GXL ARM® Cortex®-M4F Based MCUs.

## Project Structure
Project is statically architectured:
* [MCAL](https://github.com/amr-mostafa/Arm_tm4c123/tree/master/Sprints/tm4c123_firmware/mcal) which has these drivers; **System Clock**, **NVIC**, **DIO**, **PORT**.
* [Config](https://github.com/amr-mostafa/Arm_tm4c123/tree/master/Sprints/tm4c123_firmware/config) which has configuration files for the above drivers.
* [utils](https://github.com/amr-mostafa/Arm_tm4c123/tree/master/Sprints/tm4c123_firmware/utils) which has header files for **bit manipulations**, **types definitions**, **assembly routines to switch between privilege and non-privilege modes**.
* [main](https://github.com/amr-mostafa/Arm_tm4c123/blob/master/Sprints/main.c) which is the application that's just calling the operating functions of NVIC, System Clock, drivers with a small LED blink to test the port driver.

## License
This project is licensed under the GNU General Public License.

