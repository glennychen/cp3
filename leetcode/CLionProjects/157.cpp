/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int total_read_characters = 0;
        int n_read = read4(buf);
        while(n_read!=0 && n>0){
            if(n<n_read){
                total_read_characters +=n;
                buf += n; // need this line because the judge will also verify the destination buffer contain the correct read, not just the total read
            
            } else {
                total_read_characters +=n_read;
                buf += n_read;
            
            }
            n-=n_read;  
            n_read = read4(buf);
        }
        return total_read_characters;
    }
};
