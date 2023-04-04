#include "main.h"

int main() {
    init();

    while (window.isOpen()) {
        tick();
    }

    end();
    return 0;
}

void init() {
    std::cout << "Hello, World!" << std::endl;

    auto desktopMode = sf::VideoMode::getDesktopMode();
    winX = desktopMode.width / 2;
    winY = desktopMode.height / 2;

    window.create(sf::VideoMode(winX, winY), "SFML works!");
    window.setFramerateLimit(60);
    std::cout << "Created Window with size: " << window.getSize().x << ',' << window.getSize().y << std::endl;

    //init drawing texture
    drawings.create(winX, winY, sf::Color(0, 0, 0,0));
    drawTexture.loadFromImage(drawings);
    drawSprite.setTexture(drawTexture);

    auto* shape = new sf::CircleShape(30.f);
    shape->setFillColor(sf::Color::Green);
    drawVector.push_back(shape);

}

void tick() {

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    checkInputs();
    window.clear(sf::Color(0, 0, 0,0));

    // code to test combination of shapes and pure pixel drawing
    renTexture.create(winX, winY, true);

    // draw shapes onto the texture
    for (auto d : drawVector) {
        renTexture.draw(*d);
    }

    // draw pixels

    // use this to clear sprite
    drawings.create(winX, winY, sf::Color(0, 0, 0,0));

    //draw mouse position pixel
    if(withinWindow(mousePos))
    {
        drawings.setPixel(mousePos.x,mousePos.y, sf::Color(255,0,0));
    }

    //draw the sprite
    drawTexture.update(drawings);
    drawSprite.setTexture(drawTexture);

    renTexture.draw(drawSprite); // draw pixelbuffer Sprite onto the texture
    renTexture.display();

    drawSprite.setTexture(renTexture.getTexture()); // now update a render sprite
    window.draw(drawSprite); // and render it

    window.display();

}

void checkInputs()
{
    mousePos = sf::Mouse::getPosition(window);
    std::cout << mousePos.x << "," << mousePos.y << std::endl;
}

bool withinWindow(std::vector<sf::Vector2i> points)
{
    bool check = true;
    for(auto p : points)
    {
        if(p.x >= 0 && p.x <= winX && p.y >= 0 && p.y <= winY);
        else
        {
            check = false;
        }
    }
    return check;
}

bool withinWindow(sf::Vector2i point)
{
    return point.x >= 0 && point.x <= winX && point.y >= 0 && point.y <= winY;
}

void end() {
    std::cout << "Application shutting down" << std::endl;
}
