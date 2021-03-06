/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"

#include "xgpio.h"
#include "xparameters.h"

#include "xuartps_hw.h"

int main()
{
    init_platform();

    XGpio gpio_0, gpio_1, gpio_2;

    int ready = 0;
    int valid = 0;
    int din = 0;

    int y = 0;

    char charArray[11];

    // Initialization routine
    XGpio_Initialize(&gpio_0, XPAR_AXI_GPIO_0_DEVICE_ID);
    XGpio_Initialize(&gpio_1, XPAR_AXI_GPIO_1_DEVICE_ID);
    XGpio_Initialize(&gpio_2, XPAR_AXI_GPIO_2_DEVICE_ID);

    //Code
    //Direction: IN = 1, OUT = 0
    XGpio_SetDataDirection(&gpio_0, 1, 1);
    XGpio_SetDataDirection(&gpio_1, 1, 0);
    XGpio_SetDataDirection(&gpio_2, 1, 0);

    print("Beep boop\n\r");

    while(1)
    {
    	setvbuf(stdin, NULL, _IONBF, 0);
    	for(;;)
    	{
    		valid = 0;
    		XGpio_DiscreteWrite(&gpio_2, 1, valid);

    		do {
    			ready = XGpio_DiscreteRead(&gpio_0, 1);
    		} while(!ready);

    		print("Entrez une valeur pour din: \n");
    		scanf("%10s", charArray);
    		din = atoi(&charArray);
    		valid = 1;
    		XGpio_DiscreteWrite(&gpio_1, 1, din);
    		XGpio_DiscreteWrite(&gpio_2, 1, valid);
    	}


    }

    print("Hello World\n\r");
    print("Successfully ran Hello World application");
    cleanup_platform();
    return 0;
}
