# Quoridor on ARM

## Authors
- [Michele Cazzola](https://github.com/MicheleCazzola)

## General information
**Course**: `Computer architectures` (`Polytechnic of Turin`)  
**Academic Year**: 2023-24, developed from December 2023 to January 2024  
**Main teachers**: Paolo Bernardi, Giorgio Insinga, Francesco Angione  
**Topic**: implementation of game Quoridor on an ARM-based micro-controller, with support for multi-player, multi-board and NPC.

## Details
The software (firmware) hosted in this repository allows the user to enable a 2-player mode, by either:
- connecting _two boards_: the CAN protocol is used, without any additional component
- playing against a NPC: the NPC bases its behavior on a MinMax policy, choosing the move that will increase the most the difference between the distance of the opponent from the goal and its one.

_Note_: this NPC hasn't still lost a match against a human, due to the limited time to make a move too.  
_Other note_: the NPC is extraordinarily fast in choosing, thus two NPCs playing one against the other will show a very fast and predictable match

The choice of the playing mode is completely up to the players, as well as simple human communication.

The project is developed using **ARM u-Vision**, a free IDE with a cross-compiler for ARM; it does not need a pro license as long as code dimension is less than 32 KB (as in this case).  
The hardware is an ARM-based MCU (**LPC-17xx)** with a graphical peripheral, which is used as game platform.
