#include <iostream>
using namespace std;

void swap2(int &a, int &b)
{
    int t = a; a = b; b = t;
}

int main()
{
    int a = 3, b = 4;
    swap2(a, b);
    cout << a << " " << b << "\n";
    return 0;
}// AutoSave's default settings.

{
  "auto_save_on_modified": false,
  "auto_save_delay_in_seconds": 1,
  "auto_save_all_files": true,
  "auto_save_current_file": "",
  "auto_save_ignore_files": [],
  "auto_save_backup": false,
  "auto_save_backup_suffix": "autosave"
}
