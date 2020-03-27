// gcc switch_light.cpp -c
#include "switch_move.h"

GLuint switch_move(GLuint move) { 
  move = move ? 0 : 1;
  return move;
}
