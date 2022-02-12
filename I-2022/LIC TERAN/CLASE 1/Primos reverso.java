// ID 2002 juez patito
import java.util.*;
public class Main{
 
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            int y = in.nextInt();
            System.out.println((y - to_decimal(binario(y))));
        }
    }
 
    public static String binario(int x){
        String bin = "";
        while(x > 0){
            int mod = x % 2;
            String aux = String.valueOf(mod);
            bin = bin + aux;
            x /= 2;
        }
        return bin; 
    }
 
    public static int to_decimal(String s){
        int numero = 0;
        int potencia = 1;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s.charAt(i) == '1')
                numero += potencia;
            potencia *= 2;
        }
        return numero;
    }
 
 
 
     
 
}
 
