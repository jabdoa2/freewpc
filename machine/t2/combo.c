/*
 * Copyright 2017 by Noah Luskey <LuskeyNoah@gmail.com>
 *
 * This file is part of FreeWPC.
 *
 * FreeWPC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * FreeWPC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with FreeWPC; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

/* Combos */

#include <freewpc.h>


CALLSET_ENTRY (combo, start_ball)
{
}


void escape_leff(void)
{
    U8 i;
    for (i = 0; i < 20; i++) {
        leff_toggle(LM_LEFT_LOCK);
        task_sleep(TIME_100MS);
    }
    leff_exit();
}

void ai_leff(void)
{
    U8 i;
    for (i = 0; i < 20; i++) {
        leff_toggle(LM_LEFT_RAMP_MILLION);
        task_sleep(TIME_100MS);
    }
    leff_exit();
}

void command_leff(void)
{
    U8 i;
    for (i = 0; i < 20; i++) {
        leff_toggle(LM_RIGHT_RAMP_MILLION);
        task_sleep(TIME_100MS);
    }
    leff_exit();
}

void chase_leff(void)
{
    U8 i;
    for (i = 0; i < 20; i++) {
        leff_toggle(LM_RIGHT_LOOP);
        task_sleep(TIME_100MS);
    }
    leff_exit();
}

void jets_leff(void)
{
    U8 i;
    for (i = 0; i < 20; i++) {
        leff_toggle(LM_TOP_LANE_LEFT);
        leff_toggle(LM_TOP_LANE_MIDDLE);
        leff_toggle(LM_TOP_LANE_RIGHT);
        task_sleep(TIME_100MS);
    }
    leff_exit();
}


CALLSET_ENTRY(temp, EV_COMMAND_RAMP_MADE) {leff_start(LEFF_COMMAND);}
CALLSET_ENTRY(temp, EV_AI_RAMP_MADE) {leff_start(LEFF_AI);}
CALLSET_ENTRY(temp, EV_CHASE_LOOP_MADE) {leff_start(LEFF_CHASE);}
CALLSET_ENTRY(temp, EV_CHASE_LOOP_TO_JETS) {leff_start(LEFF_JETS);}
CALLSET_ENTRY(temp, EV_ESCAPE_ROUTE_MADE) {leff_start(LEFF_ESCAPE);}
CALLSET_ENTRY(temp, EV_ESCAPE_ROUTE_TO_JETS) {leff_start(LEFF_JETS);}