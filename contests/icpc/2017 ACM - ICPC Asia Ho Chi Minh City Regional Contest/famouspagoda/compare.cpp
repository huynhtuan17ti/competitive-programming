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
        int n = myIntRand(3, 8);
        inp << n << ' ' << myIntRand(1, n) << ' ' << myIntRand(1, 2) << '\n';
        vector <int> a;
        for(int i = 0; i < n; i++)
            a.push_back(myIntRand(1, 5));
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++)
            inp << a[i] << " \n"[i == n-1];
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