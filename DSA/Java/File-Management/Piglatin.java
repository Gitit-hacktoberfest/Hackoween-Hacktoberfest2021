/*

Most words in Pig Latin end in "ay." Use the rules below to translate normal English into Pig Latin.

1. If a word starts with a consonant and a vowel, put the first letter of the word at the end of the word and add "ay."

Example: Happy = appyh + ay = appyhay


2. If a word starts with two consonants move the two consonants to the end of the word and add "ay."

Example: Child = ildch + ay = Ildchay


3. If a word starts with a vowel add the word "way" at the end of the word.

Example: Awesome = Awesome +way = Awesomeway


4. If the first two letters are vowels just add ay at the end of the word

Example : air = air + ay = airay

*/

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class piglatin {
    public static void main(String args[])throws Exception
    {
        Scanner sc=new Scanner(System.in);
        int n;
        try
        {
            String str;
            System.out.println("Enter number of names ");
            n=sc.nextInt();
            File f= new File("english.txt");
            f.createNewFile();
            String arr[]=new String[10];
            for(int i=0;i<n;i++){
                System.out.println("Enter names ");
                str=sc.next();
                arr[i]=str+" ";
                File fo = new File("english.txt");
                FileWriter fw = new FileWriter(fo,true);
                fw.append(arr[i]);
                fw.close();
            }
            
        }catch(FileNotFoundException e)
        {
            System.out.println("The specified file does not exist...");
        }
        
        File w = new File("english.txt");
        Scanner s = new Scanner(w);
        File e = new File("piglatin.txt");
        e.createNewFile();
        FileWriter fe=new FileWriter(e,true);
        int count = 0;
        int i;
        char c1,c2;
        while (s.hasNext())
        {
            String word = s.next();
            String str2="";
            c1=word.charAt(0);
            c2=word.charAt(1);
            if(c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u' ){
                if(c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u' ){
                    System.out.println(str2);
                    fe.append(word+"ay ");
                }
                else{
                    System.out.println(str2);
                    fe.append(word+"way ");
                }
            }
            else{
                if(c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u' ){
                    for(int j=1;j<word.length();j++)
                        str2+=word.charAt(j);
                    str2+=word.charAt(0);
                    str2+="ay ";
                    System.out.println(str2);
                    fe.append(str2);
                }
                else{
                    for(int j=2;j<word.length();j++)
                        str2+=word.charAt(j);
                    str2=str2+word.charAt(0)+word.charAt(1);
                    str2+="ay ";
                    System.out.println(str2);
                    fe.append(str2);
                }
            }
            count = count + 1;
        }
        fe.close();
        
    }
}
