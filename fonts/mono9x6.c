
#include <freewpc.h>

DECLARE_PAGED
const uint8_t font_9x6_alpha_cap[][9] = {
	{ 4, 4, 10, 10, 31, 31, 17, 17, 17 },
	{ 7, 7, 9, 9, 7, 9, 9, 7, 7 },
	{ 14, 14, 1, 1, 1, 1, 1, 14, 14 },
	{ 7, 9, 17, 9, 7 },
	{ 31, 31, 1, 31, 31, 1, 1, 31, 31 },

	{ 31, 31, 1, 1, 31, 31, 1, 1, 1 },
	{ 14, 1, 25, 9, 15 },
	{ 17, 17, 17, 31, 31, 17, 17, 17, 17 },
	{ 31, 31, 4, 4, 4, 4, 4, 31, 31 },
	{ 15, 4, 4, 5, 2 },

	{ 17, 9, 7, 9, 17 },
	{ 1, 1, 1, 1, 1, 1, 1, 31, 31 },
	{ 17, 27, 21, 17, 17 },
	{ 17, 19, 21, 25, 17 },
	{ 14, 14, 17, 17, 17, 17, 17, 14, 14 },
	
	{ 15, 15, 17, 17, 15, 15, 1, 1, 1 },
	{ 14, 17, 21, 25, 30 },
	{ 15, 17, 15, 9, 17 },
	{ 14, 14, 1, 1, 14, 16, 16, 14, 14 },
	{ 31, 31, 4, 4, 4, 4, 4, 4, 4 },

	{ 17, 17, 17, 17, 17, 17, 17, 14, 14 },
	{ 17, 17, 17, 17, 10, 10, 10, 4, 4 },
	{ 17, 17, 21, 21, 14 },
	{ 17, 17, 10, 10, 4, 10, 10, 17, 17 },
	{ 17, 17, 17, 10, 10, 4, 4, 4, 4 },
	{ 31, 31, 8, 8, 4, 2, 2, 31, 31 },
};


DECLARE_PAGED
const uint8_t font_9x6_digit[][9] = {
	{ 12, 30, 51, 51, 51, 51, 51, 30, 12 },
	{ 12, 12, 14, 14, 12, 12, 12, 30, 30 },
	{ 30, 63, 48, 24, 12, 6, 3, 63, 63 },
	{ 30, 62, 48, 30, 62, 48, 48, 62, 30 },
	{ 27, 27, 27, 63, 63, 24, 24, 24, 24 },
	{ 63, 63, 3, 15, 31, 48, 48, 31, 15 },
	{ 12, 14, 3, 31, 63, 51, 51, 30, 30 },
	{ 63, 63, 48, 24, 12, 6, 3, 3, 3 },
	{ 12, 30, 51, 51, 30, 51, 51, 30, 12 },
	{ 12, 30, 51, 51, 62, 48, 48, 30, 12 },
};


DECLARE_PAGED
const uint8_t font_9x6_sep[][9] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 0, 0, 0, 0, 0, 0, 2, 2, 1 },
	{ 16, 16, 8, 8, 4, 4, 2, 2, 0 },
};


DECLARE_PAGED
const font_t font_9x6 = {
	.width = 6,
	.spacing = 2,
	.height = 9, 
	.chars = (uint8_t **)font_9x6_alpha_cap, 
	.digits = (uint8_t **)font_9x6_digit,
	.seps = (uint8_t **)font_9x6_sep,
};


