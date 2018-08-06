#include "Particle.h"

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



Particle::Particle()
{
    this->z_path.empty();
    this->z_position = sf::Vector2f();
    this->z_isRepeated = false;
    this->z_lifespan = 0;
    this->z_totalLife = -1;
    this->name = "";
}

Particle::Particle(sf::Vector2f position, std::vector<Motion> path)
{
    this->z_position = position;
    this->z_path = path;
    this->z_isRepeated = false;
    this->z_lifespan = 0;
    this->z_totalLife = -1;
    this->name = "";
}

void Particle::setRepeated(bool repeat)
{
    this->z_isRepeated = repeat;
}

void Particle::setPosition(sf::Vector2f position)
{
    this->z_position = position;
}
void Particle::setPosition(double x, double y)
{
    this->z_position = sf::Vector2f(x, y);
}

void Particle::setRandom(bool random)
{
    this->z_isRandom = random;
}

void Particle::setRandomSpeed(int speed)
{
    this->z_maxRandSpeed = speed;
}

void Particle::setTotalLife(int life)
{
    this->z_totalLife = life;
}

void Particle::addMotion(Motion added)
{
    this->z_path.push_back(added);
}
void Particle::addMotion(sf::Vector2f motion, int time)
{
    this->z_path.emplace_back(motion, time);
}
void Particle::addMotion(double x, double y, double time)
{
    this->z_path.push_back(Motion(sf::Vector2f(x, y), time));
}

void Particle::resetPath()
{
    this->z_path.empty();
}

void Particle::addTick()
{
    if(this->z_isRandom == false)
    {
        if (this->z_path.size())
        {
            Motion current = this->z_path[0];
            this->z_position.x += current.getMotion().x / double(current.getTime());
            this->z_position.y += current.getMotion().y / double(current.getTime());
            if (current.getRemainingTime() == 1)
            {
                if (this->z_isRepeated == true)
                {
                    this->z_path.emplace_back(this->z_path.front().getMotion(), this->z_path.front().getTime());
                }
                this->z_path.erase(this->z_path.begin());
            }
            else
            {
                this->z_path[0].sendTick();
            }
            this->z_lifespan++;
        }
    }
    else
    {
        int x = rand()%(2*this->z_maxRandSpeed+1) - this->z_maxRandSpeed, y = rand()%(2*this->z_maxRandSpeed+1) - this->z_maxRandSpeed;
        this->z_position += sf::Vector2f(x, y);
        this->z_lifespan++;
    }
}

sf::Vector2f Particle::getPosition()
{
    return this->z_position;
}

bool Particle::getRepeated()
{
    return this->z_isRepeated;
}

std::vector<Motion> Particle::getPath()
{
    return this->z_path;
}

int Particle::getLifespan()
{
    return this->z_lifespan;
}

int Particle::getTotalLife()
{
    return this->z_totalLife;
}

bool Particle::empty()
{
    return this->z_path.size();
}


ParticlePool::ParticlePool()
{
    this->z_usedSize = 0;
}

void ParticlePool::addParticle(Particle newParticle)
{
    if (this->pool.size() == this->z_usedSize)
    {
        this->pool.push_back(newParticle);
    }
    else
    {
        this->pool[this->z_usedSize] = newParticle;
    }
    this->z_usedSize++;
}

int ParticlePool::getSize()
{
    return this->z_usedSize;
}

void ParticlePool::addTick()
{
    for (int i=0; i<this->z_usedSize; i++)
    {
        this->pool[i].addTick();
        if (this->pool[i].getLifespan() == this->pool[i].getTotalLife())
        {
            std::swap(this->pool[this->z_usedSize-1], this->pool[i]);
            this->z_usedSize--;
            i--;
        }
    }
}

void ParticlePool::setSize(int size)
{
    this->z_usedSize = size;
}
