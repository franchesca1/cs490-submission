#!/bin/bash

echo "Welcome to Rock, Paper, Scissors!"
echo "Rules:"
echo "1. Rock beats Scissors (crushes them)."
echo "2. Scissors beat Paper (cuts it)."
echo "3. Paper beats Rock (covers it)."

# Array of choices
choices=("rock" "paper" "scissors")

while true; do
    # Get user input
    read -p "Enter your choice (rock, paper, or scissors): " user_choice
    
    # Generate computer choice
    computer_choice=${choices[$((RANDOM % 3))]}
    echo "Computer chose: $computer_choice"

    # Determine the winner
    if [[ "$user_choice" == "$computer_choice" ]]; then
        echo "It's a tie! Let's play again."
    elif [[ ("$user_choice" == "rock" && "$computer_choice" == "scissors") ||
            ("$user_choice" == "scissors" && "$computer_choice" == "paper") ||
            ("$user_choice" == "paper" && "$computer_choice" == "rock") ]]; then
        echo "You win! Congratulations!"
        break
    else
        echo "Computer wins! Better luck next time."
        break
    fi

done
