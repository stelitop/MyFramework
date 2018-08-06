#include "Button.h"

Button::Button()
{
    this->top = 0;
    this->left = 0;
    this->width = 0;
    this->height = 0;
}
Button::Button(int top, int left, int width, int height)
{
    this->top = top;
    this->left = left;
    this->width = width;
    this->height = height;
}
bool Button::isHovered(sf::RenderWindow * window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    if (mousePos.x >= this->left && mousePos.x <= this->left + this->width && mousePos.y >= this->top && mousePos.y <= this->top + this->height) return true;
    return false;
}
void Button::drawFrame(sf::RenderWindow * window)
{
    sf::VertexArray v(sf::LineStrip, 5);
    v[0] = sf::Vector2f(this->left, this->top);
    v[1] = sf::Vector2f(this->left + this->width, this->top);
    v[2] = sf::Vector2f(this->left + this->width, this->top + this->height);
    v[3] = sf::Vector2f(this->left, this->top + this->height);
    v[4] = sf::Vector2f(this->left, this->top);
    for (int i=0; i<5; i++) v[i].color = sf::Color::White;
    window->draw(v);
}
