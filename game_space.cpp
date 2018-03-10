#include "game_space.h"

#include <random>

class RandomPositionGenerator {
public:
    RandomPositionGenerator(uint8_t left, uint8_t up, uint8_t right, uint8_t down)
        : width_distribution(left, right)
        , height_distribution(up, down - 1)
    {
    }

    ~RandomPositionGenerator() {}

    Position acquire()
    {
        return {
            width_distribution(generator), height_distribution(generator)
        };
    }

private:
    std::default_random_engine generator;
    std::uniform_int_distribution<int> width_distribution;
    std::uniform_int_distribution<int> height_distribution;
};

GameSpace::GameSpace(uint8_t left, uint8_t up, uint8_t right, uint8_t down)
    : left(left)
    , right(right)
    , up(up)
    , down(down)
    , generator(new RandomPositionGenerator(left, up, right, down))
{
}

GameSpace::~GameSpace() {}

bool GameSpace::contains(const Position& position) const
{
    return position.x >= left && position.x < right && position.y >= up && position.y < down;
}

Position GameSpace::random_position()
{
    return generator->acquire();
}
