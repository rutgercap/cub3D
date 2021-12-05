# Cub3D

Cub3D is a project inspired by [Wolfenstein3D](http://wolf3d.atw.hu/). The project consists of building a [raycaster](https://en.wikipedia.org/wiki/Ray_casting), 
which is the technology used by the creators of the first 3D games. 
The basic steps in the process are:
- Cast rays that measure the distance of the player to the walls and/or sprites on screen
- Calculate the dimensions of the walls or sprites per ray
- Draw the sprite or wall to an image based on the textures given in the map file

## Learning goals
The project is part of the [Codam](https://www.codam.nl/studying-at-codam) curriculum. The main learning goals are:
- Building a large c program
- Use of complex algorithms
- Use of graphics
- Mathematics in practice
- Information gathering

## Usage

1. Clone this repository
   ```console
   git clone https://github.com/rutgercap/cub3d.git
   ```
2. Create the executable by running make
   ```console
   make
   ```
3. Execute **cub3D** in one of three ways:
* Run as a game with example map in the maps/ folder
   ```console
   make run
   ```
* Run as a game with a of your choice (must have the .cub extension)
   ```console
   ./cub3D path_to_map.cub
   ```
   
 **Screenshot**
 
 ![Example screenshot](/pics/screenshot.bmp)
 
 
## Controls

WASD: Moving
ARROW LEFT/RIGHT: Turning

## Rules

#### Config information
Maps have to be of the **.cub** extension!

Configuration is saved as:
- Resolution: "R: *res_x res_y*"
- North texture: "NO *path_to_texture*"
- South texture: "SO *path_to_texture*"
- West texture: "WE *path_to_texture*"
- East texture: "EA *path_to_texture*"
- Sprite texture: "S *path_to_texture*"
- Floor color: "F *colorcode in RGB*"
- Ceiling color: "C *colorcode in RGB*"
Information can be in any order with newlines in between. Configuration has to be in front of map, and once the map starts all information is needed.

#### Maps

maps can consist of spaces (**NOT tabs or other whitespaces**) and a few possible characters:
- 1: Walls
- 2: Sprites
- 0: Floor
- NSEW: player starting position (letter indicates starting direction)

Rules for a valid ap:
- Floors have to be surrounded by walls
- Maps can only have a single starting position within the walls

### Resources

[Minilibx documentation by Harm Smits](https://harm-smits.github.io/42docs/libs/minilibx)

[Raycasting tutorial from iodev](https://lodev.org/cgtutor/raycasting.html)

### Disclaimer

The entire project is written in accordance with the 42 Network Norm. The norm puts readability above everything and can therefore sometimes be limiting in options for writing the most optimal code.
