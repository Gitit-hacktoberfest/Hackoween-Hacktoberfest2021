import random
no_of_guesses=1
number_to_guess=random.randint(1,100)
guess=0


while(number_to_guess!=guess):
    guess=int(input("guess the number : "))
    if(guess>number_to_guess):
        print("Try a lower number!")
    elif(guess<number_to_guess):
        print("Try a higher number!")
    else:
        print(f"You won! You guessed correct in {no_of_guesses} attempts.")
    no_of_guesses=no_of_guesses+1


