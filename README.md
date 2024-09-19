# Computer architectures project: Quoridor
This repository contains the code of an ARM-based C program for the game "Quoridor", with the possibility to enable a 2-player mode, by connecting two boards with a CAN bus.

The single-player mode is possible, but the player needs to play with a NPC, which bases its choices on a minimum cost optimization, being very difficult to be defeated by a human, due to the time limit for each turn too.

The choice of the playing mode is up to the players, as well as the human communication, needed to avoid system crashes or deadlock of the systems, since not all possible errors in choosing the mode are handled.

The project is developed using **ARM u-Vision**, a free IDE with a cross-compiler for ARM; it does not need a pro license as long as code dimension is less than 32 KB.

The hardware is an ARM-based MCU (**LPC-17xx)** with a graphical peripheral, which is used as game platform.
