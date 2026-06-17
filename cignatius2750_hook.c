/*
 *	C to assembler menu hook
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "common.h"

int cignatius2750_add_test(int x, int y, uint32_t delay);
int cignatius2750_a2(int num, int wait);

void AddTest(int action)
{
  if(action==CMD_SHORT_HELP) return;
  if(action==CMD_LONG_HELP) {
    printf("Addition Test\n\n"
       "This command tests new addition function by cignatius2750\n"
       );
    return;
  }

  uint32_t delay;
  int fetch_status;
  fetch_status = fetch_uint32_arg(&delay);
  if(fetch_status) {
    delay = 0xFFFFFF;
  }

  printf("cignatius2750_add_test returned: %d\n", cignatius2750_add_test(99, 87, delay) );
}

  
ADD_CMD("cignatius2750_add", AddTest,"Test the new add function")

void Assignment2(int action)
{
  if(action==CMD_SHORT_HELP) return;
  if(action==CMD_LONG_HELP) {
    printf("Assignment 2\n\n"
           "This command triggers assignment 2 by cignatius2750\n"
           );
    return;
  }
  uint32_t count_input;
  uint32_t delay_input;
  int fetch_status;

  fetch_status = fetch_uint32_arg(&count_input);
  if(fetch_status) {
    // Use a default value
    count_input = 3;
  }

  fetch_status = fetch_uint32_arg(&delay_input);
  if(fetch_status) {
    // Use a default value
    delay_input = 0xFFFFF;
  }

  printf("cignatius2750_a2 returned: %d\n", cignatius2750_a2(count_input, delay_input) );
}

ADD_CMD("cignatius2750_a2", Assignment2, "Assignment 2")
