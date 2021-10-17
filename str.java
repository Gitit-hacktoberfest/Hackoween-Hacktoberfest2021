 public class str{
 public static void main(String[] args) {
   
 String txt = "         Hello myself vaishnavi.I am a engineering student.";//str variable contains collection string
   
 System.out.println(txt.indexOf("myself"));//The indexOf() method returns the index position of the first occurrence of a specified text(myself) in astring (including whitespace)
 
 System.out.println(txt.toUpperCase());   //convert string to uppercase
   
 System.out.println(txt.toLowerCase());   //convert string to lowercase

 System.out.println(txt.trim());          //remove whitespace from string

 int code = txt.codePointAt(0);           //Return the Unicode of the first character in a string 
    System.out.println(code);             //output is 32

  String mess = "I like to code";
System.out.println(txt.concat(mess)); // concatinate two strings

System.out.println(txt.endsWith("t")); //tells whether string ends with t or not

System.out.println(txt.hashCode()); // returns hash code of string

System.out.println(txt.startsWith("h"));   //tells whether string starts with h or not

 System.out.println(txt.isEmpty()); //tells whether string is empty or not
}
}
