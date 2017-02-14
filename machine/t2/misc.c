
#include <freewpc.h>
#include <mach/sound.h>

CALLSET_ENTRY (misc, sw_left_sling)
{
	sound_send (SND_SLING);
}


CALLSET_ENTRY (misc, sw_right_sling)
{
	sound_send (SND_SLING);
}

CALLSET_ENTRY (misc, sw_left_jet)
{
	sound_send (SND_DATABASE_BEEP1);
}

CALLSET_ENTRY (misc, sw_right_jet)
{
	sound_send (SND_DATABASE_BEEP2);
}

CALLSET_ENTRY (misc, sw_bottom_jet)
{
	sound_send (SND_DATABASE_BEEP3);
}
