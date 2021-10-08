//UI Elements
let num = document.querySelector('#number');
let startBtn = document.querySelector('#startBtn');
let clearBtn = document.querySelector('#clearBtn');

let counter = 10;


startBtn.addEventListener('click', function() {
        startBtn.disabled = true;
        //console.log("Clicked");
        setInterval(function() {
            counter --;
            num.textContent = counter;
        
            if(counter <= 0) {
                document.querySelector('.s-left').textContent = "";
                num.textContent = "COMPLETE";
                clearInterval(counter = 0);
                //console.log(counter);
            }
        }, 1000);
});  
clearBtn.addEventListener('click', function () {
    location.reload();
}); 

