#include "gameover.h"

#include "data_icons.h"
#include "gametitle.h"

#include <Gamebuino-Meta.h>

#undef min
#undef max

#include <algorithm>
#include <cassert>
#include <vector>

namespace {
    const int TARGET_Y_COORD = 8;
    const uint8_t VALUE_FOR_BLINK = 10;
    const uint8_t SPEED_FOR_SHAKE = 3;
    const char GAME_OVER_TEXT[] = "GAME OVER";
}

class GameOverTitle {
public:
    GameOverTitle()
        : charShifts(strlen(GAME_OVER_TEXT))
    {
        std::fill(charShifts.begin(), charShifts.end(), 0);
    }

    void update()
    {
        if (y_coordinate < TARGET_Y_COORD) {
            y_coordinate += 1;
        } else {
            speedCount -= 1;
            if (speedCount == 0) {
                speedCount = SPEED_FOR_SHAKE;

                const auto keepFirst = charShifts[0];
                std::rotate(charShifts.rbegin(), charShifts.rbegin() + 1, charShifts.rend());
                charShifts[0] = keepFirst;

                if (changeUp) {
                    if (charShifts[0] > -1) {
                        charShifts[0] -= 1;
                    } else {
                        changeUp = false;
                    }
                } else {
                    if (charShifts[0] < 1) {
                        charShifts[0] += 1;
                    } else {
                        changeUp = true;
                    }
                }
            }
        }
    }

    void display()
    {
        gb.display.setColor(Color::lightgreen);
        gb.display.setFontSize(2);

        auto count = 0;

        for (const auto shift : charShifts) {
            const char c = GAME_OVER_TEXT[count];

            if (c != ' ' && c != '\0') {
                gb.display.setCursor(5 + 8 * count, y_coordinate + shift);
                gb.display.print(c);
            }
            count += 1;
        }
    }

private:
    uint8_t y_coordinate = 0;
    std::vector<int8_t> charShifts;
    bool changeUp = true;
    bool speedCount = SPEED_FOR_SHAKE;
};

class RetryOrTitle {
public:
    RetryOrTitle()
        : iconAtlas(getIconsData())
    {
    }

    void update()
    {
        count -= 1;
        if (count == 0) {
            count = VALUE_FOR_BLINK;
            highlight = !highlight;
        }
    }

    void display()
    {
        iconAtlas.setFrame(8);
        gb.display.drawImage(60, 30, iconAtlas);

        if (highlight) {
            iconAtlas.setFrame(9);
            gb.display.drawImage(60, 30, iconAtlas);
        }

        gb.display.setFontSize(1);
        gb.display.setColor(Color::lightblue);
        gb.display.setCursor(5, 35);
        gb.display.println("PLAY AGAIN");
    }

private:
    Gamebuino_Meta::Image iconAtlas;
    bool highlight = false;
    uint8_t count = VALUE_FOR_BLINK;
};

GameOver::GameOver(Score score)
    : score(score)
    , choice(new RetryOrTitle())
    , title(new GameOverTitle())
{
}

void GameOver::update()
{
    if (finished()) {
        return;
    }

    title->update();
    title->display();

    score.display();

    if (timeBeforeRetry > 0) {
        timeBeforeRetry -= 1;
    } else {
        choice->update();
        choice->display();

        if (gb.buttons.pressed(BUTTON_A)) {
            play_again();
        }
    }
}

void GameOver::play_again()
{
    restartGame = true;
}

bool GameOver::finished()
{
    return restartGame;
}

std::unique_ptr<GameState> GameOver::new_state()
{
    assert(restartGame);
    restartGame = false;

    return std::unique_ptr<GameState>(new GameTitle());
}
