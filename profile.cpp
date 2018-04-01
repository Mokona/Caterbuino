#include <Gamebuino-Meta.h>

void displayProfileInfo()
{
    auto cpu = gb.getCpuLoad();
    auto memory = gb.getFreeRam();

    gb.display.setColor(Color::white);
    gb.display.setFontSize(1);
    gb.display.setCursor(1, 1);
    gb.display.print("CPU:");
    gb.display.print(cpu);

    gb.display.setCursor(1, 8);
    gb.display.print("MEM:");
    gb.display.print(memory);
}
