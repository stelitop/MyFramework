#ifndef BUTTON_H
#define BUTTON_H

#include<SFML/Graphics.hpp>

class Button
{
    public:
        int top, left, width, height;

        /// @brief Default constructor. The button's size is 0x0 and is located at (0;0)
        Button();
        /// @brief Specify the position of the button
        Button(int top, int left, int width, int height);

        /// @brief Returns whether or not the mouse hovers over the button on the specified window
        bool isHovered(sf::RenderWindow * window);
        /// @brief Draws the outline of the hitbox of the button
        void drawFrame(sf::RenderWindow * window);
};

#endif // BUTTON_H
