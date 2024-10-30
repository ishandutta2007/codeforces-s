import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int l = sc.nextInt();
    	String n = sc.next();
    	BigInteger ans = new BigInteger(n);
    	int[] idx = new int[l-1];
    	idx[0] = 0;
    	for(int i=1; i<l-1; i++) {
    		if(idx[i-1] > 0) {
    			idx[i] = -idx[i-1];
    		} else {
    			idx[i] = -idx[i-1] + 1;
    		}
    	}
    	for(int i=0; i<l-1; i++) {
    		if(n.charAt(l/2+idx[i]) == '0') {
    			continue;
    		}
    		String s1 = n.substring(0, l/2+idx[i]);
    		String s2 = n.substring(l/2+idx[i], l);

    		BigInteger b1 = new BigInteger(s1);
    		BigInteger b2 = new BigInteger(s2);
    		BigInteger b = b1.add(b2);
    		if(b.compareTo(ans) < 0) {
    			ans = b;
    		} else {
    			System.out.println(ans);
    			return;
    		}
    	}
    	System.out.println(ans);
    }

    static void debug(long... args) {
    	if(!DEBUG_FLG) return;
    	boolean flg = false;
    	for(long s : args) {
    		if(flg) System.out.print(" ");
    		flg = true;
    		System.out.print(s);
    	}
    	System.out.println();
    }

    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte() {
            if(ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch(IOException e) {
                    e.printStackTrace();
                }
                if(buflen <= 0) {
                    return false;
                }
            }
            return true;
        }
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
        public boolean hasNext() { skipUnprintable(); return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public int nextInt(){
            return Integer.parseInt(next());
        }
        public double nextDouble(){
            return Double.parseDouble(next());
        }
    }

    static void shuffleArray(long[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            long tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
    }
}