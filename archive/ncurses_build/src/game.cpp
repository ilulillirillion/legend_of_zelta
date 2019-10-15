#include <ncurses.h>
#include <cmath>

#include "screen.h"
#include "frame.h"
#include "character.h"


void game_loop(
    Frame &game_map,
    Frame &viewport,
    Character &player_character,
    int user_input,
    Character &monster) {

  // Check if user wants to quit
  if(user_input == 'q' || user_input == 'Q') return;;

  // Add the monster to the game map
  game_map.add(monster);

  // Show the main character on the screen
  game_map.add(player_character);
  viewport.center(player_character);
  viewport.refresh();

  while(true) {
    user_input = getch();


    // Process user input
    // Due to initializing NCurses screens with the keypad property, most 
    // special keys are handled in the background and mapped to set definitions
    // (i.e. KEY_UP, KEY_DOWN)
    // Upward movement
    if(user_input == KEY_UP) {
      game_map.add(player_character, player_character.row() - 1, player_character.column());
      viewport.center(player_character);
      viewport.refresh();
    }

    // Right movement
    else if(user_input == KEY_RIGHT) {
      game_map.add(player_character, player_character.row(), player_character.column() + 1);
      viewport.center(player_character);
      viewport.refresh();
    }

    // Downward movement
    else if(user_input == KEY_DOWN) {
      game_map.add(player_character, player_character.row() + 1, player_character.column());
      viewport.center(player_character);
      viewport.refresh();
    }

    // Left movement
    else if(user_input == KEY_LEFT) {
      game_map.add(player_character, player_character.row(), player_character.column() - 1);
      viewport.center(player_character);
      viewport.refresh();
    }
    else if(user_input == 'q' || 'Q') {
      break;
    }

    // NPC movements
    int pos = -1, score = game_map.height()*game_map.height() + game_map.width()*game_map.width(), dist = -1;
    // Try to move left
    if (game_map.is_moveable(monster.row(), monster.column() - 1)) {
      dist = std::pow(player_character.row() - monster.row(),2) + std::pow(player_character.column() - (monster.column() - 1),2);
      if (score > dist) {
        score = dist;
        pos = 0;
      }
    }
    // Try to move right
    if (game_map.is_moveable(monster.row(), monster.column() + 1)) {
      dist = std::pow(player_character.row() - monster.row(),2) + std::pow(player_character.column() - (monster.column() + 1),2);
      if (score > dist) {
        score = dist;
        pos = 1;
      }
    }
    // Try to move up
    if (game_map.is_moveable(monster.row() - 1, monster.column())) {
      dist = std::pow(player_character.row() - (monster.row() - 1),2) + std::pow(player_character.column() - monster.column(),2);
      if(score > dist) {
        score = dist;
        pos = 2;
      }
    }
    // Try to move down
    if (game_map.is_moveable(monster.row() + 1, monster.column())) {
      dist = std::pow(player_character.row() - (monster.row() + 1),2) + std::pow(player_character.column() - monster.column(),2);
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
    viewport.center(player_character);
    viewport.refresh();

  }
}


// Entrypoint for the game
int main() {

  // Initialize NCurses on the terminal
  Screen scr;

  // Print a welcome message
  scr.add("Welcome to the Legend of Zelta!\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

  // Wait until the user presses a key
  int user_input = getch();

  // Create an NCurses window to store the game map
  Frame game_map(2*scr.height(), 2*scr.width(), 0, 0);

  // Create an NCurses subwindow to serve as a viewport with dimensions
  // equal to the current terminal window and a starting position of 0,0
  Frame viewport(game_map, scr.height(), scr.width(), 0, 0);

  // Initialize the main character
  Character player_character('@', game_map.height()/2, game_map.width()/2);

  // Initialize a single test monster a fixed distance from the player
  Character test_monster('M', player_character.row() + 7, player_character.column() + 22);

  // Generate an outdoor environment using Perlin Noise
  game_map.generate_perlin_environment(211);

  // Start the game loop
  game_loop(game_map, viewport, player_character, user_input, test_monster);

  return 0;

}
