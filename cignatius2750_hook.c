/*
 *  C to assembler menu hook
 *
 *  Modified by cignatius2750
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#include "common.h"
#include "stm32f3_discovery_gyroscope.h"


int cignatius2750_lab6(uint32_t delay);
int cignatius2750_lab7(uint32_t delay);

void Lab6_cignatius2750(int action)
{

  if(action==CMD_SHORT_HELP) return;
  if(action==CMD_LONG_HELP) {
    printf("Lab 6\n\n"
	   "This command tests new lab 6 function by cignatius2750\n"
	   );

    return;
  }
  uint32_t delay;
int fetch_status;

fetch_status = fetch_uint32_arg(&delay);

if (fetch_status) {
  delay = 0xFFFFF;
}

printf("cignatius2750_lab6 returned: %d\n", cignatius2750_lab6(delay) );
}

ADD_CMD("cignatius2750_lab6", Lab6_cignatius2750,"Test the new lab 6 function")
void Lab7_cignatius2750(int action)
{
  if(action==CMD_SHORT_HELP) return;
  if(action==CMD_LONG_HELP) {
    printf("Lab 7\n\n"
           "This command tests new lab 7 function by cignatius2750\n"
           );

    return;
  }

  uint32_t count;
uint32_t delay;
uint32_t axis;
int fetch_status;

  fetch_status = fetch_uint32_arg(&count);

  if (fetch_status) {
    count = 10;
  }

  fetch_status = fetch_uint32_arg(&delay);

if (fetch_status) {
  delay = 0xFFFFF;
}

fetch_status = fetch_uint32_arg(&axis);

if (fetch_status) {
  axis = 0;
}

  for (uint32_t i = 0; i < count; i++) {
    float xyz[3] = {0};

    BSP_GYRO_GetXYZ(xyz);

    if (axis == 1) {
  printf("Gyroscope returns:\n"
         " X: %f\n",
         xyz[0] / 256);
}
else if (axis == 2) {
  printf("Gyroscope returns:\n"
         " Y: %f\n",
         xyz[1] / 256);
}
else if (axis == 3) {
  printf("Gyroscope returns:\n"
         " Z: %f\n",
         xyz[2] / 256);
}
else {
  printf("Gyroscope returns:\n"
         " X: %f\n"
         " Y: %f\n"
         " Z: %f\n",
         xyz[0] / 256,
         xyz[1] / 256,
         xyz[2] / 256);
}
    printf("cignatius2750_lab7 returned: %d\n", cignatius2750_lab7(delay) );
  }
}

ADD_CMD("cignatius2750_lab7", Lab7_cignatius2750,"Test the new lab 7 function")

int cignatius2750_a3(char *pattern_ptr);

void A3_cignatius2750(int action)
{

  if(action==CMD_SHORT_HELP) return;
  if(action==CMD_LONG_HELP) {
    printf("Assignment 3 Test\n\n"
	   "This is the A3 function by cignatius2750\n"
	   );

    return;
  }

  int fetch_status;
  char *pattern;

  fetch_status = fetch_string_arg(&pattern);

  if (fetch_status) {
    // Default logic goes here
    pattern = "Test Pattern";
  }

  printf("cignatius2750_a3 returned: %d\n", cignatius2750_a3(pattern) );
}

ADD_CMD("cignatius2750_a3", A3_cignatius2750,"Run A3 for cignatius2750")
