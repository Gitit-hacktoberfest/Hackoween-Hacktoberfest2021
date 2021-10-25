<!DOCTYPE html>
<html>

<body>

<input type="button" id="button" value="button" style="color:white" onclick="setColor('button', '#101010')" ; />

<script>
  var count = 1;

  function setColor(btn, color) {
    var property = document.getElementById(btn);
    if (count == 0) {
      property.style.backgroundColor = "green"
      count = 1;
    } else {
      property.style.backgroundColor = "red"
      count = 0;
    }
  }
</script>

</body>

</html>