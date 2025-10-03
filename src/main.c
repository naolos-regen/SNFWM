#include "../include/x11_helpers.h"

int
main (void)
{
	x11_display display;

	if (!x11_init_display (&display)) {
			return (-1);
	}

	x11_set_masks (&display);

	x11_free (&display);

	return (1);
}

