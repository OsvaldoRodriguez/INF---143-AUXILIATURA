import java.util.*;
public class Main{
 
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String a, b, c, d;
        while(in.hasNext()){
            a = g(in.nextLine());
            if(a != ""){
                b = g(in.nextLine());
                c = g(in.nextLine());
                d = g(in.nextLine());   
 
                // codigo para el problema
                String ans = "Mal";
 
                // System.out.println("a:" + a);
                // System.out.println("b:" + b);
                // System.out.println("c:" + c);
                // System.out.println("d:" + d);
 
                if(go(a) == 3){
                    if(f(a.charAt(0), a.charAt(4)) && f(a.charAt(2), c.charAt(0)) && f(b.charAt(0), d.charAt(0)))
                        ans = "Bien";
                }else if(go(b) == 3){
                    if(f(b.charAt(0), b.charAt(4)) && f(a.charAt(0), c.charAt(0)) && f(b.charAt(2), d.charAt(0)))
                        ans = "Bien";
                }else if(go(c) == 3){
                    if(f(c.charAt(0), c.charAt(4)) && f(a.charAt(0), c.charAt(2)) && f(b.charAt(0), d.charAt(0)))
                        ans = "Bien";
                }else if(go(d)== 3){
                    if(f(d.charAt(0), d.charAt(4)) && f(a.charAt(0), c.charAt(0)) && f(b.charAt(0), d.charAt(2)))
                        ans = "Bien";
                }
                System.out.println(ans);
            }
        }
    }
 
    public static int go(String a){
        int cnt = 0;
        for(int i = 0; i < a.length(); i++)
            if(a.charAt(i) != ' ')
                cnt++;
        return cnt;
    }
 
    public static String g(String x){
        String ans = "";
        int i = 0;
        while(i < x.length() && x.charAt(i) == ' ')
            i++;
        int j = x.length() - 1;
        while(j >= 0 && x.charAt(j) == ' '){
            j--;
        }
 
        for(int k = i; k <= j; k++){
            ans += x.charAt(k);
        }
        return ans;
    }
    public static boolean f(char a, char b){
        int aa = Character.getNumericValue(a);
        int bb = Character.getNumericValue(b);
        return aa + bb == 7;
    }
 
 
 
     
 
}
