import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
	public static void main(String[] args) throws java.io.IOException{
		//Scanner in=new Scanner(System.in);
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String a=in.readLine(),b=in.readLine();
		in.close();
		Map<Character,Integer> m=new HashMap<>();
		for(int i=0;i<b.length();++i) 
			m.put(b.charAt(i), 1);
		for(int i=0;i<a.length();++i) 
			if(m.get(a.charAt(i))==null)System.out.print(a.charAt(i));
	}	
}
