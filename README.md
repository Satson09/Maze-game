# Maze

## Creating a 3D Maze with Raycasting using C and SDL2

### Introduction
The Maze Project is an immersive game built in C using SDL (Simple DirectMedia Layer). Embark on a journey through intricate mazes, utilizing raycasting for realistic rendering. This project aims to combine learning with interactive gameplay, offering a hands-on experience in game development. Dive in and explore the world of 3D gaming with The Maze Project!

## Note: 
This project is still under development. More features and functions are being tested and added over time, and existing features may be revised for improvements.

## Features
- 2D maze exploration
- Basic enemy AI
- Collision detection
- Camera movement
- Rain effect for enhanced visual experience

## Project Blogs & Articles
- **Satson**: [The Maze - A 3D Game Development Venture](https://medium.com/@satsunjohnson/the-maze-a-3d-game-development-venture-ef4396136283)
- **MucheruM**: [Portfolio Project Blog Post - Creating a Maze Game](https://www.linkedin.com/pulse/portfolio-project-blog-post-creating-maze-game-peter-mucheru-eij0f)
- **Kathyslate**: [My 3D Maze Game](https://www.linkedin.com/pulse/my-3d-maze-game-oyetunde-mercy-ok65f)

## Authors
- **Satson Bamidele Johnson** - [LinkedIn](https://www.linkedin.com/in/satson-johnson-03b253153/) - [Email](mailto:satsunjohnson@gmail.com)
- **Mucheru Maina** - [LinkedIn](https://www.linkedin.com/in/peter-mucheru-heru/) - [Email](mailto:petermucheru420@gmail.com)
- **Oyetunde Mercy Omobolaji** - [LinkedIn](https://www.linkedin.com/in/oyetunde-mercy-44b186292?trk=contact-info) - [Email](mailto:mercyoyetunde98@gmail.com)

## Requirements
- GNU Make
- GCC
- SDL2
- SDL2_image

## Installation
### Clone the Repository
```bash
git clone https://github.com/Kathyslate/The-Maze.git
```

### Ubuntu Focal 20.04 LTS Works Best

### Windows
#### Open PowerShell and Install WSL
```bash
wsl --install
```

#### Open WSL Terminal and Update Packages
```bash
sudo apt update && sudo apt upgrade -y
```

#### Install Build Essentials
```bash
sudo apt install build-essential -y
```

#### Install SDL2 Libraries
```bash
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev -y
```

#### Install the X Server for Graphical Display
1. **Download & Install XLaunch (VcXsrv)**
   - Install with default settings.

2. **Start XLaunch with These Settings:**
   - Multiple Windows ✅
   - Start No Client ✅
   - Disable Access Control ✅
   - Native OpenGL ✅
   - Click Finish to start XLaunch.

3. **Set DISPLAY Variable:**
   ```bash
   export DISPLAY=:0
   ```
   If using WSL2, set DISPLAY dynamically:
   ```bash
   export DISPLAY=$(ip route | awk '/default/ {print $3}'):0
   ```
   To make it permanent:
   ```bash
   echo "export DISPLAY=$(ip route | awk '/default/ {print $3}'):0" >> ~/.bashrc
   source ~/.bashrc
   ```

4. **Check X Server Connectivity:**
   ```bash
   ping $(ip route | awk '/default/ {print $3}')
   netstat -an | grep 6000
   ```
   If no output, restart XLaunch.

5. **Allow X Server Access:**
   ```bash
   xhost +
   ```

6. **Test GUI:**
   ```bash
   xclock
   ```
   If this works, SDL2 applications should run properly.

### Linux
```bash
sudo apt update && sudo apt upgrade -y
sudo apt install build-essential -y
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev -y
```

## Compiling
```bash
make
```

## Running
After successfully compiling, run the program using the following command:
```bash
./maze
```

## Usage
### Controls
- **W or ↑** : Move forward
- **S or ↓** : Move backward
- **A or ←** : Rotate camera left
- **D or →** : Rotate camera right
- **Q** : Strafe left
- **E** : Strafe right
- **F** : Toggle fullscreen
- **ESC** : Quit
- **SPACE** : Shooting

<h3> Game video Link : https://youtu.be/mFxf3RqtrC4 </h3>

## Source Files
- **main.c** - Entry point of the game
- **shootweapon.c** - Weapon handling
- **loadTexture.c** - Texture rendering functions
- **input.c** - Quit, define maze map, check input for movement handling
- **maze.c** - Main game handling
- **raycaster.c** - Wall rendering and collision detection
- **parseMap.c** - Collision detection
- **render.c** - Rendering walls, background, weapon parsing
- **SDL.c** - Closing texture render & update
- **rain.c** - Rain effect implementation

## Contributors
1. **Fork the repository**
2. **Create a new branch**
   ```bash
   git checkout -b feature-branch
   ```
3. **Commit your changes**
   ```bash
   git commit -am 'Add new feature'
   ```
4. **Push to the branch**
   ```bash
   git push origin feature-branch
   ```
5. **Create a new Pull Request**

## Resources
- [SDL2 API](https://wiki.libsdl.org/FrontPage)
- [LazyFoo Beginning Game Programming](http://lazyfoo.net/tutorials/SDL/index.php)
- [Ray-Casting Tutorial by F. Permadi](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [LodeV Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- *Game Engine Black Book*

