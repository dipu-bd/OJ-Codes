import java.util.*;
import java.math.*;

class Main
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext())
        {
            String str = sc.nextLine();
            BigInteger num = new BigInteger(str);
            BigInteger sqr = num.multiply(num);
            String sqstr = sqr.toString();
            if(sqstr.endsWith(str))
            {
                System.out.printf("Automorphic number of %d-digit.\n", str.length());
            }
            else
            {
                System.out.printf("Not an Automorphic number.\n");
            }
        }
    }
}