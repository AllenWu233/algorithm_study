#include <cstdio>
#include <cstring>
using namespace std;

char s[85];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", s);
        int t = 1;  // 周期
        for (int i = 1; i < strlen(s); i++)  // 遍历字符串
            if (s[i] == s[0] && strlen(s)%t == 0)  // 判断周期
            {
                int ok = 1;
                for (int j = 0; j < t; j++)  // 划分成strlen(s)/t段，判断各段是否相同
                    for (int k = j; k < strlen(s) - t; k += t)
                        if (s[k] != s[k+t]) { ok = 0; break; }
                if (ok) break;
                else t++;  // 不是周期，自增1
            }
            else t++;
        if (n) printf("%d\n\n", t);
        else printf("%d\n", t);
        memset(s, '\0', sizeof(s));
    }
    return 0;
}