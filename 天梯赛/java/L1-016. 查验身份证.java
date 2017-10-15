import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main{
  public static void main(String[] args) {
    Scanner in=new Scanner(System.in);
    int n=in.nextInt();
    boolean pass=true;
    for(int i=0;i<n;++i) {
      String str=in.next();
      if(!check(str.substring(0,17),str.charAt(17))) {
        pass=false;
        System.out.println(str);
      }
    }
    if(pass)System.out.println("All passed");
  }
  public static boolean check(String s,char c) {
    int weight[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char m[]= {'1','0','X','9','8','7','6','5','4','3','2'};
    int sum=0;
    for(int i=0;i<s.length();++i) {
      if(Character.isDigit(s.charAt(i))) {
        sum+=weight[i]*(s.charAt(i)-'0');
      }else return false;
    }
    if(m[sum%11]==c)return true;
    return false;
  }
}