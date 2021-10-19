

var baseURL = "https://pokeapi.co/api/v2";
var pokemon = "/pokemon/";

var title = document.getElementById("title");
var hright = document.getElementById("height");
var weight = document.getElementById("weight");
var idd = document.getElementById("idd");
var img = document.getElementById("img");
var topp = document.getElementById("topp");
var bottom = document.getElementById("bottom");
var dis = document.getElementById("description");

(function () {
    
    document.getElementById("ajaxButton").addEventListener("click", makeRequest);



    
    var httpRequest;
    
    function makeRequest() {
        httpRequest = new XMLHttpRequest();
      
        if (!httpRequest) {
            alert("It did not work :(");
            return false;
        }
     
        var id1 = Math.floor(Math.random() * 100 + 1);
        var fullURL = baseURL + pokemon + id1;
        topp.className = 'content';
        bottom.className = 'pannel  rotate';
        dis.innerHTML = "Loading ...";
        httpRequest.onreadystatechange = fillInfo;

        httpRequest.open(
            "GET", fullURL
        );
        httpRequest.send();
    }

    
    function fillInfo() {
       
        var responseContent;
        if (httpRequest.readyState === XMLHttpRequest.DONE) {
            if (httpRequest.status === 200) {
             
                responseContent = httpRequest.responseText;
                console.log(responseContent);
             
                var parsed = JSON.parse(responseContent);
                
                console.log(parsed);
               
                title.innerHTML = parsed.name;
                height.innerHTML = parsed.height;
                weight.innerHTML = parsed.weight;
                img.src = parsed.sprites.front_default;
                topp.className = 'content active';
                bottom.className = 'pannel active';
                dis.innerHTML = "Random your Pokemon";
                //   
            } else {
                alert("There was a problem with the request.");
            }
        }

    } 
})();

function click() {

    var id = document.getElementById("idd").value;
    alert(id);
}
