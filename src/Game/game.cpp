#include <iostream>
#include "game.h"
#include <include/SDL.h>


SDL_Rect ball;
SDL_Rect paddlePlayer1;
int speed = 5;


Game::Game (){
    counter = 0;
    FPS = 60;
    frameDuration = (1.0f / FPS) * 1000.0f; //miliseconds
    counter = 0;
}

Game::~Game (){

}
void Game::init(const char* title, int width, int height){
    std::cout << "Game Setup..." << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, 0,0, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    isRunning = true;
    window_width = width;
    window_height = height;
};


void Game::setup(){
    std::cout << "Game Setup..." << std::endl;
    ball.x = 300;
    ball.y = 20;
    ball.w = 15;
    ball.h = 15;

    paddlePlayer1.w = 100;
    paddlePlayer1.h = 20;
    paddlePlayer1.x = (window_width / 2) - (paddlePlayer1.w /2);
    paddlePlayer1.y = window_height - paddlePlayer1.h;
};

void Game::frameStart(){

    std::cout << "--- Frame: " << counter << " ---" << std::endl;

    frameStartTimestamp = SDL_GetTicks();

    dT = frameEndTimeStamp - frameStartTimestamp;

};

void Game::frameEnd(){
    std::cout << "--- ---" << std::endl;
    frameEndTimeStamp = SDL_GetTicks();
    float actualFrameDuration = frameEndTimeStamp - frameStartTimestamp;
    if(actualFrameDuration < frameDuration){
        SDL_Delay(frameDuration - actualFrameDuration);
    }
    counter++;
    std::cout << " " << std::endl;
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

int dx = -1;
int dy = 1;


// GAME LOGIC
void Game::update(){
    std::cout << "Game Updating..." << std::endl;

    // if it crashes bottom of the window
    if((ball.y + ball.h) >= window_height){
        dy *= -1;
    }

    // if it crashes right side of the window
    if((ball.x + ball.w) >= window_width){
        dx *= -1;
    }

    // if it crashes left side of the window
    if(ball.x <= 0){
        dx *= -1;
    }

    // if it crases top side of the window
    if(ball.y <= 0){
        dy *= -1;
    }

    // ball movement
    ball.x += speed * dx;
    ball.y += speed * dy;
};
void Game::render(){
    std::cout << "Game Rendering..." << std::endl;
    SDL_SetRenderDrawColor(renderer, 10, 10, 30, 1);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    SDL_RenderFillRect(renderer, &ball);
    SDL_RenderFillRect(renderer,&paddlePlayer1);
    SDL_RenderPresent(renderer);

};


void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Over..." << std::endl;
};

bool Game::running(){
    return isRunning; 
};