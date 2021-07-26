#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
// Tên chương trình
const string NAME = "solution";
const int NTEST = 20;

string out_folder = "Output\\", in_folder = "Test\\";

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        remove("text.inp");
        bool b = CopyFile((in_folder + "input" + to_string(iTest) + ".txt").c_str(),
           "text.inp", true);
        if (!b) {
            cout << "Error: " << GetLastError() << endl;
        }
        cout << "Running on test " << iTest << ": ... ";
        system((NAME + ".exe").c_str());
        cout << "Done !" << '\n';

        CopyFile("text.out",
           (out_folder + "output" +to_string(iTest) + ".txt").c_str(), true);

    }
    return 0;
}





