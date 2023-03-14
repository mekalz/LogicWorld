#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int randNum() {
    return rand() % 100 + 1;
}

int main() {
    //////////////////////////////////////
    unsigned seed;  // Random generator seed
    // Use the time function to get a "seed” value for srand
    seed = time(0);
    srand(seed);
    //////////////////////////////////////
    int hp = 10; //血
    int rank = 1;// 级别
    int ex = 0;// 经验值
    cout << "欢迎来到本游戏" << endl;
    cout << "请给你的角色取一个名字" << endl;
    string name;
    cin >> name;

    cout << "你好" << name << endl;
    string a1 = "1 魔法森林";
    string a2 = "2 黑水潭";
    while (hp >= 1) {
        cout << "你要去哪？" << a1 << "  " << a2 << "  " << "hp =" << hp << endl;
        cout << "ex =" << ex << endl;
        cout << "rank =" << rank << endl;
        int ans;
        cin >> ans;
        if (ans == 1) {
            if (randNum() > 50) {
                cout << "你遇到了一个魔法精灵，他给你加了一滴血" << endl;
                if (rank * 10 > hp) {
                    hp = hp + 1;
                }
            } else {
                cout << "你遇到了一个魔法怪兽" << endl;
                if (randNum() >= 45) {
                    cout << "你遇到了一个一级魔法怪兽" << endl;
                    if (hp <= 5) {
                        cout << "魔法怪兽砍了你一刀，你死了." << endl;
                        hp = 0;
                    } else {
                        hp = hp - 5;
                        cout << "你杀了它，但你掉了5滴血." << endl;
                        ex = ex + 1;
                        if (ex >= 10) {
                            rank = rank + 1;
                            cout << "你成功升级到：" << rank << endl;
                            hp = rank * 10;
                            ex = 0;
                        }
                    }
                } else if (randNum() >= 20) {
                    cout << "你遇到了一个二级魔法怪兽" << endl;
                    if (rank < 2) {
                        cout << "它杀了你。游戏结束. " << endl;
                        hp = 0;
                    } else if (rank >= 2) {
                        hp = hp - 5;
                        cout << "你杀了它，但你掉了5滴血." << endl;
                        ex = ex + 1;
                        if (ex >= 10) {
                            rank = rank + 1;
                            cout << "你成功升级到：" << rank << endl;
                            hp = rank * 10;
                            ex = 0;
                        }
                    } else if (randNum() >= 25) {
                        cout << "你遇到了一个精灵小屋" << endl;
                        if (rank * 10 > hp || 5 < hp) {
                            cout << "它给你加了5滴血";
                        }
                    }
                }
            }
        }
    }
    return 0;
}