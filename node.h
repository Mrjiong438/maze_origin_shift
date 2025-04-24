#ifndef MAZE_NODE
#define MAZE_NODE

typedef enum {
	Maze_side_no = 0,
	Maze_side_in,
	Maze_side_out
}maze_nodo_side;

typedef struct{
	maze_nodo_side up    :2;
	maze_nodo_side down  :2;
	maze_nodo_side left  :2;
	maze_nodo_side right :2;
}Maze_node;

#endif//MAZE_NODE
