import java.util.Arrays;
import java.util.Scanner;

public class Main{
  public static void main(String[] args) {
    Scanner in=new Scanner(System.in);
    String old="",young="";
    String oldMark="2014/09/06",youngMark="1814/09/06";
    String curr="2014/09/06";
    String mark="1814/09/06";
    int cnt=0;
    int n=in.nextInt();
    for(int i=0;i<n;++i) {
      String name=in.next();
      String birth=in.next();
      if(birth.compareTo(curr)>0||birth.compareTo(mark)<0)continue;
      ++cnt;
      if(birth.compareTo(oldMark)<0) {
        oldMark=birth;
        old=name;
      }
      if(birth.compareTo(youngMark)>0) {
        youngMark=birth;
        young=name;
      }
    }
    if(cnt==0)System.out.print("0");
    else System.out.print(cnt+" "+old+" "+young);
  }
  
}