import java.util.*;
import java.math.*;

class Main
{
    public static void main(String args[]) // entry point from OS
    {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext())
        {
            int t, a, b;
            t = sc.nextInt();
            a = sc.nextInt();
            b = sc.nextInt();

            System.out.printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);
            
            boolean invalid = process(t, a, b);
            if(invalid) System.out.println("is not an integer with less than 100 digits.");
        }
    }
    
    public static boolean process(int t, int a, int b)
    {
        if(t <= 1) return true;
        if(b == 0) return true;
        if(a % b != 0) return true;
        if(a == 0)
        {
            System.out.println(0);
            return true;
        }
        
        int r = (int)((a - b) * Math.log10(t) + 1);
        if(r > 100) return true;
        
        int n = a / b - 1;
        if(n == 0)
        {
            System.out.println(1);
            return false;
        }
        
        BigInteger res = BigInteger.ONE;
        BigInteger tb = (new BigInteger(String.valueOf(t))).pow(b);
        BigInteger val = tb;
        for(int i = 1; i <= n; ++i)
        {
            res = res.add(val);
            val = val.multiply(tb);
        }
        
        String out = res.toString();
        if(out.length() > 100) return true;
        
        System.out.println(out);
        return false;
    }
}
