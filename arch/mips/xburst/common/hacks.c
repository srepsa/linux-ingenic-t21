#include <linux/jiffies.h>

extern unsigned long exported_msecs_to_jiffies (const unsigned int m) asm ("msecs_to_jiffies");

unsigned long exported_msecs_to_jiffies (const unsigned int m)
{
	if (__builtin_constant_p(m)) {
		if ((int)m < 0)
			return MAX_JIFFY_OFFSET;
		return _msecs_to_jiffies(m);
	} else {
		return __msecs_to_jiffies(m);
	}
}
