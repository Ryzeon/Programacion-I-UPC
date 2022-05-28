//
// Created by ryzeon on 20/05/22.
//

#include "CC.h"

map<string, string> CC::CONSOLE_COLOR_MAPS = {
        {"0",  "\033[m"}, // Reset
        {"1",  "\033[0;31m"}, // Red
        {"2",  "\033[0;32m"}, // Green
        {"3",  "\033[0;33m"}, // Yellow
        {"4",  "\033[0;34m"}, // Blue
        {"5",  "\033[0;35m"}, // Purple
        {"6",  "\033[0;36m"}, // Cyan
        {"7",  "\033[0;37m"}, // White
        {"8",  "\033[1;30m"}, // Bright Black
        {"9",  "\033[1;31m"}, // Bright Red
        {"10", "\033[1;32m"}, // Bright Green
        {"11", "\033[1;33m"}, // Bright Yellow
        {"12", "\033[1;34m"}, // Bright Blue
        {"13", "\033[1;35m"}, // Bright Purple
        {"14", "\033[1;36m"}, // Bright Cyan
        {"15", "\033[1;37m"}, // Bright Whitea
};

map<string, string> CC::CONSOLE_BACKGROUND_COLOR_MAPS = {
        {"0",  "\033[m"}, // Reset
        {"1",  "\033[0;41m"}, // Red
        {"2",  "\033[0;42m"}, // Green
        {"3",  "\033[0;43m"}, // Yellow
        {"4",  "\033[0;44m"}, // Blue
        {"5",  "\033[0;45m"}, // Magenta
        {"6",  "\033[0;46m"}, // Cyan
        {"7",  "\033[0;47m"}, // White
        {"8",  "\033[1;41m"}, // Red
        {"9",  "\033[1;42m"}, // Green
        {"10", "\033[1;43m"}, // Yellow
        {"11", "\033[1;44m"}, // Blue
        {"12", "\033[1;45m"}, // Magenta
        {"13", "\033[1;46m"}, // Cyan
        {"14", "\033[1;47m"}, // White
};