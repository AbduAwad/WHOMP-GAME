## Whomp! Dice Game

### Introduction

Welcome to **Whomp!**, a thrilling dice game where players compete to reach a set maximum score by rolling dice and accumulating points based on specific combinations. The game combines luck and strategy, making it enjoyable and challenging for all ages.

____

### Game Overview

In **Whomp!**, players take turns rolling up to six dice to achieve the highest score. Points are awarded for certain combinations of dice, and the first player to reach the maximum score wins the game. Be careful, though—a bad roll can result in a "Whomp!" and wipe out your points for that turn.

____

### How to Play

1. **Starting the Game:**
   - Launch the game and choose a player name from the given options.
   - Set a maximum score to win the game (recommended range: 2,500 to 20,000 points).

2. **Player's Turn:**
   - Roll up to six dice.
   - Accumulate points based on the dice combinations.
   - Decide whether to roll the remaining dice to increase your score or to end your turn and keep your points.
   - If you roll a combination that scores no points, you get a "Whomp!" and lose all points for that turn.

3. **Computer's Turn:**
   - The computer rolls and follows the same rules as the player.
   - The computer uses a simple strategy to decide whether to roll again based on its current score and remaining dice.

4. **Winning the Game:**
   - The game continues in rounds until a player reaches the maximum score.
   - The first player to reach or exceed the maximum score wins.

### Scoring Rules

Points are awarded based on the following combinations:

- **Unused 1:** 100 points
- **Unused 5:** 50 points
- **Three 1s:** 300 points
- **Three 2s:** 200 points
- **Three 3s:** 300 points
- **Three 4s:** 400 points
- **Three 5s:** 500 points
- **Three 6s:** 600 points
- **Three pairs:** 1500 points
- **Two triplets:** 2500 points
- **Straight (1, 2, 3, 4, 5, 6):** 1500 points
- **Four of a kind and one pair:** 1500 points
- **Four of a kind:** 1000 points
- **Five of a kind:** 2000 points
- **Six of a kind:** 3000 points

### Game Features

- **Interactive Menu:** Navigate through game rules, start a new game, or exit.
- **Scoreboard Display:** Keeps track of both player's and computer's scores.
- **Custom Dice Display:** Visual representation of dice rolls.
- **Computer AI:** The computer makes decisions to roll or stop based on simple probability.

____

### Compiling and Running the Game

#### Prerequisites

- GCC compiler
- Terminal (Linux or macOS) or Command Prompt (Windows)

#### Compilation

To compile the game, open your terminal and run the following command:

```sh
gcc -o whomp_game whomp_game.c
```

#### Running the Game

After compilation, run the game with:

```sh
./whomp_game
```
