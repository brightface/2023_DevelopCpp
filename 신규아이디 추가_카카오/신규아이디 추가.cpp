#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <cstring>
using namespace std;

char answer[1010];
string ans;

void rule4() {
    int flag2 = 1;
    while (flag2)
    {
        if (ans[0] == '.')
        {
            ans.erase(0, 1);

        }
        else if (ans[size(ans) - 1] == '.') ans.erase(size(ans) - 1, 1);
        else
        {
            flag2 = 0;
            break;
        }


    }
}
string solution(string new_id)
{
    strncpy(answer, new_id.c_str(), sizeof(answer));
    //1단계
    for (int i = 0; i < size(answer); i++)
    {
        if (isalpha(answer[i])) answer[i] = tolower(answer[i]);
    }
    ans = answer;
    cout << ans << endl;

    /*
     || isdigit(ans[i]) || ans[i] = '-' || ans[i] = '_' || ans[i] = '.')
    */
    //2단계
    for (int i = 0; i < size(ans); i++)
    {
        // cout<<i;
        int kflag = 0;
        if (isalpha(ans[i])) kflag = 1;
        if (isdigit(ans[i])) kflag = 1;
        if (ans[i] == '-') kflag = 1;
        if (ans[i] == '_') kflag = 1;
        if (ans[i] == '.') kflag = 1;
        if (kflag == 0)
        {
            cout << "erase:" << i << ans[i] << endl;
            ans.erase(i, 1);
            i--;
            kflag = 0;
        }
    }
    cout << ans << endl;
    //3단계
    // strncpy(answer, ans.c_str(), sizeof(answer));
    // ans = answer;
    int flag = 0;
    for (int i = 0; i < size(ans); i++)
    {
        if (flag == 0)
        {
            if (ans[i] == '.')
            {
                flag = 1; // 첫번째 . 을 남겨두고 flag를 1 건다.
                continue;
            }
        }
        else//flag == 1; //남겨두고 있을떄
        {
            if (ans[i] == '.') {
                ans.erase(i, 1);
                i--;
            }
            else {
                flag = 0; // 아니면 그냥 안지우고 그것만 나둔다.
            }
        }
    }
    cout << ans << endl;
    //4단계
//     strncpy(answer, ans.c_str(), sizeof(answer));
//     ans = answer;
    rule4();
    cout << ans << endl;
    // ans = answer;
    // 5단계
    if (ans == "")
    {
        ans += 'a';
    }
    //6단계
    if (size(ans) >= 16)
    {
        ans = ans.substr(0, 15);
    }

    rule4();
    cout << ans << endl;
    //7단계
    while (size(ans) <= 2)
    {
        ans += ans[size(ans) - 1];
    }

    cout << ans;
    return ans;
}