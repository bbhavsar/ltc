#include <cstring>
#include "common.hh"

// Forward declaration of the read4 API.
string str = "hello world. quick brown fox wants to jump over fence";
int read4(char *buf) {
    static int idx = 0;

    int count = 0;
    int i = 0;
    while (idx < str.length() && count < 4) {
        buf[i++] = str[idx++];
        count++;
    }

    return count;
}

class Solution {
private:
    static const int FIXED_BUF_SIZE = 4;
    vector<char> int_buf;
    int int_buf_idx;
    int int_buf_bytes;
    bool is_eof;
public:
    Solution() : int_buf(vector<char>(FIXED_BUF_SIZE, 0)), int_buf_idx(0),
                 int_buf_bytes(0), is_eof(false) {}

    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        if (is_eof) {
            return count;
        }
        int write_buf_idx = 0;
        if (int_buf_idx != 0) {
            while (int_buf_idx < int_buf_bytes && write_buf_idx < n) {
                buf[write_buf_idx++] = int_buf[int_buf_idx++];
                count++;
            }
            if (int_buf_idx == int_buf_bytes) {
                int_buf_idx = int_buf_bytes = 0;
            }
        }
        int num4_reads = (n-count) / 4;
        int num_remain = (n-count) % 4;
        for (; num4_reads > 0; num4_reads--) {
            int bytes_read = read4(buf + write_buf_idx);
            if (bytes_read == 0) {
                is_eof = true;
                return count;
            }
            count += bytes_read;
            write_buf_idx += bytes_read;
        }

        if (num_remain > 0) {
            assert(int_buf_idx == 0);
            assert(int_buf_bytes == 0);
            int bytes_read = read4(&int_buf[0]);
            if (bytes_read == 0) {
                is_eof = true;
                return count;
            }
            int_buf_bytes = bytes_read;
            while (num_remain > 0 && int_buf_idx < int_buf_bytes) {
                assert(write_buf_idx < n);
                assert(int_buf_idx < FIXED_BUF_SIZE);
                buf[write_buf_idx++] = int_buf[int_buf_idx++];
                count++;
                num_remain--;
            }
            if (int_buf_idx == int_buf_bytes) {
                int_buf_idx = int_buf_bytes = 0;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    char result[256] = {0};

    s.read(result, 3);
    cout << result << endl;
    memset(result, 0, 256);

    s.read(result, 10);
    cout << result << endl;
    memset(result, 0, 256);

    s.read(result, 3);
    cout << result << endl;
    memset(result, 0, 256);

    s.read(result, 15);
    cout << result << endl;
    memset(result, 0, 256);

    s.read(result, 7);
    cout << result << endl;
    memset(result, 0, 256);

    s.read(result, 9);
    cout << result << endl;
    memset(result, 0, 256);

    s.read(result, 9);
    cout << result << endl;
    memset(result, 0, 256);

    s.read(result, 9);
    cout << result << endl;
    memset(result, 0, 256);

    return 0;
}

