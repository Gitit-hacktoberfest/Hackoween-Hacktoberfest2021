/*

Create a file with a paragraph stored in it. 
Read each word and check if the word starts with a vowel or consonant. 
If the word starts with a vowel store the word in vowel.txt. 
Else if it starts with consonants, store the word in consonant.txt

*/

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class paragraph {
    public static void main(String args[])throws Exception
    {
        System.out.println("Reading the paragraph word by word");
        
        File o = new File("vowel.txt");
        o.createNewFile();
        FileWriter fo=new FileWriter(o,true);
        File e = new File("consonants.txt");
        e.createNewFile();
        FileWriter fe=new FileWriter(e,true);
        
        File w = new File("paragraph.txt");
        Scanner sc = new Scanner(w);
        int count = 0;
        char ch;
        while (sc.hasNext())
        {
            String word = sc.next();
            System.out.println(word);
            ch=word.charAt(0);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ){
                fo.append(word);
                fo.append("\r\n");
            }
            else if(ch!=' '){
                fe.append(word);
                fe.append("\r\n");
            }
        }
        
        fo.close();
        fe.close();
        System.out.println("Done...");
    }
}
