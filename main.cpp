#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int hp = 10; //血
int level = 1;// 级别
int ex = 0;// 经验值

int randNum() {
    return rand() % 100 + 1;
}
void  checkLevelUp() {
    if (ex >= 10) {
        level = level + 1;
        cout << "你成功升级到：" << level << endl;
        hp = level * 10;
        ex = 0;
    }
};

int main() {
    system("chcp 65001");
    //////////////////////////////////////
    unsigned seed;  // Random generator seed
    // Use the time function to get a "seed” value for srand
    seed = time(0);
    srand(seed);
    //////////////////////////////////////
    
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
        cout << "level =" << level << endl;
        int ans;
        cin >> ans;
        if (ans == 1) {
            int w = randNum();
            if (w > 50) {
                cout << "你遇到了一个魔法精灵，他给你加了一滴血" << endl;
                if (level * 10 > hp) {
                    hp = hp + 1;
                }
            } else {
                cout << "你遇到了一个......" << endl;
                int a = randNum();
                if (a >= 50) {
                    cout << "你遇到了一个一级魔法怪兽" << endl;
                    if (hp <= 5) {
                        cout << "魔法怪兽砍了你一刀，你死了." << endl;
                        hp = 0;
                    } else if (level == 1) {
                        hp = hp - 5;
                        cout << "你杀了它，但你掉了5滴血." << endl;
                        ex = ex + 4;
                        checkLevelUp();
                    } else {
                        hp = hp - 2;
                        cout << "你杀了它，但你掉了2滴血." << endl;
                        ex = ex + 4;
                        checkLevelUp();
                    }
                } else if (a >= 25) {
                    cout << "你遇到了一个精灵小屋" << endl;
                    if (level * 10 > hp && hp < 5) {
                        cout << "它给你加了5滴血" << endl;
                        hp = hp + 5;
                    } else if (hp >= level * 10) {
                        ex = ex + 5;
                        cout << "它给你加了5经验";
                        checkLevelUp();
                    } else {
                        cout << "它给你加了2滴血";
                        hp = hp + 2;
                    }
                } else if (randNum() >= 10) {
                    cout << "你遇到了一个二级魔法怪兽" << endl;
                    if (level < 2) {
                        cout << "它杀了你。游戏结束. " << endl;
                        hp = 0;
                    } else if (level >= 2) {
                        hp = hp - 5;
                        cout << "你杀了它，但你掉了5滴血." << endl;
                        ex = ex + 4;
                        checkLevelUp();
                    }
                }
            }
        }
        if (ans == 2) {
            int s = randNum();
            if (s >= 85) {
                cout << "你遇到了一只黑龙的筋，并把他吃掉了，你加了3滴血" << endl;
                hp = hp + 3;
            } else if (s >= 45) {
                cout << "你遇到了一只2级黑龙";
                if (level == 2 && hp >= 3) {
                    cout << "你杀了它，但你掉了5滴血." << endl;
                    hp = hp -5;
                    ex = ex + 4;
                    checkLevelUp();
                }else if (level < 2){
                    cout << "你死了" << endl;
                    hp = 0;
                }else {
                    cout <<  "你杀了它 但你掉了2滴血"<< endl;
                    hp = hp - 2;
                    ex = ex + 4;
                    checkLevelUp();
                }
            }
        }
    }
    return 0;
}