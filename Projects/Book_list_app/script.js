const form = document.querySelector('#book-form');
const tbody = document.querySelector('tbody');
const bName = document.querySelector('#b-name');
const bAuthor = document.querySelector('#b-author');
const bEdition = document.querySelector('#b-edition');


function displayData(name, author, editon) {

    let tr = document.createElement('tr');
    tr.innerHTML = `
    <td>${name}</td>
    <td>${author}</td>
    <td>${editon}</td>
    <td><a class="btn-cancel" href="#" onclick="removeBook(this)">&times;</a></td>
    `;
    tbody.appendChild(tr);
    showAlert('Success, Book Added.');
}

function showAlert(msg) {
    var parent = document.querySelector('.UI-section');
    var formPart = document.querySelector('.form-part')
    var Alert = document.createElement('div');

    Alert.classList.add('Alert');
    Alert.innerHTML = `${msg}`;

    if (msg.charAt(0) == 'S')
        Alert.classList.add('succses');
    else
        Alert.classList.add('failed');

    parent.insertBefore(Alert, formPart);

    //Hiding Alert After 2s of display.
    setTimeout(() => Alert.style.display = 'none', 2000);
}

function removeBook(e) {
    e.parentElement.parentElement.remove();
}

function clearInput() {
    bName.value = '';
    bAuthor.value = '';
    bEdition.value = '';
}

form.addEventListener('submit', (e) => {
    e.preventDefault();
    let name = bName.value;
    let author = bAuthor.value;
    let editon = bEdition.value;

    if (name === '' || author === '' || editon === '')
        showAlert('Fill All the Options.');
    else
        displayData(name, author, editon);

    clearInput();
});