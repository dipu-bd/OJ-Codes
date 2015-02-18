/**
 * @author Sudipto Chandra Dipu
 * @university SUST
 * @email dipu.sudipta@gmail.com
 */
 
import java.util.*;
import java.math.*;

class Main {
    
    public static BigInteger func[] = new BigInteger[260];
    public static Scanner sc = new Scanner(System.in);
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //generate all
        func[0] = func[1] = BigInteger.ONE;
        for(int n = 2; n <= 250; ++n)
        {
            func[n] = func[n - 1];
            func[n] = func[n].add(func[n - 2]);
            func[n] = func[n].add(func[n - 2]);
        }
        
        //result
        int n;
        while(sc.hasNext())
        {
            n = sc.nextInt();
            System.out.println(func[n]);
        }
    }
    
}
