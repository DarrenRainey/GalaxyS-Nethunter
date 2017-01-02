#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"
#include "extendedcommands.h"

int device_handle_key(int key_code, int visible) {
    if (visible) {
        switch (key_code) {
            case KEY_CAPSLOCK:
            case KEY_DOWN:
            case KEY_VOLUMEDOWN:
            // KEY_MENU is intentionally disabled to prevent mispressing the MENU key
            // right before selecting an item with the HOME key
                return HIGHLIGHT_DOWN;

            case KEY_LEFTSHIFT:
            case KEY_UP:
            case KEY_VOLUMEUP:
                return HIGHLIGHT_UP;

            case KEY_HOME:
            case KEY_POWER:
                return SELECT_ITEM;

            case KEY_BACK:
                return GO_BACK;

            default:
                return NO_ACTION;
        }
    }

    return NO_ACTION;
}
