#include "Motion.h"

Motion::Motion()
{
    this->z_time = 0;
    this->z_motion = sf::Vector2f(0, 0);
    this->z_tickRemaining = 0;
}

Motion::Motion(sf::Vector2f motion, int time)
{
    this->z_time = time;
    this->z_motion = motion;
    this->z_tickRemaining = time;
}

void Motion::setMotion(sf::Vector2f newMotion)
{
    this->z_motion = newMotion;
}

void Motion::setTime(int newTime)
{
    this->z_time = newTime;
}

void Motion::reset()
{
    this->z_tickRemaining = this->z_time;
}

void Motion::sendTick()
{
    this->z_tickRemaining--;
}

int Motion::getTime()
{
    return this->z_time;
}

sf::Vector2f Motion::getMotion()
{
    return this->z_motion;
}

int Motion::getRemainingTime()
{
    return this->z_tickRemaining;
}
