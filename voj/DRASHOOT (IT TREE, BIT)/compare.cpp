#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "test";
// Số test kiểm tra
const int NTEST = 100;

random_device device;
mt19937 generator(device());

int myIntRand(int lo, int hi) {
    uniform_int_distribution<int> rd(lo, hi);
    return rd(generator);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        int n = myIntRand(5, 10);
        inp << n << '\n';
        for(int i = 0; i < n; i++)
            inp << myIntRand(0, n+5) << " \n"[i == n-1];
        int m = myIntRand(1, n);
        inp << m << '\n';
        int cnt = 0;
        while(m--){
            int t = myIntRand(0, 1);
            if(t == 0){
                inp << "S " << myIntRand(1, n-cnt) << '\n';
                cnt--;
            }else{
                int x = myIntRand(0, n);
                int y = myIntRand(x, n);
                inp << "Q " << x << ' ' << y << '\n';
            }
        }
        
        // Code phần sinh test ở đây
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system("./sol");
        system("./accept_sol");
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}