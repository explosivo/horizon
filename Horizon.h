//
//  Horizon.h
//
//  Created by Zach Nickell on 11/19/14.
//  Copyright (c) 2014 Devious Gamers. All rights reserved.
//

#ifndef __Horizon__
#define __Horizon__

#include "Player.h"
#include "Input.h"

#include <iostream>
#include <string>
#ifdef _WIN32
#include <SDL.h>
#include <SDL_opengl.h>
#elif defined __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#elif defined __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#endif

namespace dg
{
    class Horizon
    {
    public:
        Horizon();
        ~Horizon();
        int WIDTH = 640;
        int HEIGHT = 480;
        const std::string NAME = "Horizon";
        const std::string VERSION = "Experimental";
        
        SDL_Window *window;
		SDL_Renderer *renderer;
        SDL_GLContext glcontext;
		
		const int fpsLimit = 60;
        
		Input input;
		Player player;

        void init();
        void run();
        void stop();
        std::string getTitle();
        virtual void update(int delta);
        void drawFrame();
        virtual void render();
        
    private:
        SDL_Event event;
        bool running;
        int lastDeltaTime;
        int frames;
        int getDelta();
    };
}

#endif /* defined(__Horizon__DeviousEngine__) */
