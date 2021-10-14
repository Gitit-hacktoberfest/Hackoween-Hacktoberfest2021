var inputDate = document.querySelector("#input-date");
var showBtn = document.querySelector("#show");
var output = document.querySelector("#output");
var gif = document.querySelector("#gif");
var birthdayCake = document.querySelector("#birthday-cake");

gif.style.display ='none';
birthdayCake.style.display ='none';

function stringReverse(str) {
    var charList = str.split('');
    var reversedListChars = charList.reverse();
    var reversedList = reversedListChars.join('');
    return reversedList;
  }
  
  function isPalindrome(str) {
    var reverseStr = stringReverse(str);
    if (str === reverseStr) {
      return true;
    }
  
    return false;
  }
  
  function datetostring(date) {
    var dateString = { day: '', month: '', year: '' };
    if (date.day < 10) {
      dateString.day = '0' + date.day;
    }
    else {
      dateString.day = date.day.toString();
    }
    if (date.month < 10) {
      dateString.month = '0' + date.month;
    }
    else {
      dateString.month = date.month.toString();
    }
  
    dateString.year = date.year.toString();
    return dateString;
  }
  
  function dateVariations(date) {
    var dateString = datetostring(date)
    var ddmmyyyy = dateString.day + dateString.month + dateString.year;
    var mmddyyyy = dateString.month + dateString.day + dateString.year;
    var yyyymmdd = dateString.year + dateString.month + dateString.day;
    var ddmmyy = dateString.day + dateString.month + dateString.year.slice(-2);
    var mmddyy = dateString.month + dateString.day + dateString.year.slice(-2);
    var yymmdd = dateString.year.slice(-2) + dateString.month + dateString.day;
    return [ddmmyyyy, mmddyyyy, yyyymmdd, ddmmyy, mmddyy, yymmdd]
  }
  
  function checkDatePalindrome(date) {
    var listOfPalindromes = dateVariations(date);
    var flag = false;
  
    for (var i = 0; i < listOfPalindromes.length; i++) {
      if (isPalindrome(listOfPalindromes[i])) {
        flag = true;
        break;
      }
    }
    return flag;
  }
  
  
  function isLeapYear(year) {
    if (year % 400 === 0) {
      return true;
    }
  
    if (year % 100 === 0) {
      return true;
    }
  
    if (year % 4 === 0) {
      return true;
    }
  
    return false;
  }
  
  function getNextDate(date) {
    var day = date.day + 1;
    var month = date.month;
    var year = date.year;
  
    var daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
  
    if (month == 2) {
      if (isLeapYear(year)) {
        if (day > 29) {
          day = 1;
          month++;
        }
      }
      else {
        if (day > 28) {
          day = 1;
          month++;
        }
      }
    }
    else {
      if (day > daysInMonth[month - 1]) {
        day = 1;
        month++;
      }
    }
  
    if (month > 12) {
      month = 1;
      year++;
    }
  
    return {
      day: day,
      month: month,
      year: year,
    }
  }
  
  function getPreviousDate(date) {
    // console.log(date.day);
    var day = date.day - 1;
    var month = date.month;
    var year = date.year;
  
    var daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
  
    if (month === 3) {
      if (isLeapYear(year)) {
        if (day === 0) {
          day = 29;
          month = 2;
        }
      }
      else {
        if (day === 0) {
          day = 28;
          month = 2;
        }
      }
    }
    else {
      if (day === 0) {
        month--;
        day = daysInMonth[month - 1];
      }
    }
  
    if (month === 0) {
      month = 12;
      year--;
      day = daysInMonth[11];
    }
  
    return {
      day: day,
      month: month,
      year: year
    }
  }
  function getNextPalindromeDate(date) {
    var count = 0;
    var nextDate = getNextDate(date);
  
    while (1) {
      count++;
      var isPalindrome = checkDatePalindrome(nextDate)
      if (isPalindrome) {
        break;
      }
      nextDate = getNextDate(nextDate);
    }
  
    return [count, nextDate];
  }
  
  
  function getPreviousPalindromeDate(date) {
    var count = 0;
    var prevDate = getPreviousDate(date);
    while (1) {
      count++;
      var isPalindrome = checkDatePalindrome(prevDate)
      if (isPalindrome) {
        break;
      }
      prevDate = getPreviousDate(prevDate);
    }
    return [count, prevDate];
  }
  
  
  
  function nearestPalindrome(date) {
    birthdayCake.style.display = 'none';

    if(checkDatePalindrome(date)){
      showMessage("YAY!, Your birthday is a Palindrome!");
      birthdayCake.style.display = 'block';
    }
    else{

    var [countPrev, prevPal] = getPreviousPalindromeDate(date);
    var [countNext, nextPal] = getNextPalindromeDate(date);
    if (countPrev < countNext) {
      if(prevPal.day < 10) {
        prevPal.day = '0' + (prevPal.day);
      }
      if(prevPal.month < 10) {
        prevPal.month = '0' + (prevPal.month);
      }
      showMessage(`The nearest palindrome date is ${prevPal.day}-${prevPal.month}-${prevPal.year}, you missed by ${countPrev} ${countPrev > 1 ? 'days' : 'day'}.`);
    }
    else {
      if(nextPal.day < 10) {
        nextPal.day = '0' + (nextPal.day);
      }
      if(nextPal.month < 10) {
        nextPal.month = '0' + (nextPal.month);
      }
      showMessage(`The nearest palindrome date is ${nextPal.day}-${nextPal.month}-${nextPal.year}, you missed by ${countNext} ${countNext > 1 ? 'days' : 'day'}.`);
    }
    }
  }
  
  

  
  
    function showPalindrome(){
  
      if(inputDate.value !== ''){
          var date = inputDate.value;
          var dateSplit = date.split('-');
          var requiredDate = {
              day: Number(dateSplit[2]),
              month: Number(dateSplit[1]),
              year: Number(dateSplit[0]),
          }
          nearestPalindrome(requiredDate);
      }
      else{
          showMessage("Please select a date!");
      }
    }
    
  function showOutputMessage(msg){
    hideMessage();
    gif.style.display ='block';
    setTimeout(() => {
      gif.style.display ='none';
      showPalindrome();

    }, 1500);
  }

  function hideMessage(){
    output.style.display ="none";

  }

  function showMessage(msg){
    output.style.display = "block";
    output.innerText = msg;
  }

  showBtn.addEventListener('click', showOutputMessage)
  
  