#include "buttonwidget.h"

#include "data_icons.h"

namespace {
    const uint8_t VALUE_FOR_BLINK = 10;
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
    iconAtlas.setFrame(8);
    gb.display.drawImage(
        parameters.buttonPlacement.x,
        parameters.buttonPlacement.y,
        iconAtlas);

    if (highlight) {
        iconAtlas.setFrame(9);
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
