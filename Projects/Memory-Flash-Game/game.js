var buttonColors = ["red", "blue", "green", "yellow"];
var gamePattern = [];
var userClickedPattern = [];
var level = 0;
var hiScore = 0;

//Starting Game
$("#startbtn").on ("click", function startGame(){
    $("#startbtn").hide();
    nextSequence();
});

//Generating Pattern
function nextSequence(){
    //Once nextSequence() is triggered, reset the userClickedPattern to an empty array ready for the next level.
    userClickedPattern = [];   

    var randomNumber = Math.floor(Math.random()*4);
    var randomChosenColor = buttonColors[randomNumber];
    gamePattern.push(randomChosenColor);

    $('#' + randomChosenColor).fadeIn(100).fadeOut(100).fadeIn(100);
    playSound(randomChosenColor);

    level++;
    $("#level-title").text("Level " + level);
}

//Handling button clicks
$(".btn").on('click', handler);

function handler(event){
    var userChosenColour = event.target.id;
    userClickedPattern.push(userChosenColour);
    playSound(userChosenColour);
    animatePress(userChosenColour);
    checkAnswer(userClickedPattern.length-1);
}

//Playing corresponding sounds
function playSound(name){
    var audio = new Audio ("sounds/" + name + ".mp3");
    audio.play();
}

//Animating button clicks
function animatePress(currentColor){
    var ele = $("#" + currentColor);
    ele.addClass("pressed");
    setTimeout(function(){
        ele.removeClass("pressed");
    }, 100);
}


//Game logic
function checkAnswer(currentLevel){
    if (userClickedPattern[currentLevel] == gamePattern[currentLevel]){
        if (userClickedPattern.length == gamePattern.length){
            if (level > hiScore){
                hiScore = level;
            }
            
            $(".score").text("Hi-Score: " + hiScore);

            setTimeout(function(){
                nextSequence();
            }, 1000);
        }
    }
    
    else{
        playSound("wrong");
        $("body").addClass("game-over");
        $("#level-title").text("Game Over");
        setTimeout(function(){
            $("body").removeClass("game-over");
            startOver();
        }, 700);
    }
}

//Game Restart
function startOver(){
    gamePattern = [];
    level = 0;
    $("#level-title").text("");
    $("#startbtn").show();
}