/* model this after wcs/whatever_driver.c */

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

 /* this file is how one should interact with the cannon. It will (hopefully)
  * prevent balls from being fired at the wrong time or wrong thing
  *
  * See the cannon state machine diagram drawing in machines/t2/notes
  * for a clearer picture of what's going on here (if you're curious)
  */

 #include <freewpc.h>
 #include <stdbool.h>

typedef enum
{
    HOME_STATIONARY=0,
    CANNON_READY,
    HOME_MOVING,
    ON_MARK,
    FIRE_READY,
    FORGOTTEN,
    FIRED,
    GET_HOME,       // like a demand "GET HOME!" (and empty)
    FINDING_HOME    // just gets the cannon home
} cannon_state_t;

cannon_state_t cannon_state;

bool cannon_check_valid_state_transition(const cannon_state_t from, const cannon_state_t to);


void cannon_motor_on(void)
{
    //TODO: implement
}

void cannon_motor_off(void)
{
    //TODO: implement
}

void cannon_enable_firing(void)
{
    //TODO: implement
}

void cannon_disable_firing(void)
{
    //TODO: implement
}

void cannon_set_ball_count(U8 count)
{
    //TODO: implement
}

//
// Force set the cannon_state
// This really shouldn't ever be called by the user. Just me.
// TODO: handle setting the motors and lights and whatever actions
//
void cannon_force_state(const cannon_state_t state)
{
    switch (state) {
    case HOME_STATIONARY:
    case CANNON_READY:
        cannon_motor_off();
        cannon_disable_firing();
        cannon_set_ball_count(1);
        break;
    case HOME_MOVING:
    case ON_MARK:
        cannon_motor_on();
        cannon_disable_firing();
        cannon_set_ball_count(1);
        break;
    case FIRE_READY:
        cannon_motor_on();
        cannon_enable_firing();
        cannon_set_ball_count(1);
        break;
    case FORGOTTEN:
        cannon_motor_on();
        cannon_enable_firing();
        cannon_set_ball_count(0);
        break;
    case FIRED:
        cannon_motor_on();
        cannon_disable_firing();
        cannon_set_ball_count(1);
        break;
    case GET_HOME:
        cannon_motor_off();
        cannon_disable_firing();
        cannon_set_ball_count(1);
        break;
    case FINDING_HOME:
        cannon_motor_on();
        cannon_disable_firing();
        cannon_set_ball_count(1);
        break;
    }
    cannon_state = state;
}

//
// set the state safely - will only allow valid transitions
// if the requested transitions is illegal, nothing happens
// TODO: print some sort of debug message
//
void cannon_set_state(const cannon_state_t state) {
    if (cannon_check_valid_state_transition(cannon_state, state)) {
        cannon_force_state(state);
    } else {
        // TODO: print a debug message
    }
}


//
// return true if the state transition is valid
//
bool cannon_check_valid_state_transition(const cannon_state_t from, const cannon_state_t to)
{
    // not changing state is always valid
    if (from == to) {
        return true;
    }

    // jumping to the GET_HOME state is always valid
    if (to == GET_HOME) {
        return true;
    }

    // here's the real meat and potatoes. See machines/t2/notes
    switch (from) {
    case HOME_STATIONARY:
        return (to == CANNON_READY);
    case CANNON_READY:
        return (to == HOME_MOVING);
    case HOME_MOVING:
        return (to == ON_MARK);
    case ON_MARK:
        return (to == FIRE_READY);
    case FIRE_READY:
        return (to == FORGOTTEN) || (to == FIRED);
    case FORGOTTEN:
        return (to == FIRED);
    case FIRED:
        return (to == HOME_STATIONARY);
    case GET_HOME:
        return (to == FINDING_HOME) || (to == HOME_MOVING) || (to == HOME_STATIONARY);
    case FINDING_HOME:
        return (to == GET_HOME);
    default:
        return false;
        // TODO: print some debug that this should NEVER happen
    }
}


// At the start/end of the ball, make sure the cannon is empty and home
CALLSET_ENTRY(cannon, start_ball, end_ball)
{
    cannon_set_state(GET_HOME);
}