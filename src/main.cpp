#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <random>



SDL_Window* window  = NULL;
SDL_Renderer* renderer = NULL;


class Game_object {
public:
  SDL_Surface* temp_surf;
  SDL_Texture* texture = NULL;

  SDL_Rect src_rect;
  SDL_Rect des_rect;



  void render(){

    texture = SDL_CreateTextureFromSurface(renderer, temp_surf);

    SDL_RenderCopy(renderer, texture, &src_rect, &des_rect);

    SDL_RenderPresent(renderer);

    const int fps = 60;
    const int frame_delay = 1000/fps;
    Uint32 frame_start;
    int frame_time;
    frame_start = SDL_GetTicks();
    frame_time = SDL_GetTicks() - frame_start;
    if (frame_delay > frame_time) {
      SDL_Delay(frame_delay - frame_time);
    }

  }

};


int main(int argc, char *argv[]) {

  const int fps = 60;
  const int frame_delay = 1000/fps;


  //init SDL
  SDL_Init(SDL_INIT_EVERYTHING);
  if (SDL_Init(SDL_INIT_EVERYTHING > 0)) {
    std::cout << "Could not init SDL, Error: " << SDL_GetError() << std::endl;
  }
  else {
    window = SDL_CreateWindow("You Ded", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500 , 500, SDL_WINDOW_SHOWN);

    if (window == NULL) {
      std::cout << "Could not create window, Error: " << SDL_GetError() << std::endl;
    }
    else {
      renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer == NULL) {
        std::cout << "Could not create renderer, Error: " << SDL_GetError() << std::endl;
      }
    }
  }



 

  bool is_running = true;
  SDL_Event event;
  int player_pos_x;
  int player_pos_y;





  while (is_running) {

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        is_running = false;
      }
      else if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_UP:
          player_pos_y -= 1;
          break;
        case SDLK_DOWN:
          player_pos_y += 1;
          break;
        case SDLK_RIGHT:
          player_pos_x += 1;
          break;
        case SDLK_LEFT:
          player_pos_x -= 1;
          break;
        default:
          player_pos_y = player_pos_y;
          player_pos_x = player_pos_x;
        }

      }


    }

    Game_object player;
    player.temp_surf = IMG_Load("player.png");
    player.src_rect.w = 32;
    player.src_rect.h = 32;
    player.src_rect.x = 0;
    player.src_rect.y = 0;
    player.des_rect.x = player_pos_x;
    player.des_rect.y = player_pos_y;
    player.des_rect.w = player.src_rect.w * 2;
    player.des_rect.h = player.src_rect.h * 2;
    player.render();


    //enemies
      Game_object enemy;
      enemy.temp_surf = IMG_Load("enemy.png");
      enemy.src_rect.w = 32;
      enemy.src_rect.h = 32;
      enemy.src_rect.x = 0;
      enemy.src_rect.y = 0;
      enemy.des_rect.x = 200;
      enemy.des_rect.y = 50;
      enemy.des_rect.w = enemy.src_rect.w * 2;
      enemy.des_rect.h = enemy.src_rect.h * 2;
      enemy.render();
      int l1 = player.des_rect.x;
      int r1 = player.des_rect.x + enemy.des_rect.w;
      int t1 = player.des_rect.y;
      int b1 = player.des_rect.y + enemy.des_rect.h;

      int l21 = enemy.des_rect.x;
      int r21 = enemy.des_rect.x + enemy.des_rect.w;
      int t21 = enemy.des_rect.y;
      int b21 = enemy.des_rect.y + enemy.des_rect.h;
      if (l1 > r21 || l21 > r1 ||t1 > b21 || t21 > b1) {
        //std::cout << " not col" << std::endl;
      }
      else {
         std::cout << "you were caught" << std::endl;

        is_running = false;//std::cout << "col" << std::endl;
      }

      Game_object enemy2;
      enemy2.temp_surf = IMG_Load("enemy.png");
      enemy2.src_rect.w = 32;
      enemy2.src_rect.h = 32;
      enemy2.src_rect.x = 0;
      enemy2.src_rect.y = 0;
      enemy2.des_rect.x = 190;
      enemy2.des_rect.y = 150;
      enemy2.des_rect.w = enemy.src_rect.w * 2;
      enemy2.des_rect.h = enemy.src_rect.h * 2;
      enemy2.render();
      int l22 = enemy2.des_rect.x;
      int r22 = enemy2.des_rect.x + enemy.des_rect.w;
      int t22 = enemy2.des_rect.y;
      int b22 = enemy2.des_rect.y + enemy.des_rect.h;
      if (l1 > r22 || l22 > r1 ||t1 > b22 || t22 > b1) {
          //std::cout << "not col" << std::endl;
      }
      else {
        std::cout << "you were caught" << std::endl;
        is_running = false;//std::cout << "col" << std::endl;
      }

      Game_object enemy3;
      enemy3.temp_surf = IMG_Load("enemy.png");
      enemy3.src_rect.w = 32;
      enemy3.src_rect.h = 32;
      enemy3.src_rect.x = 0;
      enemy3.src_rect.y = 0;
      enemy3.des_rect.x = 100;
      enemy3.des_rect.y = 250;
      enemy3.des_rect.w = enemy.src_rect.w * 2;
      enemy3.des_rect.h = enemy.src_rect.h * 2;
      enemy3.render();
      int l23 = enemy3.des_rect.x;
      int r23 = enemy3.des_rect.x + enemy.des_rect.w;
      int t23 = enemy3.des_rect.y;
      int b23 = enemy3.des_rect.y + enemy.des_rect.h;
      if (l1 > r23 || l23 > r1 ||t1 > b23 || t23 > b1) {

      }
      else {
        std::cout << "You were caught" << std::endl;
        is_running = false;//std::cout << "col" << std::endl;
      }

      Game_object escape;
      escape.temp_surf = IMG_Load("escape.png");
      escape.src_rect.w = 32;
      escape.src_rect.h = 32;
      escape.src_rect.x = 0;
      escape.src_rect.y = 0;
      escape.des_rect.x = 380;
      escape.des_rect.y = 380;
      escape.des_rect.w = escape.src_rect.w * 2;
      escape.des_rect.h = escape.src_rect.h * 2;
      escape.render();
      int l24 = escape.des_rect.x;
      int r24 = escape.des_rect.x + enemy.des_rect.w;
      int t24 = escape.des_rect.y;
      int b24 = escape.des_rect.y + enemy.des_rect.h;
      if (l1 > r24 || l24 > r1 ||t1 > b24 || t24 > b1) {
          //is_running = false;//std::cout << "not col" << std::endl;
      }
      else {
        std::cout << "YOu escaped" << std::endl;
        is_running = false;//std::cout << "col" << std::endl;
      }


    }

  
  return 0;
}
