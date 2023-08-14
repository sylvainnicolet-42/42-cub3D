#!/bin/bash

# Colors
RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

function exec_test()
{
  ./cub3D "$@"
}

# Invalid arguments
printf "\n$BOLDBLUE%s$RESET\n" "--- Invalid arguments ---"
printf "\n$BOLDYELLOW%s$RESET\n" "No arguments: "
exec_test
printf "\n$BOLDYELLOW%s$RESET\n" "More than 2 arguments: "
exec_test tests/maps/map.cub tests/maps/map.cub

# Invalid file
printf "\n$BOLDBLUE%s$RESET\n" "--- Invalid file ---"
printf "\n$BOLDYELLOW%s$RESET\n" "Invalid extension: "
exec_test tests/maps/invalid_extension.cube
printf "\n$BOLDYELLOW%s$RESET\n" "Empty file: "
exec_test tests/maps/empty.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Non-existent file: "
exec_test tests/maps/non_existent.cub

# Open map
printf "\n$BOLDBLUE%s$RESET\n" "--- Open map ---"
printf "\n$BOLDYELLOW%s$RESET\n" "Open up: "
exec_test tests/maps/map_open_up.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Open down: "
exec_test tests/maps/map_open_down.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Open left: "
exec_test tests/maps/map_open_left.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Open right: "
exec_test tests/maps/map_open_right.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Open up with door: "
exec_test tests/maps/map_open_up_door.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Open down with door: "
exec_test tests/maps/map_open_down_door.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Open left with door: "
exec_test tests/maps/map_open_left_door.cub

# Other
printf "\n$BOLDBLUE%s$RESET\n" "--- Other ---"
printf "\n$BOLDYELLOW%s$RESET\n" "Map before textures: "
exec_test tests/maps/map_before_textures.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Map with invalid letter: "
exec_test tests/maps/map_invalid_letter.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Map with invalid line: "
exec_test tests/maps/map_invalid_line.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Map with invalid textures: "
exec_test tests/maps/map_invalid_textures.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Map without map: "
exec_test tests/maps/map_without_map.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Map without textures: "
exec_test tests/maps/map_without_textures.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Map with 3 textures: "
exec_test tests/maps/map_with_3_textures.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Map with duplicate textures: "
exec_test tests/maps/map_with_duplicate_textures.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Map with duplicate map: "
exec_test tests/maps/map_with_duplicate_map.cub
printf "\n$BOLDYELLOW%s$RESET\n" "Map with textures inside map: "
exec_test tests/maps/map_with_textures_inside_map.cub