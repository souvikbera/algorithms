import java.math.*;
class assignment1
{
	public static void main(String as[])
	{
		BigInteger a=new BigInteger("3141592653589793238462643383279502884197169399375105820974944592");
		BigInteger b=new BigInteger("2718281828459045235360287471352662497757247093699959574966967627");
		BigInteger c=a.multiply(b);
		System.out.println(c);
	}
}