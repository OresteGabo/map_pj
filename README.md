# Simulation Application

## Overview
This simulation application represents the movement of cars between different bus stations (Arrets) on a map. The project is built using the Qt framework.

## Key Components
1. **App Class:**
    - Manages the overall simulation.
    - Stores Arrets and Cars.
    - Provides functions to draw Arrets and Cars on the screen.

2. **Arret Class:**
    - Represents a bus station on the map.
    - Contains an ID and a position.
    - Includes a collection of associated Cars.

3. **Car Class:**
    - Represents a moving vehicle.
    - Has a position and speed.
    - Moves between Arrets based on a predefined path.

4. **PathNode Class:**
    - Represents a node in the Car's path.
    - Points to the next node in the path.

5. **Widget Class:**
    - GUI component displaying the simulation.
    - Handles user interactions.
    - Draws the map, Arrets, and moving Cars.

## Simulation Logic
- Cars follow a predefined path between Arrets.
- The simulation can be started and stopped by the user.
- The speed of the simulation is adjustable using a slider.

## Getting Started
1. **Prerequisites:**
    - Install Qt framework.

2. **Building the Project:**
    - Clone the repository.
    - Open the project in Qt Creator.
    - Build and run the application.

## Usage
- Launch the application.
- Start/stop the simulation using the "Lancer Simulation" button.
- Adjust the simulation speed with the slider.

## Future Enhancements
- Implement additional features and improvements.

## Contributing
Contributions are welcome! Feel free to open issues or pull requests.

## License
This project is licensed under the [License Name] - see the [LICENSE.md](LICENSE.md) file for details.
