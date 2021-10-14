import java.util.*;
// it counts the number of palindromic substrings in a given string 
//its complexity if of order (n^3)
public class Palindromicsubstrings {
    public static void main(String args[])
    {
        String s1 = "",s2 = "", s3 = "" ;
        char ch ;
        System.out.println("Enter a String");
        Scanner scn = new Scanner(System.in);
        s1 = scn.next();
        for(int i = 0 ; i < s1.length();i++)
        {
            for(int j = i+1 ; j<= s1.length();j++)
            {
                s3 = "";
                s2 = s1.substring(i,j);
              //  System.out.println(s2);
                //System.out.println(s2.length());
                
                for(int k = s2.length()- 1 ; k >= 0 ; k--)
                {
                    ch = s2.charAt(k);
                   s3 = s3 +ch ;
                }
                if(s2.equals(s3)==true){System.out.println(s2);}
            }
        }
    }


}
