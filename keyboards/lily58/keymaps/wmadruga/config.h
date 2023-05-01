/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MASTER_LEFT
#define QUICK_TAP_TERM 0
#define TAPPING_TERM 250

#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

// Encoder
#ifdef ENCODER_ENABLE
  #define ENCODERS_PAD_A { F5 }
  #define ENCODERS_PAD_B { F4 }
  #define ENCODER_RESOLUTION 2
#endif
