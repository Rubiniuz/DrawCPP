//
// Created by Ruben Engelage on 04/04/2023.
//

#ifndef DRAWCPP_MAIN_H
#define DRAWCPP_MAIN_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <vector>
#include "drawManager.h"

int main();
void init();
void tick();
void end();

void checkInputs();
bool withinWindow(std::vector<sf::Vector2i> points);
bool withinWindow(sf::Vector2i point);
//OLD
static sf::RenderWindow window;
std::vector<sf::Drawable*> drawVector;

unsigned int winX;
unsigned int winY;

sf::Vector2i mousePos;

sf::Image drawings;
sf::Texture drawTexture;
sf::RenderTexture renTexture;
sf::Sprite drawSprite;


#endif //DRAWCPP_MAIN_H
