import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
	public static void main(String args[])throws IOException{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String s=in.readLine().toLowerCase();
		in.close();
		int v[]=new int[30];
		char res='a';
		int rescnt=0;
		for(int i=0;i<s.length();++i)
			if(Character.isAlphabetic(s.charAt(i)))
				v[s.charAt(i)-'a']++;
		for(int i=0;i<30;++i)
			if(v[i]>rescnt) {
				rescnt=v[i];
				res=(char) ('a'+i);
			}
		System.out.print(res+" "+rescnt);
	}
}
