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

int main() {
	init_platform();

	XGpio gpio_wdata, gpio_wvalid, gpio_address, gpio_rready, gpio_rdata,
			gpio_rdata_ack, gpio_rvalid, gpio_resp, gpio_resp_ack,
			gpio_resp_valid, gpio_debug_current_state, gpio_axi_awready,
			gpio_axi_wready, gpio_axi_arready;

	// Initialization routine
	XGpio_Initialize(&gpio_wdata, XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_Initialize(&gpio_wvalid, XPAR_AXI_GPIO_1_DEVICE_ID);
	XGpio_Initialize(&gpio_address, XPAR_AXI_GPIO_2_DEVICE_ID);
	XGpio_Initialize(&gpio_rready, XPAR_AXI_GPIO_3_DEVICE_ID);
	XGpio_Initialize(&gpio_rdata, XPAR_AXI_GPIO_4_DEVICE_ID);
	XGpio_Initialize(&gpio_rdata_ack, XPAR_AXI_GPIO_7_DEVICE_ID);
	XGpio_Initialize(&gpio_rvalid, XPAR_AXI_GPIO_5_DEVICE_ID);
	XGpio_Initialize(&gpio_resp, XPAR_AXI_GPIO_6_DEVICE_ID);
	XGpio_Initialize(&gpio_resp_ack, XPAR_AXI_GPIO_9_DEVICE_ID);
	XGpio_Initialize(&gpio_resp_valid, XPAR_AXI_GPIO_8_DEVICE_ID);
	XGpio_Initialize(&gpio_debug_current_state, XPAR_AXI_GPIO_10_DEVICE_ID);
	XGpio_Initialize(&gpio_axi_awready, XPAR_AXI_GPIO_12_DEVICE_ID);
	XGpio_Initialize(&gpio_axi_wready, XPAR_AXI_GPIO_11_DEVICE_ID);
	XGpio_Initialize(&gpio_axi_arready, XPAR_AXI_GPIO_13_DEVICE_ID);

	//Code
	//Direction: IN = 1, OUT = 0
	XGpio_SetDataDirection(&gpio_wdata, 1, 0);
	XGpio_SetDataDirection(&gpio_wvalid, 1, 0);
	XGpio_SetDataDirection(&gpio_address, 1, 0);
	XGpio_SetDataDirection(&gpio_rready, 1, 0);
	XGpio_SetDataDirection(&gpio_rdata, 1, 1);
	XGpio_SetDataDirection(&gpio_rdata_ack, 1, 0);
	XGpio_SetDataDirection(&gpio_rvalid, 1, 1);
	XGpio_SetDataDirection(&gpio_resp, 1, 1);
	XGpio_SetDataDirection(&gpio_resp_ack, 1, 0);
	XGpio_SetDataDirection(&gpio_resp_valid, 1, 1);
	XGpio_SetDataDirection(&gpio_debug_current_state, 1, 1);
	XGpio_SetDataDirection(&gpio_axi_awready, 1, 1);
	XGpio_SetDataDirection(&gpio_axi_wready, 1, 1);
	XGpio_SetDataDirection(&gpio_axi_arready, 1, 1);

	print("Beep boop\n\r");
	print("application ver0_1 \n");

	const int READ_MODE = 0;
	const int WRITE_MODE = 1;

	const int OKAY = 0;
	const int EXOKAY = 1;
	const int SLVERR = 2;
	const int DECERR = 3;

	int wdata = 0;
	int rdata = 0;
	int rvalid = 0;
	int resp = 0;
	int resp_valid = 0;
	int mode = 0;
	int address = 0;

	while (1) {
		setvbuf(stdin, NULL, _IONBF, 0);

		XGpio_DiscreteWrite(&gpio_rready, 1, 0);
		XGpio_DiscreteWrite(&gpio_wvalid, 1, 0);

		for (;;) {

			print("------------------------------- \n");
			print("Mode LECTURE = 0, ECRITURE = 1: \n");

			printf("AWREADY: %d", XGpio_DiscreteRead(&gpio_axi_awready, 1));
			printf("WREADY: %d", XGpio_DiscreteRead(&gpio_axi_wready, 1));
			printf("ARREADY: %d", XGpio_DiscreteRead(&gpio_axi_arready, 1));
			printf("\n");

			scanf("%d", &mode);

			if (mode == READ_MODE) {
				printf("---MODE LECTURE--- \n");
				printf("Adresse de lecture: \n");
				scanf("%d", &address);
				printf("Lecture a l'adresse: %d \n", address);

				printf("AWREADY: %d", XGpio_DiscreteRead(&gpio_axi_awready, 1));
				printf("WREADY: %d", XGpio_DiscreteRead(&gpio_axi_wready, 1));
				printf("ARREADY: %d", XGpio_DiscreteRead(&gpio_axi_arready, 1));
				printf("\n");

				XGpio_DiscreteWrite(&gpio_rdata_ack, 1, 0);
				XGpio_DiscreteWrite(&gpio_resp_ack, 1, 0);

				XGpio_DiscreteWrite(&gpio_address, 1, address);
				XGpio_DiscreteWrite(&gpio_rready, 1, 1);

				do {
					rvalid = XGpio_DiscreteRead(&gpio_rvalid, 1);
					printf("STATE: %d \n", XGpio_DiscreteRead(&gpio_debug_current_state, 1));
					//print("...ATTENTE... \n");

				} while (rvalid != 1);

				print("\n");

				rdata = XGpio_DiscreteRead(&gpio_rdata, 1);
				resp = XGpio_DiscreteRead(&gpio_resp, 1);

				XGpio_DiscreteWrite(&gpio_rready, 1, 0);

				XGpio_DiscreteWrite(&gpio_rdata_ack, 1, 1);
				XGpio_DiscreteWrite(&gpio_resp_ack, 1, 1);

				if (resp == OKAY) {
					printf("SUCCES: OKAY \n");
				} else if (resp == EXOKAY) {
					printf("SUCCES: EXOKAY \n");
				} else if (resp == SLVERR) {
					printf("ECHEC: SLVERR \n");
				} else if (resp == DECERR) {
					printf("ECHEC: DECERR \n");
				} else {
					printf("Erreur dans la valeur de RESP \n");
				}

				printf("Donnee lue: %d \n", rdata);
			} else if (mode == WRITE_MODE) {
				printf("---MODE ECRITURE--- \n");
				printf("Donnee a ecrire: \n");
				scanf("%d", &wdata);
				printf("Adresse de l'ecriture: \n");
				scanf("%d", &address);

				printf("Ecriture a l'adresse %d de la valeur %d \n", address,
						wdata);

				printf("AWREADY: %d", XGpio_DiscreteRead(&gpio_axi_awready, 1));
				printf("WREADY: %d", XGpio_DiscreteRead(&gpio_axi_wready, 1));
				printf("ARREADY: %d", XGpio_DiscreteRead(&gpio_axi_arready, 1));
				printf("\n");

				XGpio_DiscreteWrite(&gpio_address, 1, address);
				XGpio_DiscreteWrite(&gpio_wdata, 1, wdata);
				XGpio_DiscreteWrite(&gpio_wvalid, 1, 1);

				do {
					resp_valid = XGpio_DiscreteRead(&gpio_resp_valid, 1);
					printf("STATE: %d \n",XGpio_DiscreteRead(&gpio_debug_current_state, 1));
					//print("...ATTENTE... \n");
				} while (resp_valid != 1);

				print("\n");

				resp = XGpio_DiscreteRead(&gpio_resp, 1);

				XGpio_DiscreteWrite(&gpio_wvalid, 1, 0);
				XGpio_DiscreteWrite(&gpio_resp_ack, 1, 1);

				if (resp == OKAY) {
					print("SUCCES: OKAY \n");
				} else if (resp == EXOKAY) {
					print("SUCCES: EXOKAY \n");
				} else if (resp == SLVERR) {
					print("ECHEC: SLVERR \n");
				} else if (resp == DECERR) {
					print("ECHEC: DECERR \n");
				} else {
					print("Erreur dans la valeur de RESP \n");
				}
			} else {
				print("S?lectionnez une option entre 0 et 1. \n");
			}
		}
	}

	cleanup_platform();
	return 0;
}
