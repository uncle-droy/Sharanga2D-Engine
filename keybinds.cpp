#include "keybinds.h"
#include <SDL.h> // or other necessary headers
#include <stdio.h>
#include <string>
// Convert user string to SDL Scancode


SDL_Scancode getScancodeFromString(const std::string& key) {
    // Numbers
    if (key == "0") return SDL_SCANCODE_0;
    if (key == "1") return SDL_SCANCODE_1;
    if (key == "2") return SDL_SCANCODE_2;
    if (key == "3") return SDL_SCANCODE_3;
    if (key == "4") return SDL_SCANCODE_4;
    if (key == "5") return SDL_SCANCODE_5;
    if (key == "6") return SDL_SCANCODE_6;
    if (key == "7") return SDL_SCANCODE_7;
    if (key == "8") return SDL_SCANCODE_8;
    if (key == "9") return SDL_SCANCODE_9;
    if (key == "KP_ENTER") return SDL_SCANCODE_KP_ENTER;
    if (key == "KP_PLUS") return SDL_SCANCODE_KP_PLUS;
    if (key == "KP_MINUS") return SDL_SCANCODE_KP_MINUS;
    if (key == "KP_MULTIPLY") return SDL_SCANCODE_KP_MULTIPLY;
    if (key == "KP_DIVIDE") return SDL_SCANCODE_KP_DIVIDE;
    if (key == "KP_PERIOD") return SDL_SCANCODE_KP_PERIOD;

    //Other Keys
    if (key == "UP") return SDL_SCANCODE_UP;
    if (key == "DOWN") return SDL_SCANCODE_DOWN;
    if (key == "LEFT") return SDL_SCANCODE_LEFT;
    if (key == "RIGHT") return SDL_SCANCODE_RIGHT;
    if (key == "SPACE") return SDL_SCANCODE_SPACE;
    if (key == "ENTER") return SDL_SCANCODE_RETURN;
    if (key == "ESCAPE") return SDL_SCANCODE_ESCAPE;
    if (key == "TAB") return SDL_SCANCODE_TAB;
    if (key == "BACKSPACE") return SDL_SCANCODE_BACKSPACE;
    if (key == "DELETE") return SDL_SCANCODE_DELETE;
    if (key == "LSHIFT") return SDL_SCANCODE_LSHIFT;
    if (key == "LCTRL") return SDL_SCANCODE_LCTRL;
    if (key == "LALT") return SDL_SCANCODE_LALT;
    if (key == "LGUI") return SDL_SCANCODE_LGUI; // Windows / Command key (Mac)
    if (key == "RGUI") return SDL_SCANCODE_RGUI;
    if (key == "RSHIFT") return SDL_SCANCODE_RSHIFT;
    if (key == "RCTRL") return SDL_SCANCODE_RCTRL;
    if (key == "RALT") return SDL_SCANCODE_RALT;
    if (key == "CAPSLOCK") return SDL_SCANCODE_CAPSLOCK;

    if (key == "PRINTSCREEN") return SDL_SCANCODE_PRINTSCREEN;
    if (key == "SCROLLLOCK") return SDL_SCANCODE_SCROLLLOCK;
    if (key == "PAUSE") return SDL_SCANCODE_PAUSE;
    if (key == "INSERT") return SDL_SCANCODE_INSERT;
    if (key == "HOME") return SDL_SCANCODE_HOME;
    if (key == "END") return SDL_SCANCODE_END;
    if (key == "PAGEUP") return SDL_SCANCODE_PAGEUP;
    if (key == "PAGEDOWN") return SDL_SCANCODE_PAGEDOWN;

    //Operators
    //if (key == "!") return SDL_SCANCODE_KP_EXCLAIM;     // Shift + 1
    if (key == "@") return SDL_SCANCODE_KP_AT;          // Shift + 2
    if (key == "#") return SDL_SCANCODE_KP_HASH;        // Shift + 3
    //if (key == "$") return SDL_SCANCODE_KP_DOLLAR;      // Shift + 4
    if (key == "%") return SDL_SCANCODE_KP_PERCENT;     // Shift + 5
    //if (key == "^") return SDL_SCANCODE__CARET;       // Shift + 6
    if (key == "&") return SDL_SCANCODE_KP_AMPERSAND;   // Shift + 7
    //if (key == "*") return SDL_SCANCODE_KP_ASTERISK;    // Shift + 8
    if (key == "(") return SDL_SCANCODE_KP_LEFTPAREN;   // Shift + 9
    if (key == ")") return SDL_SCANCODE_KP_RIGHTPAREN;
    if (key == "-") return SDL_SCANCODE_MINUS;
    if (key == "=") return SDL_SCANCODE_EQUALS;
    if (key == "[") return SDL_SCANCODE_LEFTBRACKET;
    if (key == "]") return SDL_SCANCODE_RIGHTBRACKET;
    if (key == "\\") return SDL_SCANCODE_BACKSLASH;
    if (key == ";") return SDL_SCANCODE_SEMICOLON;
    if (key == "'") return SDL_SCANCODE_APOSTROPHE;
    if (key == ",") return SDL_SCANCODE_COMMA;
    if (key == ".") return SDL_SCANCODE_PERIOD;
    if (key == "/") return SDL_SCANCODE_SLASH;
    if (key == "`") return SDL_SCANCODE_GRAVE;

    //Function Keys
    if (key == "F1") return SDL_SCANCODE_F1;
    if (key == "F2") return SDL_SCANCODE_F2;
    if (key == "F3") return SDL_SCANCODE_F3;
    if (key == "F4") return SDL_SCANCODE_F4;
    if (key == "F5") return SDL_SCANCODE_F5;
    if (key == "F6") return SDL_SCANCODE_F6;
    if (key == "F7") return SDL_SCANCODE_F7;
    if (key == "F8") return SDL_SCANCODE_F8;
    if (key == "F9") return SDL_SCANCODE_F9;
    if (key == "F10") return SDL_SCANCODE_F10;
    if (key == "F11") return SDL_SCANCODE_F11;
    if (key == "F12") return SDL_SCANCODE_F12;

    //Capital Letters
    if (key == "A") return SDL_SCANCODE_A;
    if (key == "B") return SDL_SCANCODE_B;
    if (key == "C") return SDL_SCANCODE_C;
    if (key == "D") return SDL_SCANCODE_D;
    if (key == "E") return SDL_SCANCODE_E;
    if (key == "F") return SDL_SCANCODE_F;
    if (key == "G") return SDL_SCANCODE_G;
    if (key == "H") return SDL_SCANCODE_H;
    if (key == "I") return SDL_SCANCODE_I;
    if (key == "J") return SDL_SCANCODE_J;
    if (key == "K") return SDL_SCANCODE_K;
    if (key == "L") return SDL_SCANCODE_L;
    if (key == "M") return SDL_SCANCODE_M;
    if (key == "N") return SDL_SCANCODE_N;
    if (key == "O") return SDL_SCANCODE_O;
    if (key == "P") return SDL_SCANCODE_P;
    if (key == "Q") return SDL_SCANCODE_Q;
    if (key == "R") return SDL_SCANCODE_R;
    if (key == "S") return SDL_SCANCODE_S;
    if (key == "T") return SDL_SCANCODE_T;
    if (key == "U") return SDL_SCANCODE_U;
    if (key == "V") return SDL_SCANCODE_V;
    if (key == "W") return SDL_SCANCODE_W;
    if (key == "X") return SDL_SCANCODE_X;
    if (key == "Y") return SDL_SCANCODE_Y;
    if (key == "Z") return SDL_SCANCODE_Z;
    // Small letters
    if (key == "a") return SDL_SCANCODE_A;
    if (key == "b") return SDL_SCANCODE_B;
    if (key == "c") return SDL_SCANCODE_C;
    if (key == "d") return SDL_SCANCODE_D;
    if (key == "e") return SDL_SCANCODE_E;
    if (key == "f") return SDL_SCANCODE_F;
    if (key == "g") return SDL_SCANCODE_G;
    if (key == "h") return SDL_SCANCODE_H;
    if (key == "i") return SDL_SCANCODE_I;
    if (key == "j") return SDL_SCANCODE_J;
    if (key == "k") return SDL_SCANCODE_K;
    if (key == "l") return SDL_SCANCODE_L;
    if (key == "m") return SDL_SCANCODE_M;
    if (key == "n") return SDL_SCANCODE_N;
    if (key == "o") return SDL_SCANCODE_O;
    if (key == "p") return SDL_SCANCODE_P;
    if (key == "q") return SDL_SCANCODE_Q;
    if (key == "r") return SDL_SCANCODE_R;
    if (key == "s") return SDL_SCANCODE_S;
    if (key == "t") return SDL_SCANCODE_T;
    if (key == "u") return SDL_SCANCODE_U;
    if (key == "v") return SDL_SCANCODE_V;
    if (key == "w") return SDL_SCANCODE_W;
    if (key == "x") return SDL_SCANCODE_X;
    if (key == "y") return SDL_SCANCODE_Y;
    if (key == "z") return SDL_SCANCODE_Z;

    return SDL_SCANCODE_UNKNOWN; // If invalid input
}