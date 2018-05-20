#include "gamecredits.h"

#include "buttonwidget.h"
#include "gametitle.h"

#include "gamebuino_fix.h"

#include <cassert>

namespace {
    const char* BACK_TEXT = "BACK";
    ButtonWidget::Parameters widgetParameters = {
        { 65, 47 },
        { 48, 52 },
        ButtonWidget::BLINK_MENU,
        BACK_TEXT
    };
}

GameCredits::GameCredits()
    : backToTitleDisplay(new ButtonWidget(widgetParameters))

{
}

void GameCredits::update()
{
    if (gb.buttons.pressed(BUTTON_A) || gb.buttons.pressed(BUTTON_MENU)) {
        back_to_title();
    }

    gb.display.setColor(Color::white);
    gb.display.setFontSize(1);
    gb.display.setCursor(0, 10);
    gb.display.println("  GRAPHICS & DESIGN");
    gb.display.println("    S.GLAIZE");
    gb.display.println("    O.GLAIZE");
    gb.display.println();
    gb.display.println("  CODE");
    gb.display.println("    S.GLAIZE");

    backToTitleDisplay->update();
    backToTitleDisplay->display();
}

void GameCredits::back_to_title()
{
    next_state = true;
}

bool GameCredits::finished()
{
    return next_state;
}

std::unique_ptr<GameState> GameCredits::new_state()
{
    assert(finished());
    next_state = false;
    return std::unique_ptr<GameState>(new GameTitle());
}
