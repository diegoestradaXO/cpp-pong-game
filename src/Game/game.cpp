#include <iostream>
#include "game.h"
#include <include/SDL.h>

Game::Game (){

}

Game::~Game (){

}
void Game::init(const char* title, int width, int height){
    std::cout << "Game Setup..." << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, 0,0, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    isRunning = true;
};


void Game::setup(){
    std::cout << "Game Setup..." << std::endl;
};
void Game::handleEvents(){
    std::cout << "Game Handling events..." << std::endl;
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            isRunning = false;
        }
    }
};
void Game::update(){
    std::cout << "Game Updating..." << std::endl;
};
void Game::render(){
    std::cout << "Game Rendering..." << std::endl;
    SDL_SetRenderDrawColor(renderer, 50, 50, 100, 1);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
};
void Game::clean(){
    std::cout << "Game Cleaning..." << std::endl;
};
bool Game::running(){
    return isRunning; 
};