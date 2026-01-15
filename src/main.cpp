#include <bn_core.h>
#include <bn_log.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_vector.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>

int main() {
    bn::core::init();

    bn::backdrop::set_color((bn::color(22, 5, 20)));
    int count = 60;

    // bn::sprite_ptr dot_01 = bn::sprite_items::dot.create_sprite(-50, -50);
    // bn::sprite_ptr dot_02 = bn::sprite_items::dot.create_sprite(-50, -25);
    // bn::sprite_ptr dot_03 = bn::sprite_items::dot.create_sprite(-50, 0);
    // bn::sprite_ptr dot_04 = bn::sprite_items::dot.create_sprite(-50, 25);
    // bn::sprite_ptr dot_05 = bn::sprite_items::dot.create_sprite(-50, -50);
    // bn::sprite_ptr dot_06 = bn::sprite_items::dot.create_sprite(-25, -50);
    // bn::sprite_ptr dot_07 = bn::sprite_items::dot.create_sprite(0, -50);
    // bn::sprite_ptr dot_08 = bn::sprite_items::dot.create_sprite(25, -50);

    bn::vector<bn::sprite_ptr, 10> circles = {};

    for(int x = -40; x <= 40; x += 20) 
    {
        circles.push_back(bn::sprite_items::dot.create_sprite(x, x));
        circles.push_back(bn::sprite_items::dot.create_sprite(-x, x));
    }

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