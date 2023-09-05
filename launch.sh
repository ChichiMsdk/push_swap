#!/bin/bash
gcc -fsanitize=undefined -g printers.c movement.c push_swap.c push_swap_utils.c sorter_backup.c -F frame/ -framework SDL2 -framework SDL2_mixer -framework SDL2_ttf && DYLD_FRAMEWORK_PATH=/Users/chmoussa/push_swap/frame ./a.out > log
