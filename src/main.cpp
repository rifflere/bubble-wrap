#include <bn_core.h>
#include <bn_log.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_vector.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_sprite_items_lil.h>

#define FLOOR (80 - 4)

int main() {
    bn::core::init();

    // Create background
    bn::backdrop::set_color((bn::color(22, 5, 20)));
    int count = 60;

    // Add circles
    bn::vector<bn::sprite_ptr, 10> circles = {};

    for(int x = -40; x <= 40; x += 20) 
    {
        circles.push_back(bn::sprite_items::dot.create_sprite(x, x));
        circles.push_back(bn::sprite_items::dot.create_sprite(-x, x));
    }

    // Add character
    bn::sprite_ptr lil = bn::sprite_items::lil.create_sprite(-65, 65);

    // Establish physics
    bn::fixed speed = 1.0;
    bn::fixed dy = 0;
    bn::fixed gravity = 0.03;
    bn::fixed jump_strength = 1;

    while (true)
    {
        // Handle character movement
        if (bn::keypad::left_held())
        {
            lil.set_x(lil.x() - speed);
        }
        if (bn::keypad::right_held())
        {
            lil.set_x(lil.x() + speed);
        }
        if (bn::keypad::up_pressed())
        {
            dy -= jump_strength;
        }

        dy += gravity;

        lil.set_y(lil.y() + dy);

        if (lil.y() > FLOOR)
        {
            lil.set_y(FLOOR);
            dy = 0;
        }

        // Handle background color change
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