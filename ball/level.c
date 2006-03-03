/*   
 * Copyright (C) 2003 Robert Kooima
 *
 * NEVERBALL is  free software; you can redistribute  it and/or modify
 * it under the  terms of the GNU General  Public License as published
 * by the Free  Software Foundation; either version 2  of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT  ANY  WARRANTY;  without   even  the  implied  warranty  of
 * MERCHANTABILITY or  FITNESS FOR A PARTICULAR PURPOSE.   See the GNU
 * General Public License for more details.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "level.h"

/*---------------------------------------------------------------------------*/

int level_load(const char *filename, struct level * level)
/* Load the level 'filename' and fill the 'level' structure */
/* return 1 on success, 0 on error */
{
    strcpy(level->file, filename);
    return 1;
}

void level_dump_info(const struct level * level)
{
    printf("filename:        %s\n"
           "background:      %s\n"
	   "gradiant:        %s\n"
	   "screenshot:      %s\n"
	   "song:            %s\n"
	   "time limit:      %d\n"
	   "goal count:      %d\n",
	   level->file, level->back, level->grad, level->shot, level->song,
	   level->time, level->goal);
}

/*---------------------------------------------------------------------------*/

const char * mode_to_str(int m)
{
    switch (m)
    {
    case MODE_CHALLENGE: return _("Challenge");
    case MODE_NORMAL:    return _("Normal");
    case MODE_PRACTICE:  return _("Practice");
    case MODE_SINGLE:    return _("Single");
    default:             return "???";
    }
}

/*---------------------------------------------------------------------------*/

const char * state_to_str(int m)
{
    switch (m)
    {
    case GAME_NONE:    return _("Aborted");
    case GAME_TIME:    return _("Time-out");
    case GAME_GOAL:    return _("Success");
    case GAME_FALL:    return _("Fall-out");
    default:           return "???";
    }
}

/*---------------------------------------------------------------------------*/
