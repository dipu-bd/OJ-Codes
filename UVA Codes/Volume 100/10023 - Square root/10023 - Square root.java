import java.util.*;
import java.math.*;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int test = sc.nextInt();
        for(int i = 1; i <= test; ++i)
        {
            BigInteger Y = new BigInteger(sc.next());
            BigInteger X = SquareRoot(Y);
            System.out.println(X);
            if(test != i) System.out.println();
        }
    }
    
    public static BigInteger SquareRoot(BigInteger Y)
    {
        if(Y.compareTo(BigInteger.ZERO) == 0 || 
            Y.compareTo(BigInteger.ONE) == 0)
            return Y;
        
        BigInteger two = BigInteger.valueOf(2);
        BigInteger PX = Y;
        BigInteger X = Y.divide(two);
        while(X.compareTo(PX) != 0) 
        {
            PX = X;
            X = (Y.divide(X).add(X)).divide(two);
        }
        
        return PX;
    }
}