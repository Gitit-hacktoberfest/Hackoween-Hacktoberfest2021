/*
KMP algorithm
Time complexity : O(n + m)
Space complexity : O(m)
where n = length of txt
m = length of pattern
*/
import java.util.*;
public class KMP{
	static void KMPSearch(String txt, String pat, int lps[]){
		int i=0, j=0;
		int n = txt.length(), m = pat.length();
		while(i<n){
			if(txt.charAt(i) == pat.charAt(j)){
				i++; j++;
			}
			if(j==m){
				System.out.println((i-j) + " ");
				j = lps[j-1];
			}else if(i<n && txt.charAt(i)!=pat.charAt(j)){
				if(j==0)
					i++;
				else
					j = lps[j-1];
			}
		}
	}
	static void fillLPS(String str, int lps[]){
		int len = 0, n = str.length();
		lps[0] = 0;
		int i=1;
		while(i<n){
			if(str.charAt(i)==str.charAt(len)){
				len++;
				lps[i] = len;
				i++;
			}else{
				if(len==0){
					lps[i]=0;
					i++;
				}else{
					len = lps[len-1];
				}
			}
		}
	}
	public static void main(String[] args) {
		String txt = "Happy coding! && Enjoy coding"; 
        String pat = "od"; 
        int lps[] = new int[pat.length()];
        fillLPS(pat, lps);
        System.out.println("Starting indices in txt where pattern(pat) found:");
        KMPSearch(txt, pat, lps);
	}
}