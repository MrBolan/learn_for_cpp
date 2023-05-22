#include <iostream>
#include <cmath>
#include <vector>
#include <random>
class RSA {
private:
    // private member variables
    int __p, __q, __n, __f, __e, __d;

public:
    // public member functions
    RSA() {
        __p = __q = __n = __f = __e = __d = 0;
        std::tie(__n, __e, __d) = __keyGenerate();
    }

    std::pair<int, int> generatePubKey() {
        return std::make_pair(__n, __e);
    }

    std::pair<int, int> generatePrivKey() {
        return std::make_pair(__n, __d);
    }

    int encrypt(int plain) {
        return __RSA(plain, std::make_pair(__n, __e));
    }

    int decrypt(int crpt) {
        return __deRSA(crpt, std::make_pair(__n, __d));
    }

private:
    // private member functions
    int __fastExpMod(int b, int e, int m) {
        int result = 1;
        while (e != 0) {
            if ((e & 1) == 1) {
                result = (result * b) % m;
            }
            e >>= 1;
            b = (b * b) % m;
        }
        return result;
    }

    std::vector<int> __primeArray(int r) {
        std::vector<int> lis;
        std::vector<int> prime(r + 1, 0);
        for (int i = 2; i <= r; i++) {
            if (prime[i] == 0) {
                lis.push_back(i);
            }
            for (int j : lis) {
                if (i * j > r) {
                    break;
                }
                prime[i * j] = 1;
                if (i % j == 0) {
                    break;
                }
            }
        }
        return lis;
    }

    bool __prime(int n, int test_divisor) {
        if (std::sqrt(n) < test_divisor) {
            return true;  // True if n is prime
        }
        if (n % test_divisor == 0) {
            return false;  // False if n is not prime
        }
        else {
            return __prime(n, test_divisor + 1);
        }
    }

    int __gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        else {
            return __gcd(b, a % b);
        }
    }

    int __findCoPrime(int s) {
        int e = 0;
        while (true) {
            e = rand() % 10000;
            int x = __gcd(e, s);
            if (x == 1) {
                break;
            }
        }
        return e;
    }

    std::tuple<int, int, int> __inV(int a, int b) {
        if (b == 0) {
            return std::make_tuple(1, 0, a);
        }
        int x, y, r;
        std::tie(x, y, r) = __inV(b, a % b);
        int temp = x;
        x = y;
        y = temp - static_cast<int>(a / b) * y;
        return std::make_tuple(x, y, r);
    }

    int __searchD(int e, int s) {
        int x = 0;
        int y = 0;
        int r = 0;
        std::tie(x, y, r) = __inV(e, s);
        int d = (x + s) % s;
        return d;
    }

    std::tuple<int, int, int> __keyGenerate() {
        std::vector<int> a = __primeArray(10000);
        int p = a[rand() % a.size()];
        int q = a[rand() % a.size()];
        int n = p * q;
        int s = (p - 1) * (q - 1);
        int e = __findCoPrime(s);
        int d = __searchD(e, s);
        return std::make_tuple(n, e, d);
    }

    int __RSA(int plain, std::pair<int, int> ned) {
        int crpt = __fastExpMod(plain, ned.second, ned.first);
        return crpt;
    }

    int __deRSA(int crpt, std::pair<int, int> ned) {
        int plain = __fastExpMod(crpt, ned.second, ned.first);
        return plain;
    }
};


int main() {
    RSA rsa;
    auto pubkey = rsa.generatePubKey();
    auto privkey = rsa.generatePrivKey();

    int plain;
    std::cout << "请输入要进行RSA加密的明文: ";
    std::cin >> plain;

    std::cout << "RSA公钥为: (" << pubkey.first << ", " << pubkey.second << ")" << std::endl;
    int crpt = rsa.encrypt(plain);
    std::cout << "使用RSA公钥加密的结果为: " << crpt << std::endl;

    std::cout << "RSA私钥为: (" << privkey.first << ", " << privkey.second << ")" << std::endl;
    int decrypted = rsa.decrypt(crpt);
    std::cout << "使用RSA私钥解密的结果为: " << decrypted << std::endl;

    return 0;
}
