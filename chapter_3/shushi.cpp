#include <cstdio>
#include <cstring>
// 输入一串数字集合，输出所有只包含于该集合内数字的三位数乘两位数竖式
int main()
{
    int cnt = 0;
    char s[20], buf[99];
    scanf("%s", s);
    for (int abc = 111; abc <= 999; abc++)
        for (int de = 11; de <= 99; de++)
        {
            int x = abc * (de % 10), y = abc * (de / 10), z = abc * de;
            sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);  // 输出到字符串
            int ok = 1;
            for (int i = 0; i < strlen(buf); i++)
                // strchr()返回在字符串 s 中第一次出现字符 buf[i] 的位置，
                //  如果未找到该字符则返回 NULL
                if (strchr(s, buf[i]) == NULL) ok = 0;
            if (ok)
            {
                printf("<%d>\n", ++cnt);
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
            }
        }
    printf("The number of solutions = %d\n", cnt);
    return 0;
}