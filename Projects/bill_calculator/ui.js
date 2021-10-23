class UI {
  createTable(record) {
    const row = document.createElement("tr");
    row.id = "tablerow";
    row.innerHTML = `<td id="tdname">${record.name}</td>
    <td id="tdmeter">${record.meter}</td>
    <td id="tdunit">${record.bill}</td>
    <td><a href="#" class="delete-item secondary-content float-right"><i class="fa fa-remove"></i></a></td>`;
    tbody.appendChild(row);
  }
  clrInputFields() {
    name.value = "";
    meter.value = "";
    prev_reading.value = "";
    curr_reading.value = "";
    unit.value = "";
  }
  //showALERT
  showAlert(msg, className) {
    const message = document.createElement("div");
    message.className = `alert alert-${className} text-center`;
    message.appendChild(document.createTextNode(msg));
    const card_body = document.querySelector(".card-body");
    const title = document.querySelector(".card-title");
    card_body.insertBefore(message, title);

    setTimeout(function () {
      document.querySelector(".alert").remove();
    }, 1500);
  }
}
