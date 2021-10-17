//Write a program that accepts 10 names and stores them in a file
//and segregates the names into two separate files based on
//if the length of the word is even or odd.

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class NamesFile {
    public static void main(String args[])throws Exception
    {
        Scanner sc=new Scanner(System.in);
        int n=10;
        try
        {
            String str;
            File f= new File("name.txt");
            f.createNewFile();
            String arr[]=new String[10];
            for(int i=0;i<n;i++){
                System.out.println("Enter number names ");
                str=sc.next();
                arr[i]=str+" ";
                File fo = new File("name.txt");
                FileWriter fw = new FileWriter(fo,true);
                fw.append(arr[i]);
                fw.close();
            }
            
        }catch(FileNotFoundException e)
        {
            System.out.println("The specified file does not exist...");
        }
        File w = new File("name.txt");
        Scanner s = new Scanner(w);
        int count = 0;
        File o = new File("odd.txt");
        o.createNewFile();
        FileWriter fo=new FileWriter(o,true);
        File e = new File("even.txt");
        e.createNewFile();
        FileWriter fe=new FileWriter(e,true);
        while (s.hasNext())
        {
            String word = s.next();
            System.out.println(word);
            if(word.length()%2==0)
                fe.append(word);
            else
                fo.append(word);
            count = count + 1;
        }
        fe.close();
        fo.close();
    }
}
