
import java.util.*;
import java.math.*;

class Main
{

    public static void main(String args[]) // entry point from OS
    {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext())
        {

            BigInteger big = new BigInteger(sc.next());
            if (big.signum() == 0) break;


            big = big.subtract(BigInteger.ONE);
            int len = big.bitLength();

            System.out.print("{");

            BigInteger three = new BigInteger("3");
            boolean comma = false;
            for (int i = 0; i < len; ++i)
            {
                if (big.testBit(i))
                {

                    //print comma if necessary
                    if (comma) System.out.print(',');
                    else comma = true;

                    //print number
                    System.out.print(" " + three.pow(i));
                }
            }

            System.out.println(" }");
        }
    }
}
