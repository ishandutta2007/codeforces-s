import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;
/*

Remove BRs, take turns

#B > #R Bob wins
#B < #R Alice wins

EQUAL:
Parity of number of turns

1
4
RBBR


 */
public class F {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		int[] nimber=getReal(1000);
		int[] nimberFull=new int[500_001];
		for (int i=0; i<1000; i++) nimberFull[i]=nimber[i];
		for (int i=1000; i<nimberFull.length; i++) {
			nimberFull[i]=nimberFull[i-34];
		}
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] a=fs.next().toCharArray();
			int aCount=0, bCount=0;
			for (char c:a) 
				if (c=='R') aCount++;
				else bCount++;
			if (aCount!=bCount) {
				if (aCount>bCount) {
					out.println("Alice");
				}
				else {
					out.println("Bob");
				}
				continue;
			}
			ArrayList<Integer> groups=new ArrayList<>();
			int curSize=1;
			for (int i=1; i<n; i++) {
				if (a[i]!=a[i-1]) {
					curSize++;
				}
				else {
					groups.add(curSize);
					curSize=1;
				}
			}
			groups.add(curSize);
//			System.out.println(groups);
			int mex=0;
			for (int i:groups) {
				mex^=nimberFull[i];
			}
			if (mex==0) {
				out.println("Bob");
			}
			else {
				out.println("Alice");
			}
		}
		out.close();
	}
	
	static int[] getReal(int size) {
		int[] a=new int[size];
		a[0]=0;
		a[1]=0;
		int max=0;
		for (int i=2; i<a.length; i++) {
			if (i%10000 == 0) {
				System.out.println("At "+i);
			}
			boolean[] reachable=new boolean[16];
			for (int split=0; split+1<i; split++) {
				int left=split;
				int right=i-2-left;
				if (left>right) {
					break;
				}
				int leftAns=a[left], rightAns=a[right];
				reachable[leftAns^rightAns] = true;
			}
			
			int mex=0;
			while (reachable[mex]) mex++;
			a[i]=mex;
			max=Math.max(max, a[i]);
		}
		return a;
	}
	
	static final Random random=new Random();
	static final int mod=1_000_000_007;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}