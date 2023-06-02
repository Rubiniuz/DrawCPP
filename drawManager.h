//
// Created by ruben on 22-5-2023.
//

#ifndef DRAWCPP_DRAWMANAGER_H
#define DRAWCPP_DRAWMANAGER_H

#include <iostream>

class drawManager {

public:
    static drawManager& getInstance()
    {
        static drawManager instance;
        return instance;
    }

    static void draw();

private:
    drawManager() {}

public:
    drawManager(drawManager const&) = delete;
    void operator=(drawManager const&) = delete;

};


#endif //DRAWCPP_DRAWMANAGER_H
