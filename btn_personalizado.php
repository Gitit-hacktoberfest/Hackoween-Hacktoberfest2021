<!DOCTYPE html>
<html>

<body>

  <h1>The onclick Event</h1>

  <p>The onclick event is used to trigger a function when an element is clicked on.</p>

  <p>Click the button to trigger a function that will output "Hello World" in a p element with id="demo".</p>

  <div class="row">
    <button onclick="myFunction()">Click me</button>

    <p id="demo"></p>
  </div>

  <input value="button"> </input>

  <script>
    function formataData() {

      var recebida = ("2021-09-22T09:00:00");

      var data = new Date(recebida);

      var resultado = data.toLocaleString();

      document.getElementById("demo").innerHTML = resultado;

    }


    function updateButton() {
      if (button.value === 'botao desligado') {
        button.value = 'botao ligado';
        paragraph.textContent = 'botao ligado';

        button.style.backgroundColor = "Green";

      } else {
        button.value = 'botao desligado';
        paragraph.textContent = 'botao desligado';

        button.style.backgroundColor = "Red";

      }
    }
  </script>

</body>

</html>