#include "Enemy.h"
#include<iostream>

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 5;
    body.setSize(sf::Vector2f(90.0f, 108.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Enemy::~Enemy()
{
}

void Enemy::update1(float deltaTime, Bullet bullet1)
{
    animation.updatestar(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (bullet1.GetCollider().CheckCollision(this->GetCollider()))
    {
        std::cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkk";
        count++;
        row = 1;
        body.setPosition(-1000.0f, 350.0f);
    }

}

void Enemy::update2(float deltaTime, Player player)
{
    if (abs(player.GetPosition().x - body.getPosition().x) <= 300.0f)
    {
        velocity.y = 0;
        velocity.x = 80;
        if (player.GetPosition().x < body.getPosition().x) 
        {
            body.move(-velocity * deltaTime);
        }
        else if (player.GetCollider().CheckCollision(this->GetCollider()))
        {
            x1 += 10;
            body.setPosition(-1000.0f, 350.0f);
        }
        animation.updatestar(row, deltaTime);
        body.setTextureRect(animation.uvRect);

        std::cout << "...................................collide !!!!! ";
        /*count++;
        row = 1;
        body.setPosition(-1000.0f, 350.0f);*/
    }

}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(body);
}