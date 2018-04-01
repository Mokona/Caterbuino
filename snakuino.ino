#include <Gamebuino-Meta.h>

// Because Arduino has min/max macros that conflicts with STL
#undef max
#undef min

#include "gameinit.h"
#include "profile.h"

#include <memory>

std::unique_ptr<GameState> game;

void setup()
{
    gb.begin();
    gb.setFrameRate(25);

    game = create_game();
}

void loop()
{
    while (!gb.update())
        ;
    gb.display.clear();

    game->update();

    static bool displayProfile = false;
    if (gb.buttons.pressed(BUTTON_B)) {

        displayProfile = !displayProfile;
    }
    if (displayProfile) {
        displayProfileInfo();
    }

    if (game->finished()) {
        auto newGameState = game->new_state();
        if (newGameState) {
            game.reset(newGameState.release());
        }
    }
}
