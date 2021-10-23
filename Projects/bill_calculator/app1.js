// instantialte storage class
const storage = new Storage();

//instantiate ui class
const ui = new UI();

// record class declaration
class Record {
  constructor(name, meter, bill) {
    this.name = name;
    this.meter = meter;
    this.bill = bill;
  }
}
// UI variables
const form = document.querySelector(".form-inline"),
  name = document.querySelector("#name"),
  meter = document.querySelector("#meter"),
  prev_reading = document.querySelector("#prev-reading"),
  curr_reading = document.querySelector("#curr-reading"),
  unit = document.querySelector("#unit"),
  table = document.querySelector(".table"),
  clearall = document.querySelector(".clrall"),
  tbody = document.querySelector("#tbody"),
  filter = document.querySelector(".filter"),
  total = document.querySelector("#total");

//load event listners
loadEventListners();

//declare event listners
function loadEventListners() {
  //loads when DOM loads
  document.addEventListener(
    "DOMContentLoaded",
    storage.displayFromLocalStorage()
  );
  //other event listner
  form.addEventListener("submit", function (e) {
    document.querySelector("#loading").style.display = "block";
    filter.style.display = "none";
    clearall.style.display = "none";
    table.style.display = "none";
    setTimeout(addToTable, 1700);
    e.preventDefault();
  });

  clearall.addEventListener("click", removeAll);

  //event delegation
  table.addEventListener("click", deleteRow);

  //filter
  filter.addEventListener("keyup", filterThrough);
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
    ui.showAlert("please fill out all the fields correctly", "danger");
    document.querySelector("#loading").style.display = "none";
    table.style.display = "table";
    const tablerow = document.querySelector("#tablerow");
    if (tablerow != null) {
      clearall.style.display = "block";
      filter.style.display = "block";
    }
  } else {
    //get values from form
    const nameOFTenant = name.value,
      meter_no = meter.value,
      previous_read = parseInt(prev_reading.value),
      current_read = parseInt(curr_reading.value),
      unt = parseInt(unit.value);

    //Bill calculation
    const bill = (current_read - previous_read) * unt;

    //class instance
    const record = new Record(nameOFTenant, meter_no, bill);

    // create table
    ui.createTable(record);

    //add to local storage
    storage.addToLocalStorage(record);

    //show total bill
    storage.totalBillAmount();

    ui.showAlert("Record Added", "success");

    //ui experience
    document.querySelector("#loading").style.display = "none";
    table.style.display = "table";
    filter.style.display = "block";
    clearall.style.display = "block";
  }

  // clear fields
  ui.clrInputFields();
}

//delete row
function deleteRow(e) {
  // const records = new Record();
  if (e.target.parentElement.classList.contains("delete-item")) {
    e.target.parentElement.parentElement.parentElement.remove();

    storage.removeFromLocalStorage(
      e.target.parentElement.parentElement.previousElementSibling
        .previousElementSibling.textContent
    );
    //total bill
    storage.totalBillAmount();

    // cheack if
    const tablerow = document.querySelector("#tablerow");
    if (tablerow == null) {
      clearall.style.display = "none";
      filter.style.display = "none";
    }
    ui.showAlert("Record Deleted", "success");
  }
  e.preventDefault();
}

//Remove all from the list
function removeAll(e) {
  tbody.innerHTML = "";
  storage.removeAllFromStorage();
  //total bill
  total.innerHTML = "0";
  clearall.style.display = "none";
  filter.style.display = "none";
  ui.showAlert("List Is EMPTY Now", "success");
  e.preventDefault();
}

//filter through
function filterThrough(e) {
  const text = e.target.value.toLowerCase();
  const tablerow = document.querySelector("#tablerow");
  if (tablerow !== null) {
    document.querySelectorAll("#tdname").forEach(function (name) {
      if (name.textContent.toLowerCase().indexOf(text) != -1) {
        name.parentElement.style.display = "table-row";
        console.log(name.parentElement);
      } else {
        name.parentElement.style.display = "none";
      }
    });
  }
  e.preventDefault();
}
