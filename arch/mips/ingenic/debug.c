#include <asm/io.h>
#include <linux/delay.h>

#define GPIO_IOBASE             0x10010000
#define GPIO_PORT_OFF   0x1000
#define PXPAT0S         0x44   /* Port Pattern 0 Set Register */
#define PXPAT0C         0x48   /* Port Pattern 0 Clear */
#define PXPAT1C         0x38   /* Port Pattern 1 Clear Reg. */

void flash_green_led(char count) {
    volatile unsigned int* const gpio_port2_pxpat0s = ioremap(GPIO_IOBASE+ 2*GPIO_PORT_OFF + PXPAT0S, 0x4);
    volatile unsigned int* const gpio_port2_pxpat0c = ioremap(GPIO_IOBASE+ 2*GPIO_PORT_OFF + PXPAT0C, 0x4);

    int i;

    for (; count > 0; count--){
        writel(0x800, gpio_port2_pxpat0s);
        for (i = 64; i > 0; i--) asm("nop");
        // udelay(4);  // Wait for a bit, we want the GPIO pin to saturate
        writel(0x800, gpio_port2_pxpat0c);
        for (i = 64; i > 0; i--) asm("nop");
        // udelay(4);
    }

    iounmap(gpio_port2_pxpat0s);
    iounmap(gpio_port2_pxpat0c);

    for (i = 128; i > 0; i--) asm("nop");
}
