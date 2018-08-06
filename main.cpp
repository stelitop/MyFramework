#include<iostream>
#include<SFML/Graphics.hpp>
#include<ctime>
#include<cstdlib>
#include<cstdio>

#include"Particle.h"


using namespace std;
using namespace sf;

int main()
{
    srand(time(0));
    sf::Time tick = sf::milliseconds(5);
    /// Main Window
    RenderWindow window(VideoMode(800, 600), "");

    ParticlePool particlePool;

    Particle p;
    p.addMotion(0, 40, 6);
    p.name = "Rain";
    p.setRepeated(true);

    CircleShape c;
    c.setFillColor(Color::White);
    c.setRadius(3);

    while (window.isOpen())
    {
        p.setTotalLife(window.getSize().y*3/20 + 1);
        ///Code
        int xCoord = rand()%(window.getSize().x*3/2) - window.getSize().x/2;
        p.setPosition(xCoord, 0);
        particlePool.addParticle(p);

        xCoord = rand()%(window.getSize().x*3/2) - window.getSize().x/2;
        p.setPosition(xCoord, 0);
        particlePool.addParticle(p);

        xCoord = rand()%(window.getSize().x*3/2) - window.getSize().x/2;
        p.setPosition(xCoord, 0);
        particlePool.addParticle(p);

        xCoord = rand()%(window.getSize().x*3/2) - window.getSize().x/2;
        p.setPosition(xCoord, 0);
        particlePool.addParticle(p);

        xCoord = rand()%(window.getSize().x*3/2) - window.getSize().x/2;
        p.setPosition(xCoord, 0);
        particlePool.addParticle(p);

        /// Tick waiting
        sf::Clock tickTimer;
        tickTimer.restart();
        while (tickTimer.getElapsedTime() < tick);

        /// Executing Events
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::Resized)
            {
                View v;
                v.setCenter(window.getSize().x/2, window.getSize().y/2);
                v.setSize(window.getSize().x, window.getSize().y);
                window.setView(v);
            }
        }
        /// Rendering
        window.clear();

        for (int i=0; i<particlePool.getSize(); i++)
        {
            VertexArray v(Lines, 2);
            v[0].position = particlePool.pool[i].getPosition();
            v[1].position = particlePool.pool[i].getPosition() + Vector2f(0, 8);
            v[0].color = Color(0, 155, 255);
            v[1].color = Color(0, 155, 255);
            window.draw(v);

           //c.setPosition(particlePool.pool[i].getPosition() - Vector2f(3, 3));
           //window.draw(c);
        }
        particlePool.addTick();

        window.display();

        cout<<"Particles: "<<particlePool.pool.size()<<endl;
    }
    return 0;
}
