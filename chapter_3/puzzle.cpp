#define LOCAL
#include <iostream>
using namespace std;

const int length = 5 + 1;
char puz[length][length];
int ch, sx, sy, n = 0;
bool solve = true, stop = false;

int main()
{
#ifdef LOCAL
    freopen("data_puzzle.in", "r", stdin);
    freopen("data_puzzle.out", "w", stdout);
#endif
    while (!stop)
    {
        n++;
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                puz[i][j] = getchar();
                if (puz[i][j] == 'Z') { stop = true; break; }
                if (puz[i][j] == ' ') { sx = i; sy = j; }
            }
            if (stop) break;
            getchar();
        }
        if (stop) break;
        while (ch = getchar())
        {
            // if (ch == '\n') continue;
            if (ch == 'A' && sx > 1)
            {
                puz[sx][sy] = puz[sx-1][sy];
                puz[sx-1][sy] = ' ';
                sx--;
            }
            else if (ch == 'B' && sx < 5)
            {
                puz[sx][sy] = puz[sx+1][sy];
                puz[sx+1][sy] = ' ';
                sx++;
            }
            else if (ch == 'L' && sy > 1)
            {
                puz[sx][sy] = puz[sx][sy-1];
                puz[sx][sy-1] = ' ';
                sy--;
            }
            else if (ch == 'R' && sy < 5)
            {
                puz[sx][sy] = puz[sx][sy+1];
                puz[sx][sy+1] = ' ';
                sy++;
            }
            else if (ch == '0') break;
            else { solve = false; break; }
        }
        cout << "Puzzle #" << n << ":\n";
        if (solve)
            for (int i = 1; i <= 5; i++)
            {
                for (int j = 1; j <= 5; j++) cout << puz[i][j] << " ";
                cout << '\n';
            }
        else cout<<"This puzzle has no final configuration."<<"\n";
        cout << "\n";
        solve = true;
    }
}
