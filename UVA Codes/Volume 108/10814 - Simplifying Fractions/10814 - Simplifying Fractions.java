import java.util.*;
import java.math.*;

class Main
{
    public static Scanner sc = new Scanner(System.in);
    public static void main(String args[])
    {
        int test = sc.nextInt();
        for(int i = 0; i < test; ++i)
        {
            BigInteger p, q;
            p = sc.nextBigInteger();
            sc.next();
            q = sc.nextBigInteger();
            BigInteger g = p.gcd(q);
            
            p = p.divide(g);
            q = q.divide(g);
            System.out.printf("%d / %d\n", p, q);
        } 
    }
}