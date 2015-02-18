import java.util.*;
import java.math.*;

class Main
{
    public static void main(String args[])
    {
        boolean first = true;
        Scanner sc = new Scanner(System.in);
        System.out.println("Dear GOD, Pardon Me");
        while(sc.hasNext())
        {
            //newline between cases
            if(first) first = false;
            else System.out.println();
            
            //input
            BigInteger t = new BigInteger(sc.next());
            int n = sc.nextInt();
            
            //calculation
            BigInteger tn = t.pow(n);
            BigInteger A = tn.multiply(t.subtract(BigInteger.ONE));
            BigInteger B = tn.subtract(BigInteger.ONE);
            BigInteger g = A.gcd(B);
            BigInteger x = B.divide(g);
            BigInteger k = A.divide(g);
            
            //result
            System.out.printf("X = %d\n", x);
            System.out.printf("K = %d\n", k);
        }
    }
    
}