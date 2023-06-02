//
// Created by ruben on 22-5-2023.
//

#ifndef DRAWCPP_DRAWMANAGER_H
#define DRAWCPP_DRAWMANAGER_H

#include <iostream>

class drawManager {

public:

    static drawManager* instance;

    static void createInstance()
    {
        drawManager::instance = new drawManager();
    }

    void print()
    {
        std::cout << "heyo" << std::endl;
    }

    drawManager()
    {
        if(drawManager::instance == nullptr)
        {
            drawManager::instance = this;
        } else
        {
            delete(this);
        }
    }

};


#endif //DRAWCPP_DRAWMANAGER_H
