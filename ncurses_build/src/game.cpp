#include <ncurses.h>
#include <cmath>

#include "screen.h"
#include "frame.h"
#include "character.h"


void game_loop(
    Frame &game_map,
    Frame &viewport,
    Character &main_char,
    int user_input,
    Character &monster) {

  // Check if user wants to quit
  if(user_input == 'q' || user_input == 'Q') return;;

  // Add the monster to the game map
  game_map.add(monster);

  // Show the main character on the screen
  game_map.add(main_char);
  viewport.center(main_char);
  viewport.refresh();

  while(true) {
    user_input = getch();


    // Process user input
    // Due to initializing NCurses screens with the keypad property, most 
    // special keys are handled in the background and mapped to set definitions
    // (i.e. KEY_UP, KEY_DOWN)
    // Upward movement
    if(user_input == KEY_UP) {
      game_map.add(main_char, main_char.row() - 1, main_char.column());
      viewport.center(main_char);
      viewport.refresh();
    }

    // Right movement
    else if(user_input == KEY_RIGHT) {
      game_map.add(main_char, main_char.row(), main_char.column() + 1);
      viewport.center(main_char);
      viewport.refresh();
    }

    // Downward movement
    else if(user_input == KEY_DOWN) {
      game_map.add(main_char, main_char.row() + 1, main_char.column());
      viewport.center(main_char);
      viewport.refresh();
    }

    // Left movement
    else if(user_input == KEY_LEFT) {
      game_map.add(main_char, main_char.row(), main_char.column() - 1);
      viewport.center(main_char);
      viewport.refresh();
    }
    else if(user_input == 'q' || 'Q') {
      break;
    }

    // NPC movements
    int pos = -1, score = game_map.height()*game_map.height() + game_map.width()*game_map.width(), dist = -1;
    // Try to move left
    if (game_map.is_moveable(monster.row(), monster.column() - 1)) {
      dist = std::pow(main_char.row() - monster.row(),2) + std::pow(main_char.column() - (monster.column() - 1),2);
      if (score > dist) {
        score = dist;
        pos = 0;
      }
    }
    // Try to move right
    if (game_map.is_moveable(monster.row(), monster.column() + 1)) {
      dist = std::pow(main_char.row() - monster.row(),2) + std::pow(main_char.column() - (monster.column() + 1),2);
      if (score > dist) {
        score = dist;
        pos = 1;
      }
    }
    // Try to move up
    if (game_map.is_moveable(monster.row() - 1, monster.column())) {
      dist = std::pow(main_char.row() - (monster.row() - 1),2) + std::pow(main_char.column() - monster.column(),2);
      if(score > dist) {
        score = dist;
        pos = 2;
      }
    }
    // Try to move down
    if (game_map.is_moveable(monster.row() + 1, monster.column())) {
      dist = std::pow(main_char.row() - (monster.row() + 1),2) + std::pow(main_char.column() - monster.column(),2);
      if(score > dist) {
        score = dist;
        pos = 3;
      }
    }
  
    switch(pos) {
      case 0:
        game_map.add(monster, monster.row(), monster.column() - 1);
        break;
      case 1:
        game_map.add(monster, monster.row(), monster.column() + 1);
        break;
      case 2:
        game_map.add(monster, monster.row() - 1, monster.column());
        break;
      case 3:
        game_map.add(monster, monster.row() + 1, monster.column());
        break;
    }
    viewport.center(main_char);
    viewport.refresh();

  }
}


// Entrypoint for the game
int main() {

  // Initialize NCurses
  Screen scr;

  // Print a welcome message
  scr.add("Welcome to the Legend of Zelta!\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

  // Wait until the user presses a key
  int user_input = getch();

  // Create an NCurses window to store the game map
  Frame game_map(2*scr.height(), 2*scr.width(), 0, 0);

  // Create an NCurses subwindow to serve as a viewport
  Frame viewport(game_map, scr.height(), scr.width(), 0, 0);

  // Initialize the main character
  Character main_char('@', game_map.height()/2, game_map.width()/2);

  // Initialize a single test monster a fixed distance from the player
  Character test_monster('M', main_char.row() + 7, main_char.column() + 22);

  // Generate an outdoor environment using Perlin Noise
  game_map.generate_perlin_environment(211);

  // Start the game loop
  game_loop(game_map, viewport, main_char, user_input, test_monster);

  return 0;

}
