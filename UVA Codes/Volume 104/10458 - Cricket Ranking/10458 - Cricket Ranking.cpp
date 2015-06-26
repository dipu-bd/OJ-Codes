
/**
 * @author Sudipto Chandra Das
 * @email dipu.sudipta@gmail.com
 * @univ SUST
 */
import java.util.Scanner;
import java.math.BigInteger;

class Main {
    
    public static BigInteger combin(int n, int k)
    {
        BigInteger up = BigInteger.ONE;
        BigInteger down = BigInteger.ONE;
        for(int i = 1; i <= k; ++i, --n)
        {
            up = up.multiply(BigInteger.valueOf(n));
            down = down.multiply(BigInteger.valueOf(n));
        }        
        return up.divide(down);
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        while (sc.hasNext())
        {
            //take input
            int n = sc.nextInt();
            int k = sc.nextInt();
            int lower[], upper[];
            lower = new int[k + 10];
            upper = new int[k + 10];
            for (int i = 0; i < k; ++i)
            {
                lower[i] = sc.nextInt();
                upper[i] = sc.nextInt();
            }

            //process using inclusion exclusion
            BigInteger res = BigInteger.ZERO;
            for (int m = (1 << k) - 1; m >= 0; --m)
            {
                int p = n, popc = 0;
                for (int i = 0; i < k; ++i) //iterate to build n
                {
                    if ((m & (1 << i)) == 0)
                    {
                        p -= lower[i];
                    }
                    else
                    {
                        ++popc;
                        p -= (upper[i] + 1);
                    }
                }
                       
                if ((popc & 1) == 0) //inclusion
                {
                    res = res.add(combin(p + k - 1, k - 1));                
                }
                else //exclusion
                { 
                    res = res.subtract(combin(p + k - 1, k - 1));
                }
            }
                
            //show final result
            System.out.println(res);
        }
    }
}
