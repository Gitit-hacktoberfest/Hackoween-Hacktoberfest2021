function checkPassword()
{
 var pswdInput=document.getElementById('pswd');
 var output=document.getElementsByTagName('li');
 
 var password=pswdInput.value;

 var rwIcon=document.getElementsByClassName('rw-icon');

 var digits=false;
 var alphUpper=false;
 var alphlower=false; 
 var spelCh=false;
 var space=true;

 var len=password.length;

 for(var i=0;i<len;i++)
 {
  if(password[i]>=0 && password[i]<=9)
   digits=true;
  if(password[i]>='A' && password[i]<='Z')
   alphUpper=true;
  if(password[i]>='a' && password[i]<='z')
   alphlower=true;
  if((password[i].charCodeAt(0)>=33 &&     
      password[i].charCodeAt(0)<=47)||
     (password[i].charCodeAt(0)>=58 &&
      password[i].charCodeAt(0)<=64)||
     (password[i].charCodeAt(0)>=91 && 
      password[i].charCodeAt(0)<=96))
    spelCh=true;
   
  if(password[i]==' ')
   space=false;
 }

 if(len>=5 && len<=10){
   output[0].style.color='green';
   rwIcon[0].innerHTML='✔️';
  }
 else{
   output[0].style.color='red';
   rwIcon[0].innerHTML='❌';
  }
   
 if(digits){
   output[1].style.color='green';
   rwIcon[1].innerHTML='✔️';
  }
 else{
   output[1].style.color='red';
   rwIcon[1].innerHTML='❌';
  }
   
 if(alphUpper){
   output[2].style.color='green'; 
   rwIcon[2].innerHTML='✔️';
  }  
 else{
   output[2].style.color='red';
   rwIcon[2].innerHTML='❌';
  }

 if(alphlower){
   output[3].style.color='green';
   rwIcon[3].innerHTML='✔️';
  }
 else{
   output[3].style.color='red';
   rwIcon[3].innerHTML='❌';
  }

 if(spelCh){
   output[4].style.color='green'; 
   rwIcon[4].innerHTML='✔️';
  }
 else{
   output[4].style.color='red'; 
   rwIcon[4].innerHTML='❌';
  }

 if(space && len>=1){
   output[5].style.color='green';
   rwIcon[5].innerHTML='✔️';
  }
 else{
   output[5].style.color='red';
   rwIcon[5].innerHTML='❌';
  }
   
}


function seePassword()
{
  var pasInput = document.getElementById("pswd");    

  if(pasInput.getAttribute("type") == "password")
    pasInput.setAttribute("type", "text");
  else         
    pasInput.setAttribute("type", "password");
}

