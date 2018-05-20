#include "buttonwidget.h"

#include "data_icons.h"

namespace {
    const uint8_t VALUE_FOR_BLINK = 10;

    struct BlinkPair {
        uint8_t mainSprite;
        uint8_t highlightSprite;
    };

    BlinkPair getSpritePair(ButtonWidget::ButtonType type)
    {
        switch (type) {
        case ButtonWidget::BLINK_A:
            return BlinkPair{ 8, 9 };
        case ButtonWidget::BLINK_MENU:
            return BlinkPair{ 6, 7 };
        }

        return BlinkPair{ 0, 0 };
    }
}

ButtonWidget::ButtonWidget(Parameters parameters)
    : parameters(parameters)
    , iconAtlas(getIconsData())
    , count(VALUE_FOR_BLINK)
{
}

void ButtonWidget::update()
{
    count -= 1;
    if (count == 0) {
        count = VALUE_FOR_BLINK;
        highlight = !highlight;
    }
}

void ButtonWidget::display()
{
    auto pair = getSpritePair(parameters.buttonType);

    iconAtlas.setFrame(pair.mainSprite);
    gb.display.drawImage(
        parameters.buttonPlacement.x,
        parameters.buttonPlacement.y,
        iconAtlas);

    if (highlight) {
        iconAtlas.setFrame(pair.highlightSprite);
        gb.display.drawImage(
            parameters.buttonPlacement.x,
            parameters.buttonPlacement.y,
            iconAtlas);
    }

    gb.display.setFontSize(1);
    gb.display.setColor(Color::lightblue);
    gb.display.setCursor(
        parameters.textPlacement.x,
        parameters.textPlacement.y);
    gb.display.println(parameters.text);
}
