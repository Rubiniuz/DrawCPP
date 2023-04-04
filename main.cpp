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
    drawings.create(winX, winY, sf::Color(0, 0, 0));
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
    window.clear();

    // use this to clear sprite
    //drawings.create(winX, winY);

    //draw mouse position pixel
    if(mousePos.x >= 0 && mousePos.x <= winX && mousePos.y >= 0 && mousePos.y <= winY)
    {
        drawings.setPixel(mousePos.x,mousePos.y, sf::Color(255,255,255));
    }

    //draw the sprite
    drawTexture.loadFromImage(drawings);
    drawSprite.setTexture(drawTexture);
    window.draw(drawSprite);

    //draw shapes
    for (auto d : drawVector) {
        window.draw(*d);
    }

    window.display();

}

void checkInputs()
{
    mousePos = sf::Mouse::getPosition(window);
    std::cout << mousePos.x << "," << mousePos.y << std::endl;
}

void end() {
    std::cout << "Application shutting down" << std::endl;
}
