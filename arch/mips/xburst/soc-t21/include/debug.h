#ifndef __JIM_DEBUG_H__
#define __JIM_DEBUG_H__

#define WHEREAMI        pr_info("[DEBUG]: At %s ln. %d (%s)\n", __FILE__, __LINE__, __func__);

void flash_green_led(char count);

#endif /* __JIM_DEBUG_H__ */