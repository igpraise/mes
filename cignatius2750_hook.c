/*
 *	C to assembler menu hook
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "common.h"

int cignatius2750_add_test(int x, int y, uint32_t delay);

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