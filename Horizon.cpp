//
//  Horizon.cpp
//
//  Created by Zach Nickell on 11/19/14.
//  Copyright (c) 2014 Devious Gamers. All rights reserved.
//

#include "Horizon.h"
using namespace dg;

Horizon::Horizon()
{
    frames = 0;
    lastDeltaTime = SDL_GetTicks();
}

Horizon::~Horizon()
{
}

void Horizon::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not initialize. SDL Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        
        window = SDL_CreateWindow(getTitle().c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            std::cout << "Window could not be created. SDL Error: " << SDL_GetError() << std::endl;
        }
        else
        {
            glcontext = SDL_GL_CreateContext(window);
            
            glOrtho(0.0f, WIDTH, HEIGHT, 0.0f, -1.0f, 1.0f);
            
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            
        }
    }
}

void Horizon::run()
{
    int time = 0;
    int delta;
    if (!running)
    {
        running = true;
    }
    
    while (running)
    {
        delta = getDelta();
        if ((time += delta) >= 1000)
        {
            std::string title = getTitle() + " fps: " + std::to_string(frames);
            SDL_SetWindowTitle(window, title.c_str());
            frames = 0;
            time = 0;
        }
        while (SDL_PollEvent(&event))
        {
            //input.updateInput(event);
            
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
            }
        }
        update(delta);
        drawFrame();
    }
    stop();
}

void Horizon::stop()
{
    SDL_GL_DeleteContext(glcontext);
    SDL_Quit();
}

void Horizon::update(int delta)
{
}

void Horizon::drawFrame()
{
    frames ++;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    render();
    SDL_GL_SwapWindow(window);
}

void Horizon::render()
{
}


int Horizon::getDelta()
{
    int delta = SDL_GetTicks() - lastDeltaTime;
    lastDeltaTime = SDL_GetTicks();
    return delta;
    
}

std::string Horizon::getTitle()
{
    std::string title;
    
    title = NAME + " - " + VERSION;
    
    return title;
}

int main(int argc, char* args[])
{
	Horizon horizon;
	horizon.init();
	horizon.run();
}
