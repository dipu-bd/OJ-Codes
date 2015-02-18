
import java.util.*;
import java.math.*;

class Main 
{

    public static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) 
    {
        int test = sc.nextInt();
        for (int i = 0; i < test; ++i) 
        { 
            BigDecimal a, b, c;
            a = sc.nextBigDecimal();
            b = sc.nextBigDecimal();
            c = a.add(b);
            String res = c.toPlainString(); 
            res = res.replace('0', ' ').trim();
            if(res.length() == 0) res = "0.0";
            res = res.replace(' ', '0');
            if(res.endsWith(".")) res += '0';            
            if(res.startsWith(".")) res = '0' + res;            
            if (res.indexOf('.') == -1) res += ".0";
            System.out.println(res);
        }
    }
}
