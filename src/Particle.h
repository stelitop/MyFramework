#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include<ctime>

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
    unsigned int          z_time;
    sf::Vector2f          z_motion;
    unsigned int          z_tickRemaining;
};

class Particle
{
public:
    Particle();
    Particle(sf::Vector2f position, std::vector<Motion> path);

    void setRepeated(bool repeat);
    void setPosition(sf::Vector2f position);
    void setPosition(double x, double y);
    void setRandom(bool random);
    void setRandomSpeed(int speed);
    void setTotalLife(int life);

    void addMotion(Motion added);
    void addMotion(sf::Vector2f motion, int time);
    void addMotion(double x, double y, double time);
    void resetPath();
    void addTick();

    bool getRepeated();
    sf::Vector2f getPosition();
    std::vector<Motion> getPath();
    int getLifespan();
    int getTotalLife();

    bool empty();



    std::string           name;

private:
    sf::Vector2f          z_position;
    std::vector<Motion>   z_path;
    bool                  z_isRepeated;
    bool                  z_isRandom;
    unsigned int          z_lifespan;
    unsigned int          z_maxRandSpeed;
    unsigned int          z_totalLife;

};

class ParticlePool
{
public:
    ParticlePool();

    std::vector<Particle> pool;

    void addParticle(Particle newParticle);
    void addTick();

    int getSize();

    void setSize(int size);

private:
    int z_usedSize;
};

#endif // PARTICLE_H
