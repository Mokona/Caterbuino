#pragma once

class LightAnimation {
public:
    LightAnimation();

    void update();
    void go();

private:
    int step = 0;
};
