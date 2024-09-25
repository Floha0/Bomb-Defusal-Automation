# Keep Talking and Nobody Explodes Console Helper
This console application assists players of **Keep Talking and Nobody Explodes** by providing guidance on what actions to take at each level. The app covers a total of 12 levels, focusing on various modules and puzzles.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Levels](#levels)
- [Contributing](#contributing)
- [License](#license)

## Features
- Interactive console interface.
- Provides instructions based on game logic.
- Covers 12 distinct levels with unique challenges.

## Installation
To run this application, ensure you have a C++ compiler installed on your system. Follow these steps to set up the project:
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/keep-talking-console-helper.git
   cd keep-talking-console-helper
   ```
2. Compile the source files:
   ```bash
   g++ -o keep_talking src/main.cpp src/basicWire.cpp src/maze.cpp src/button.cpp src/keypad.cpp src/simonSays.cpp src/whosFirst.cpp src/memory.cpp src/morsCode.cpp src/complicatedWires.cpp src/wireSequences.cpp src/passwords.cpp src/knobs.cpp -I include
   ```
3. Run the application:
   ```bash
    ./keep_talking
   ```
## Usage
1. Launch the console application.
2. Follow the prompts to input the colors of the wires based on the game’s requirements.
3. The application will analyze your input and provide instructions on which wire to cut.

## Levels
The application currently supports the following levels, each featuring unique challenges:
1. **Basic Wires**: Identify and cut the correct wire based on color rules.
2. **Button**: Determine the action required based on the button displayed.
3. **Keypad**: Solve the keypad puzzle using the symbols shown.
4. **Simon Says**: Follow the pattern in this memory game.
5. **Who's First?**: Determine the correct word based on the displayed word and options.
6. **Memory**: Navigate the memory module based on previous inputs.
7. **Morse Code**: Decode the Morse code signal to take action.
8. **Complicated Wires**: Analyze a complex wire setup with multiple conditions.
9. **Wire Sequences**: Cut wires in a specific sequence according to given rules.
10. **Maze**: Navigate through the maze to identify the correct path.
11. **Passwords**: Input the correct letters to form a valid password.
12. **Knobs**: Adjust knobs based on provided instructions to complete this module.

## Contributing
Contributions are welcome! If you would like to contribute to this project, please fork the repository and submit a pull request with your changes.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
