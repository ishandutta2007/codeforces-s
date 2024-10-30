import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
 
public class Main {
	private static FastScanner sc = new FastScanner();
	
	public static void main(String[] args) {
		int n = sc.nextInt();
		int[] p = new int[n];
		for(int i=0; i<n; i++) {
			p[i] = sc.nextInt();
		}
		
		int max1n = 0;
		int max1p = -1;
		int max2n = 0;
		int[] rec = new int[n];
		for(int i=0; i<n; i++) {
			if(p[i] > max1n && p[i] > max2n) {
				rec[i]--;
				max2n = max1n;
				max1n = p[i];
				max1p = i;
			} else if(p[i] > max2n) {
				rec[max1p]++;
				max2n = p[i];
			}
		}
		int max = -2;
		int pos = -1;
		for(int i=0; i<n; i++) {
			if(rec[i] > max) {
				max = rec[i];
				pos = i;
			} else if(rec[i] == max && p[i] < p[pos]) {
				pos = i;
			}
		}
		System.out.println(p[pos]);
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
}