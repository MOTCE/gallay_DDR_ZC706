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

#define NUMBER_OF_STRING 17
#define MAX_STRING_SIZE 40

#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"

#include "xgpio.h"
#include "xparameters.h"

#include "xuartps_hw.h"

void printState(int state);

int main() {
	init_platform();

	print("Running burst_app_v0_3_7... \n");

	init_platform();

	XGpio gpio_wreq, gpio_rreq, gpio_wvalid, gpio_wlast, gpio_wack, gpio_awaddr,
			gpio_wdata, gpio_awlen, gpio_awburst, gpio_wresp_ack, gpio_rready,
			gpio_rack, gpio_araddr, gpio_arlen, gpio_arburst, gpio_rresp_ack,
			gpio_wfifo_ready, gpio_wresp_valid, gpio_wresp, gpio_rresp,
			gpio_rvalid, gpio_rdata, gpio_rresp_valid, gpio_debug_state,
			gpio_awready, gpio_wready, gpio_arready;

	// Initialization routine
	XGpio_Initialize(&gpio_wreq, XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_Initialize(&gpio_rreq, XPAR_AXI_GPIO_1_DEVICE_ID);
	XGpio_Initialize(&gpio_wvalid, XPAR_AXI_GPIO_2_DEVICE_ID);
	XGpio_Initialize(&gpio_wlast, XPAR_AXI_GPIO_3_DEVICE_ID);
	XGpio_Initialize(&gpio_wack, XPAR_AXI_GPIO_4_DEVICE_ID);
	XGpio_Initialize(&gpio_awaddr, XPAR_AXI_GPIO_5_DEVICE_ID);
	XGpio_Initialize(&gpio_wdata, XPAR_AXI_GPIO_6_DEVICE_ID);
	XGpio_Initialize(&gpio_awlen, XPAR_AXI_GPIO_7_DEVICE_ID);
	XGpio_Initialize(&gpio_awburst, XPAR_AXI_GPIO_8_DEVICE_ID);
	XGpio_Initialize(&gpio_wresp_ack, XPAR_AXI_GPIO_9_DEVICE_ID);
	XGpio_Initialize(&gpio_rready, XPAR_AXI_GPIO_10_DEVICE_ID);
	XGpio_Initialize(&gpio_rack, XPAR_AXI_GPIO_11_DEVICE_ID);
	XGpio_Initialize(&gpio_araddr, XPAR_AXI_GPIO_12_DEVICE_ID);
	XGpio_Initialize(&gpio_arlen, XPAR_AXI_GPIO_13_DEVICE_ID);
	XGpio_Initialize(&gpio_arburst, XPAR_AXI_GPIO_14_DEVICE_ID);
	XGpio_Initialize(&gpio_rresp_ack, XPAR_AXI_GPIO_15_DEVICE_ID);
	XGpio_Initialize(&gpio_wfifo_ready, XPAR_AXI_GPIO_16_DEVICE_ID);
	XGpio_Initialize(&gpio_wresp_valid, XPAR_AXI_GPIO_17_DEVICE_ID);
	XGpio_Initialize(&gpio_wresp, XPAR_AXI_GPIO_18_DEVICE_ID);
	XGpio_Initialize(&gpio_rresp, XPAR_AXI_GPIO_19_DEVICE_ID);
	XGpio_Initialize(&gpio_rvalid, XPAR_AXI_GPIO_20_DEVICE_ID);
	XGpio_Initialize(&gpio_rdata, XPAR_AXI_GPIO_21_DEVICE_ID);
	XGpio_Initialize(&gpio_rresp_valid, XPAR_AXI_GPIO_22_DEVICE_ID);
	XGpio_Initialize(&gpio_debug_state, XPAR_AXI_GPIO_23_DEVICE_ID);
	XGpio_Initialize(&gpio_awready, XPAR_AXI_GPIO_24_DEVICE_ID);
	XGpio_Initialize(&gpio_wready, XPAR_AXI_GPIO_25_DEVICE_ID);
	XGpio_Initialize(&gpio_arready, XPAR_AXI_GPIO_26_DEVICE_ID);

	//Code
	//Direction: IN = 1, OUT = 0
	XGpio_SetDataDirection(&gpio_wreq, 1, 0);
	XGpio_SetDataDirection(&gpio_rreq, 1, 0);
	XGpio_SetDataDirection(&gpio_wvalid, 1, 0);
	XGpio_SetDataDirection(&gpio_wlast, 1, 0);
	XGpio_SetDataDirection(&gpio_wack, 1, 0);
	XGpio_SetDataDirection(&gpio_awaddr, 1, 0);
	XGpio_SetDataDirection(&gpio_wdata, 1, 0);
	XGpio_SetDataDirection(&gpio_awlen, 1, 0);
	XGpio_SetDataDirection(&gpio_awburst, 1, 0);
	XGpio_SetDataDirection(&gpio_wresp_ack, 1, 0);
	XGpio_SetDataDirection(&gpio_rready, 1, 0);
	XGpio_SetDataDirection(&gpio_rack, 1, 0);
	XGpio_SetDataDirection(&gpio_araddr, 1, 0);
	XGpio_SetDataDirection(&gpio_arlen, 1, 0);
	XGpio_SetDataDirection(&gpio_arburst, 1, 0);
	XGpio_SetDataDirection(&gpio_rresp_ack, 1, 0);
	XGpio_SetDataDirection(&gpio_wfifo_ready, 1, 1);
	XGpio_SetDataDirection(&gpio_wresp_valid, 1, 1);
	XGpio_SetDataDirection(&gpio_wresp, 1, 1);
	XGpio_SetDataDirection(&gpio_rresp, 1, 1);
	XGpio_SetDataDirection(&gpio_rvalid, 1, 1);
	XGpio_SetDataDirection(&gpio_rdata, 1, 1);
	XGpio_SetDataDirection(&gpio_rresp_valid, 1, 1);
	XGpio_SetDataDirection(&gpio_debug_state, 1, 1);

	XGpio_SetDataDirection(&gpio_awready, 1, 1);
	XGpio_SetDataDirection(&gpio_wready, 1, 1);
	XGpio_SetDataDirection(&gpio_arready, 1, 1);

	const int READ_MODE = 0;
	const int WRITE_MODE = 1;

	const int OKAY = 0;
	const int EXOKAY = 1;
	const int SLVERR = 2;
	const int DECERR = 3;

	int mode = 0;

	int read_addr = 0;
	int read_len = 0;
	int read_burst = 0;
	int read_resp = 0;

	int write_addr = 0;
	int write_len = 0;
	int write_burst = 0;
	int write_data = 0;
	int write_resp = 0;

	while (1) {
		setvbuf(stdin, NULL, _IONBF, 0);
		for (;;) {
			printf("-------------------------");
			printf("LECTURE = 0, ECRITURE = 1");
			printf("------------------------- \n");

			printState(XGpio_DiscreteRead(&gpio_debug_state, 1));
			printf("AWREADY: %d ; WREADY: %d ; ARREADY: %d \n",
					XGpio_DiscreteRead(&gpio_awready, 1),
					XGpio_DiscreteRead(&gpio_wready, 1),
					XGpio_DiscreteRead(&gpio_arready, 1));

			scanf("%d", &mode);

			if (mode == READ_MODE) {
				printf("Adresse de lecture: \n");
				scanf("%d", &read_addr);
				printf("%d \n", read_addr);
				printf("Nombre de donn?es ? lire: \n");
				scanf("%d", &read_len);
				printf("%d \n", read_addr);

				if (read_len > 1) {
					XGpio_DiscreteWrite(&gpio_arburst, 1, 1); // INCR burst
				} else {
					XGpio_DiscreteWrite(&gpio_arburst, 1, 0); // FIXED burst
				}

				XGpio_DiscreteWrite(&gpio_araddr, 1, read_addr);
				XGpio_DiscreteWrite(&gpio_arlen, 1, read_len - 1);

				XGpio_DiscreteWrite(&gpio_rready, 1, 1); // READY to read

				XGpio_DiscreteWrite(&gpio_rack, 1, 0); // READ ACK set to 0
				XGpio_DiscreteWrite(&gpio_rresp_ack, 1, 0); // READ RESP ACK set to 0

				XGpio_DiscreteWrite(&gpio_rreq, 1, 1); // READ request
				XGpio_DiscreteWrite(&gpio_wreq, 1, 0); // NOT WRITE request

				do {
					printf("Attente r?ponse valide en lecture, STATE: %d \n",
							XGpio_DiscreteRead(&gpio_debug_state, 1));
					printf("AWREADY: %d ; WREADY: %d ; ARREADY: %d \n",
							XGpio_DiscreteRead(&gpio_awready, 1),
							XGpio_DiscreteRead(&gpio_wready, 1),
							XGpio_DiscreteRead(&gpio_arready, 1));
				} while (XGpio_DiscreteRead(&gpio_rresp_valid, 1) != 1);

				for (int rdata_n = 0; rdata_n < read_len; rdata_n++) {
					while (XGpio_DiscreteRead(&gpio_rvalid, 1) != 1) {
						printf("Attente donn?e valide en lecture, STATE: %d \n",
								XGpio_DiscreteRead(&gpio_debug_state, 1));
						printf("AWREADY: %d ; WREADY: %d ; ARREADY: %d \n",
								XGpio_DiscreteRead(&gpio_awready, 1),
								XGpio_DiscreteRead(&gpio_wready, 1),
								XGpio_DiscreteRead(&gpio_arready, 1));
					}

					XGpio_DiscreteWrite(&gpio_rready, 1, 0); // Not READY to receive a new READ data before printing current READ data
					XGpio_DiscreteWrite(&gpio_rack, 1, 1); // ACK READ data

					printf("| %d | \n", XGpio_DiscreteRead(&gpio_rdata, 1)); // Print READ data
					XGpio_DiscreteWrite(&gpio_rready, 1, 1); // READY to receive a new READ data
				}

				read_resp = XGpio_DiscreteRead(&gpio_rresp, 1);

				if (read_resp == 0) {
					print("OKAY \n");
				} else if (read_resp == 1) {
					print("EXOKAY \n");
				} else if (read_resp == 2) {
					print("SLVERR \n");
				} else if (read_resp == 3) {
					print("DECERR \n");
				} else {
					printf("ERREUR INCONNUE. \n");
				}

				XGpio_DiscreteWrite(&gpio_rreq, 1, 0);
				XGpio_DiscreteWrite(&gpio_rresp_ack, 1, 1);

			} else if (mode == WRITE_MODE) {
				printf("Adresse d'?criture: \n");
				scanf("%d", &write_addr);
				printf("%d \n", write_addr);
				printf("Nombre de donn?es ? ?crire: \n");
				scanf("%d", &write_len);
				printf("%d \n", write_len);
				printf("AWREADY: %d ; WREADY: %d ; ARREADY: %d \n",
						XGpio_DiscreteRead(&gpio_awready, 1),
						XGpio_DiscreteRead(&gpio_wready, 1),
						XGpio_DiscreteRead(&gpio_arready, 1));

				if (write_len > 1) {
					XGpio_DiscreteWrite(&gpio_awburst, 1, 1); // INCR burst
				} else {
					XGpio_DiscreteWrite(&gpio_awburst, 1, 0); // FIXED burst
				}

				XGpio_DiscreteWrite(&gpio_awaddr, 1, write_addr);
				XGpio_DiscreteWrite(&gpio_awlen, 1, write_len - 1);

				XGpio_DiscreteWrite(&gpio_wack, 1, 0); // NOT WRITE ACK
				XGpio_DiscreteWrite(&gpio_wresp_ack, 1, 0); // NOT WRITE RESP ACK
				XGpio_DiscreteWrite(&gpio_wlast, 1, 0); // NOT LAST data

				XGpio_DiscreteWrite(&gpio_rreq, 1, 0); // NOT READ request
				XGpio_DiscreteWrite(&gpio_wreq, 1, 1); // WRITE request

				for (int wdata_n = 0; wdata_n < write_len; wdata_n++) {
					printf("Donn?e %d : \n", wdata_n + 1);
					scanf("%d", &write_data);
					printf("%d \n", write_data);
					XGpio_DiscreteWrite(&gpio_wdata, 1, write_data); // WRITE data

					if (wdata_n == write_len - 1) {
						XGpio_DiscreteWrite(&gpio_wlast, 1, 1); // LAST WDATA
					} else {
						XGpio_DiscreteWrite(&gpio_wlast, 1, 0); // NOT LAST WDATA
					}

					XGpio_DiscreteWrite(&gpio_wvalid, 1, 1); // WDATA valid

					do {
						printf("Attente FIFO pr?te pour ?criture, STATE: %d \n",
								XGpio_DiscreteRead(&gpio_debug_state, 1));
						printf("AWREADY: %d ; WREADY: %d ; ARREADY: %d \n",
								XGpio_DiscreteRead(&gpio_awready, 1),
								XGpio_DiscreteRead(&gpio_wready, 1),
								XGpio_DiscreteRead(&gpio_arready, 1));
					} while ((XGpio_DiscreteRead(&gpio_wfifo_ready, 1) != 1)
							&& (wdata_n != write_len - 1));

					XGpio_DiscreteWrite(&gpio_wvalid, 1, 0); // WDATA not valid
					XGpio_DiscreteWrite(&gpio_wack, 1, 1); // WRITE ACK
				}

				do {
					printf("Attente MEMOIRE pr?te pour ?criture, STATE: %d \n",
							XGpio_DiscreteRead(&gpio_debug_state, 1));
					printf("AWREADY: %d ; WREADY: %d ; ARREADY: %d \n",
							XGpio_DiscreteRead(&gpio_awready, 1),
							XGpio_DiscreteRead(&gpio_wready, 1),
							XGpio_DiscreteRead(&gpio_arready, 1));
				} while (XGpio_DiscreteRead(&gpio_wresp_valid, 1) != 1);

				write_resp = XGpio_DiscreteRead(&gpio_wresp, 1);

				if (write_resp == 0) {
					print("OKAY \n");
				} else if (write_resp == 1) {
					print("EXOKAY \n");
				} else if (write_resp == 2) {
					print("SLVERR \n");
				} else if (write_resp == 3) {
					print("DECERR \n");
				} else {
					printf("ERREUR INCONNUE. \n");
				}

				XGpio_DiscreteWrite(&gpio_wreq, 1, 0); // NOT WRITE request
				XGpio_DiscreteWrite(&gpio_wresp_ack, 1, 1); // WRITE RESP ACK

			} else {
				printf("VEUILLEZ CHOISIR ENTRE 0 et 1. \n");
			}

		}
	}

	cleanup_platform();
	return 0;
}

void printState(int state) {
	char arr[NUMBER_OF_STRING][MAX_STRING_SIZE] = { "RESET", "IDLE",
			"WRITE_FIFO_WAIT", "WRITE_FIFO", "WRITE_FIFO_WAIT_ACK",
			"AWRITE_MEM_WAIT", "FIRST_WRITE_MEM", "WRITE_MEM", "WRITE_MEM_RESP",
			"READ_ADDR_WAIT", "READ_MEM_WAIT", "READ_MEM_2_FIFO",
			"READ_MEM_WAIT_GPIO", "READ_FIFO_2_GPIO", "READ_WAIT_ACK",
			"READ_WAIT_READY", "READ_FIFO_RESP" };
	printf("STATE: %s \n", arr[state], strlen(arr[state]));
}
