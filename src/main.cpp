#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>

int main() {
    bn::core::init();

    bn::backdrop::set_color((bn::color(22, 5, 20)));
    int count = 60;

    while(true)
    {
        if (count < 60)
        {
            count++;
        }
        else if (bn::keypad::a_held() && bn::keypad::b_held()) 
        {
            bn::backdrop::set_color((bn::color(28, 28, 28)));
            count = 0;
        }
        else if (bn::keypad::a_held())
        {
            bn::backdrop::set_color((bn::color(16, 0, 14)));
            count = 0;
        } else if (bn::keypad::b_held())
        {
            bn::backdrop::set_color((bn::color(28, 5, 26)));
            count = 0;
        } else 
        {
            bn::backdrop::set_color((bn::color(22, 5, 20)));
        }

        bn::core::update();
    }
}