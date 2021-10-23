class Storage {
  getFromLocalStorage() {
    let record;
    if (localStorage.getItem("records") === null) {
      record = [];
    } else {
      record = JSON.parse(localStorage.getItem("records"));
    }
    return record;
  }

  displayFromLocalStorage() {
    const records = this.getFromLocalStorage();
    records.forEach(function (record) {
      const row = document.createElement("tr");
      row.id = "tablerow";
      row.innerHTML = `<td id="tdname">${record.name}</td>
      <td id="tdmeter">${record.meter}</td>
      <td id="tdunit">${record.bill}</td>
      <td><a href="#" class="delete-item secondary-content float-right"><i class="fa fa-remove"></i></a></td>`;
      tbody.appendChild(row);
    });
    this.totalBillAmount();
    const tablerow = document.querySelector("#tablerow");
    if (tablerow != null) {
      clearall.style.display = "block";
      filter.style.display = "block";
    }
  }

  addToLocalStorage(record) {
    const records = this.getFromLocalStorage();
    records.push(record);
    localStorage.setItem("records", JSON.stringify(records));
  }
  removeFromLocalStorage(target) {
    const records = this.getFromLocalStorage();
    records.forEach(function (record, index) {
      if (target == record.meter) {
        records.splice(index, 1);
      }
    });
    //set local staorage again
    localStorage.setItem("records", JSON.stringify(records));
  }
  removeAllFromStorage() {
    localStorage.removeItem("records");
  }
  totalBillAmount() {
    let totalBill = 0;
    const items = storage.getFromLocalStorage();
    items.forEach(function (item) {
      totalBill += item.bill;
    });
    total.innerHTML = `${totalBill}`;
  }
}
