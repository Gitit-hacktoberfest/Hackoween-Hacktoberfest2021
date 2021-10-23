// UI variables

const form = document.querySelector(".form-inline"),
  name = document.querySelector("#name"),
  meter = document.querySelector("#meter"),
  prev_reading = document.querySelector("#prev-reading"),
  curr_reading = document.querySelector("#curr-reading"),
  unit = document.querySelector("#unit"),
  table = document.querySelector(".table"),
  clearall = document.querySelector(".clrall");

//load event listners
loadEventListners();

//declare event listners
function loadEventListners() {
  form.addEventListener("submit", function (e) {
    document.querySelector("#loading").style.display = "block";
    clearall.style.display = "none";
    table.style.display = "none";
    setTimeout(addToTable, 2000);
    e.preventDefault();
  });
  clearall.addEventListener("click", removeAll);
  table.addEventListener("click", deleteRow);
}

//add values to table
function addToTable() {
  //check if field is empty
  if (
    name.value === "" ||
    meter.value === "" ||
    prev_reading.value === "" ||
    curr_reading.value === "" ||
    unit.value === ""
  ) {
    showAlert("please fill out all the fields correctly", "danger");
    document.querySelector("#loading").style.display = "none";
    const tablerow = document.querySelector("#tablerow");
    if (tablerow != null) {
      clearall.style.display = "block";
      table.style.display = "table";
    }
  } else {
    if (table.innerHTML == "") {
      table.innerHTML = `<thead id="htable">
      <tr>
        <th scope="col">name</th>
        <th scope="col">Meter No.</th>
        <th scope="col">Bill</th>
        <th></th>
      </tr>
    </thead>`;
    }
    //get values from form
    const nameOFTenant = name.value,
      meter_no = meter.value,
      previous_read = parseInt(prev_reading.value),
      current_read = parseInt(curr_reading.value),
      unt = parseInt(unit.value);

    //Bill calculation
    const bill = (current_read - previous_read) * unt;
    // create table
    createTable(nameOFTenant, meter_no, bill);

    showAlert("Record Added", "success");

    //ui experience
    document.querySelector("#loading").style.display = "none";
    table.style.display = "table";
    clearall.style.display = "block";
  }

  // clear fields
  clrInputFields();
}
//Clear input fields
function clrInputFields() {
  name.value = "";
  meter.value = "";
  prev_reading.value = "";
  curr_reading.value = "";
  unit.value = "";
}
//define create table
function createTable(nameOFTenant, meter_no, bill) {
  const row = document.createElement("tr");
  row.id = "tablerow";
  row.innerHTML = `<td id="tdname">${nameOFTenant}</td>
  <td id="tdmeter">${meter_no}</td>
  <td id="tdunit">${bill}</td>
  <td><a href="#" class="delete-item secondary-content float-right"><i class="fa fa-remove"></i></a></td>`;
  table.appendChild(row);
}

//Remove all from the list
function removeAll(e) {
  table.innerHTML = "";
  clearall.style.display = "none";
  showAlert("List Is EMPTY Now", "success");
  e.preventDefault();
}

//delete row
function deleteRow(e) {
  if (e.target.parentElement.classList.contains("delete-item")) {
    e.target.parentElement.parentElement.parentElement.remove();
    showAlert("Record Deleted", "success");
  }
  e.preventDefault();
}

//showALERT
function showAlert(msg, className) {
  const message = document.createElement("div");
  message.className = `alert alert-${className} text-center`;
  message.appendChild(document.createTextNode(msg));
  const card_body = document.querySelector(".card-body");
  const title = document.querySelector(".card-title");
  card_body.insertBefore(message, title);

  setTimeout(function () {
    document.querySelector(".alert").remove();
  }, 3000);
}
