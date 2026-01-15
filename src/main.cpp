#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>

int main() {
    bn::core::init();

    bn::backdrop::set_color((bn::color(22, 5, 20)));

    while(true)
    {
        if (bn::keypad::a_pressed())
        {
            bn::backdrop::set_color((bn::color(16, 0, 14)));
        }

        bn::core::update();
    }
}