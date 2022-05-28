//
// Created by ryzeon on 20/05/22.
//

#include <iostream>
#include <map>
#include <regex>
#include <utility>

using namespace std;

#ifndef UNIDAD_3_CC_H
#define UNIDAD_3_CC_H

class CC {
public:
    static map<string, string> CONSOLE_COLOR_MAPS;

    static map<string, string> CONSOLE_BACKGROUND_COLOR_MAPS;

    static string color(string input) {
        string output = std::move(input);
        output = findConsoleColorRegex(output);
        output = findConsoleBackgroundRegex(output);
        return output;
    }

    static string findConsoleColorRegex(const string &input) {
        // Regex for console colors is som lioke this example:
        // &1Hi&2xd // input
        // CONSOLE_COLOR_MAPS["1"}HiCONSOLE_COLOR_MAPS["2"]xd // output
        // Remember in an input can be found more than one console color
        // so we need to find all of them and replace them with the correct
        string output = input;
        // Example text is &1Hello &2World&3!&4 // So the rebex only detect the first one and replace it with the correct one beacuse the second one is anothe color or background color or nothing
        // Match the first console color
        regex colorRegex("&([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        smatch match;
        while (regex_search(output, match, colorRegex)) {
            // Get the console color
            string consoleColor = match.str(1);
            // Get the console color from the map
            string consoleColorMap = CONSOLE_COLOR_MAPS[consoleColor];
            // Replace the first console color with the correct one not all text because loop needs to find another console color
            output = regex_replace(output, colorRegex, consoleColorMap, regex_constants::format_first_only);
        }
        output += CONSOLE_COLOR_MAPS["0"];
        return output;
    }

    static string findConsoleBackgroundRegex(const string &input) {
        // Regex for console colors is ^[number]
        string output = input;
        regex colorRegex("%([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
        smatch match;
        while (regex_search(output, match, colorRegex)) {
            // Get the console color
            string consoleColor = match.str(1);
            // Get the console color from the map
            string consoleColorMap = CONSOLE_BACKGROUND_COLOR_MAPS[consoleColor];
            // Replace the first console color with the correct one not all text because loop needs to find another console color
            output = regex_replace(output, colorRegex, consoleColorMap, regex_constants::format_first_only);
        }
        output += CONSOLE_BACKGROUND_COLOR_MAPS["0"];
        return output;
    }
};


#endif //UNIDAD_3_CC_H
