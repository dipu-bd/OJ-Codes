import java.util.*;
import java.math.*;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int test = sc.nextInt();
        for(int i = 0; i < test; ++i)
        {
            BigInteger benefit = new BigInteger(sc.next());
            BigInteger cost = new BigInteger(sc.next());
            BigInteger res = benefit.subtract(cost);
            System.out.println(res);
        }
    }
}