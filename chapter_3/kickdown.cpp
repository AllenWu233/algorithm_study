// UVa1588
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char n1[105], n2[105];
int cnt1, cnt2, ok;

int main()
{
    while (cin >> n1 >> n2)
    {
        if (strlen(n1) > strlen(n2)) swap(n1, n2);  // 短条在上，长条在下
        for (cnt1 = 0; cnt1 < strlen(n1); cnt1++)  // 尝试左移上条
        {
            ok = 1;
            for (int i = cnt1; i < strlen(n1); i++)
                if (n1[i] - '0' + n2[i-cnt1] - '0' > 3) { ok = 0; break; }
            if (ok) break;
        }
        for (cnt2 = 0; cnt2 < strlen(n1), strlen(n1); cnt2++)  // 尝试右移上条
        {
            ok = 1;
            for (int i = 0; i < min(strlen(n2)-cnt2, strlen(n1)); i++)
                if (n1[i] - '0' + n2[i+cnt2] - '0' > 3) { ok = 0; break; }
            if (ok) break;
        }
        cout << min(strlen(n2)+cnt1, max(strlen(n1)+cnt2, strlen(n2))) << endl;
        memset(n1, '\0', sizeof(n1));
        memset(n2, '\0', sizeof(n2));
    }
    return 0;
}