let heading=document.querySelector("#heading");

let mode=document.querySelectorAll("button");

let message=document.querySelector("#message");

let reset=document.querySelector("#reset");

let squares=document.querySelectorAll(".squares");

let rgbDisplay=document.querySelector("h1 span");

let num=6;
let colors=[];
let colorSelected;

newGame();

function newGame(){
     selectMode();
     setColor();
     resetgame();
}
reset.addEventListener("click",function(){
     resetgame()
})

function selectMode()
{
     for(let i=1; i<mode.length ;i++)
     {
          mode[i].addEventListener("click",function()
          {
               mode[1].classList.remove("selected");
               mode[2].classList.remove("selected");
               this.classList.add("selected");
               this.textContent =="EASY"? num=3 : num=6;
               resetgame();
          });
          
     }
               
}

function setColor()
{
     //It creates the array of random colors
      colors = colorpicker(num);

     colorSelected=answer();
     rgbDisplay.textContent=colorSelected;

     for(let i=0; i<squares.length; i++)
     {   
          squares[i].addEventListener("click",function()
          {
               if(this.style.backgroundColor==colorSelected)
               {
                    message.textContent="Correct!";
                    changeColor(colorSelected);
                    reset.textContent="PLAY AGAIN?"
               }
               else
               {
                    this.style.backgroundColor="rgb(29, 26, 26)";
                    message.textContent="Try again";
               }
          });
     }
}

function resetgame()
{         
          for(let i=0; i<squares.num; i++)
          {   //to intially set the color
               squares[i].style.backgroundColor="rgb(29, 26, 26)";
          }
          colors=colorpicker(num);
          colorSelected=answer();
          this.textContent="NEW COLORS";
          rgbDisplay.textContent=colorSelected;
          for(let i=0; i<squares.length; i++)
          {
               if(colors[i])
               {  
                    squares[i].style.display="block";
                    squares[i].style.backgroundColor=colors[i];
               }
               else
               {
                    squares[i].style.display="none";
               }
          }
         
          heading.style.backgroundColor="rgb(13, 108, 200)";
          message.textContent="";     
}

//function to create array
function colorpicker(num){
     let arr=[];
     for(let i=0;i<num;i++)
     {
          let r=Math.floor(Math.random() * 256);
          let g=Math.floor(Math.random() * 256);
          let b=Math.floor(Math.random() * 256);
          arr.push("rgb("+r+", "+g+", "+b+")");
     }
     return arr;
}

//To pick a random ans
function answer(){
     let random = Math.floor(Math.random() * colors.length);
       return colors[random];
  }
  
// Executes when person wins
function changeColor(color)
{
     for(let i=0; i<num ; i++){
          squares[i].style.backgroundColor=color;
     }
     heading.style.backgroundColor=color;
}



