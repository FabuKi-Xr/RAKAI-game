#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"

class star
{
public:

    star(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~star();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    int iscollide()
    {
        if (Cstar == 1) {
            Cstar--;
            return 1;
        }
    }

    Collision GetCollider() { return Collision(body); }

private:
    int row;
    int Cstar;
    int collide;
    sf::RectangleShape body;
    Animation animation;
};