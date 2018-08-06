#ifndef MOTION_H
#define MOTION_H

#include<SFML/Graphics.hpp>

/// @brief The Motion class describes a single step in one direction. Time is the time it will take to move in ticks.
class Motion
{
public:
    Motion();
    Motion(sf::Vector2f motion, int time);

    void setTime(int newTime);
    void setMotion(sf::Vector2f newMotion);
    void reset();
    void sendTick();
    int getTime();
    sf::Vector2f getMotion();
    int getRemainingTime();

private:
    int          z_time;
    sf::Vector2f z_motion;
    int          z_tickRemaining;
};

#endif // MOTION_H
