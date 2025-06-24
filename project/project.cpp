#include "clui.h"
#include <stdio.h>
#include <iostream>

using namespace std;
struct admin
{
    char *username = new char[0], *password = new char[0];
};
struct user
{
    char *firstname = new char[0], *lastname = new char[0];
    char *password = new char[0], *student_id = new char[0];
    char *phone_number = new char[0], *level = new char[0];
    char *reshte = new char[0];
    int cash = 0;
    int *list = new int[0];
    int size = 0;
};
struct Day
{
    int d, m, y;
    int *list = new int[0];
    int size = 0;
};
struct food
{
    int d, m, y;
    char *name = new char[0], *loc = new char[0];
    int cnt, price;
};
struct self
{
    char *name = new char[0];
};
admin *ADs = nullptr;
user *users = nullptr;
Day *days = nullptr;
food *foods = nullptr;
self *selfs = nullptr;
int AD_cnt = 0, US_cnt = 0, DAY_cnt = 0, food_cnt = 0, self_cnt = 0, dl = 2000, cur_day = 0;
void Invaliid(int l, int r, char t)
{
    if((t < ('0' + l)) || (t > ('0' + r)))
    {
        printf("\n\n\n\n\n                         ");
        change_background_color(5);
        printf("Invalid input");
        reset_color();
        printf("\n\n\n   ");
        delay(dl);
        clear_screen();
    }
}
void welcome()
{
    init_clui();
    int k = 30, k2 = 5;
    change_background_color(1);
    for(int i = 0; i < k2; i ++)
    {
        for(int j = 0; j < 16 + 2 * k; j ++)
            printf(" ");
        printf("\n");
    }
    for(int i = 0; i < k; i ++)
        printf(" ");
    printf("Welcome to SAMAD");
    for(int i = 0; i < k; i ++)
        printf(" ");
    printf("\n");
    for(int i = 0; i < k2; i ++)
    {
        for(int j = 0; j < 16 + 2 * k; j ++)
            printf(" ");
        printf("\n");
    }
    reset_color();
    delay(dl);
    clear_screen();
}
void prnt(const char* c, int a)
{
    change_background_color(a);
    printf("%s", c);
    reset_color();
    printf("\n\n   ");
}
void get_and_fix(char* &s)
{
    char *name = new char[500];
    cin.getline(name, 500);
    int sz = 0;
    while(name[sz])
        sz ++;
    s = new char[sz + 1];
    while(sz)
    {
        s[sz] = name[sz];
        sz --;
    }
    s[0] = name[0];
    delete[] name;
}
bool str_cmp(char *s, char *t)
{
    for(int i = 0; ; i ++)
    {
        if(s[i] != t[i])
            return 0;
        if(s[i] == 0)
            return 1;
    }
}
void Register_admin()
{
    admin *temp = new admin[AD_cnt + 1];
    printf(" Enter username : ");
    get_and_fix(temp[AD_cnt].username);
    printf(" Enter password : ");
    get_and_fix(temp[AD_cnt].password);
    for(int i = 0; i < AD_cnt; i ++)
        temp[i] = ADs[i];
    for(int i = 0; i < AD_cnt; i ++)
    {
        if(str_cmp(temp[AD_cnt].username, ADs[i].username))
            {
                delete[] temp[AD_cnt].username;
                delete[] temp[AD_cnt].password;
                delete[] temp;
                prnt(" This username is already taken", 7);
                delay(dl);
                return;
            }
    }
    AD_cnt ++;
    delete[] ADs;
    ADs = temp;
    prnt(" Registration was successful ", 3);
    delay(dl);
}

void Remove_admin()
{
    admin temp;
    printf(" Enter username : ");
    get_and_fix(temp.username);
    printf(" Enter password : ");
    get_and_fix(temp.password);
    int ind = -1;
    for(int i = 0; i < AD_cnt; i ++)
    {
        if(str_cmp(temp.username, ADs[i].username) == 0)
            continue;
        if(str_cmp(temp.password, ADs[i].password) == 0)
            continue;
        ind = i;
        break;
    }
    if(ind == -1)
    {
        prnt(" Invalid username or password", 5);
        delay(dl);
        return;
    }
    admin *temp2 = new admin[AD_cnt - 1];
    for(int i = 0; i < ind; i ++)
        temp2[i] = ADs[i];
    for(int i = ind + 1; i < AD_cnt; i ++)
        temp2[i - 1] = ADs[i];
    delete[] ADs[ind].username;
    delete[] ADs[ind].password;
    delete[] ADs;
    AD_cnt --;
    ADs = temp2;
    prnt(" The admin was removed ", 3);
    delay(dl);
}

void ADMIN()
{
    printf("\n\n\n   ");
    prnt("1_ Register an admin", 1);
    prnt("2_ Remove an admin  ", 4);
    prnt("3_ Back             ", 1);
    prnt("(Type the number of your choice)", 0);
    char t = getch();
    printf("you entered : <%c>\n", t);
    delay(dl);
    clear_screen();
    Invaliid(1, 3, t);
    if(t == '1')
        Register_admin();
    if(t == '2')
        Remove_admin();
    if(t == '3')
        return;
    ADMIN();
}
void Free(user temp)
{
    delete[] temp.firstname;
    delete[] temp.lastname;
    delete[] temp.password;
    delete[] temp.student_id;
    delete[] temp.phone_number;
    delete[] temp.level;
    delete[] temp.reshte;
}
void Register_user()
{
    user *temp = new user[US_cnt + 1];
    printf(" Enter firstname : ");
    get_and_fix(temp[US_cnt].firstname);
    printf(" Enter lastname : ");
    get_and_fix(temp[US_cnt].lastname);
    printf(" Enter password : ");
    get_and_fix(temp[US_cnt].password);
    printf(" Enter student_id : ");
    get_and_fix(temp[US_cnt].student_id);
    printf(" Enter phone_number : ");
    get_and_fix(temp[US_cnt].phone_number);
    printf(" Enter level : ");
    get_and_fix(temp[US_cnt].level);
    printf(" Enter reshte : ");
    get_and_fix(temp[US_cnt].reshte);
    for(int i = 0; i < US_cnt; i ++)
        temp[i] = users[i];
    for(int i = 0; i < US_cnt; i ++)
    {
        if(str_cmp(temp[US_cnt].student_id, users[i].student_id))
            {
                Free(temp[US_cnt]);
                delete[] temp;
                prnt(" This student_id is already taken", 7);
                delay(dl);
                return;
            }
    }
    US_cnt ++;
    delete[] users;
    users = temp;
    prnt(" Registration was successful ", 3);
    delay(dl);
}
void Remove_user()
{
    user temp;
    printf(" Enter student_id : ");
    get_and_fix(temp.student_id);
    printf(" Enter password : ");
    get_and_fix(temp.password);
    int ind = -1;
    for(int i = 0; i < US_cnt; i ++)
    {
        if(str_cmp(temp.student_id, users[i].student_id) == 0)
            continue;
        if(str_cmp(temp.password, users[i].password) == 0)
            continue;
        ind = i;
        break;
    }
    if(ind == -1)
    {
        prnt(" Invalid student_id or password", 5);
        delay(dl);
        return;
    }
    user *temp2 = new user[US_cnt - 1];
    for(int i = 0; i < ind; i ++)
        temp2[i] = users[i];
    for(int i = ind + 1; i < US_cnt; i ++)
        temp2[i - 1] = users[i];
    Free(users[ind]);
    delete[] users;
    US_cnt --;
    users = temp2;
    prnt(" The admin was removed ", 3);
    delay(dl);
}
void USER()
{
    printf("\n\n\n   ");
    prnt("1_ Register an user", 1);
    prnt("2_ Remove an user  ", 4);
    prnt("3_ Back             ", 1);
    prnt("(Type the number of your choice)", 0);
    char t = getch();
    printf("you entered : <%c>\n", t);
    delay(dl);
    clear_screen();
    Invaliid(1, 3, t);
    if(t == '1')
        Register_user();
    if(t == '2')
        Remove_user();
    if(t == '3')
        return;
    USER();
}
void add_to_days(int d, int m, int y)
{
    for(int i = 0; i < DAY_cnt; i ++)
    {
        if(days[i].d != d)
            continue;
        if(days[i].m != m)
            continue;
        if(days[i].y != y)
            continue;
        return;
    }
    Day *temp = new Day[DAY_cnt + 1];
    for(int i = 0; i < DAY_cnt; i ++)
        temp[i] = days[i];
    temp[DAY_cnt].d = d;
    temp[DAY_cnt].m = m;
    temp[DAY_cnt].y = y;
    delete[] days;
    days = temp;
    DAY_cnt ++;
}
void add_to_list(int ind, int ind2)
{
    int *temp = new int[days[ind].size +  1];
    for(int i = 0; i < days[ind].size; i ++)
        temp[i] = days[ind].list[i];
    temp[days[ind].size] = ind2;
    delete[] days[ind].list;
    days[ind].list = temp;
    days[ind].size ++;
}
void add_to_foods(int d, int m, int y, char *name, char *loc, int cnt, int price)
{
    food *temp = new food[food_cnt + 1];
    for(int i = 0; i < food_cnt; i ++)
        temp[i] = foods[i];
    temp[food_cnt] = {d, m, y, name, loc, cnt, price};
    delete[] foods;
    foods = temp;
    food_cnt ++;
    for(int i = 0; i < DAY_cnt; i ++)
    {
        if(d != days[i].d)
            continue;
        if(y != days[i].y)
            continue;
        if(m != days[i].m)
            continue;
        add_to_list(i, food_cnt - 1);
        prnt(" Added successfully", 3);
        delay(dl);
        clear_screen();
        return;
    }
}
void add_food()
{
    int d, m, y;
    printf(" Enter day : ");
    scanf("%d", &d);
    printf(" Enter month : ");
    scanf("%d", &m);
    printf(" Enter year : ");
    scanf("%d", &y);
    char *name, *loc;
    printf(" Enter name : ");
    cin.ignore();
    get_and_fix(name);
    int cnt, price;
    printf(" Enter location : ");
    get_and_fix(loc);
    printf(" Enter cnt : ");
    scanf("%d", &cnt);
    printf(" Enter price : ");
    scanf("%d", &price);
    cnt *= 2;
    add_to_days(d, m, y);
    int ind = -1;
    for(int i = 0; i < self_cnt; i ++)
    {
        if(str_cmp(selfs[i].name, loc) == 0)
            continue;
        ind = i;
        break;
    }
    if(ind == -1)
    {
        prnt(" Invalid location", 5);
        delay(dl);
        clear_screen();
        return;
    }
    add_to_foods(d, m, y, name, loc, cnt, price);
}
void add_location()
{
    char *name;
    printf(" Enter location name : ");
    get_and_fix(name);
    for(int i = 0; i < self_cnt; i ++)
    {
        if(str_cmp(selfs[i].name, name) == 0)
            continue;
        prnt(" This location is already exist", 5);
        delay(dl);
        clear_screen();
        return;
    }
    self *temp = new self[self_cnt + 1];
    for(int i = 0; i < self_cnt; i ++)
        temp[i] = selfs[i];
    temp[self_cnt].name =  name;
    self_cnt ++;
    delete[] selfs;
    selfs = temp;
}
void admin_entered()
{
    printf("\n\n\n   ");
    prnt("1_ Add a food", 1);
    prnt("2_ Add a location", 4);
    prnt("3_ Logout      ", 1);
    prnt("(Type the number of your choice)", 0);
    char t = getch();
    printf("you entered : <%c>\n", t);
    delay(dl);
    clear_screen();
    Invaliid(1, 3, t);
    if(t == '1')
        add_food();
    if(t == '2')
        add_location();
    if(t == '3')
        return;
    admin_entered();
}
void Enter_admin()
{
    char *user_name, *password;
    printf(" Enter Username : ");
    get_and_fix(user_name);
    printf(" Enter Password : ");
    get_and_fix(password);
    int ind = -1;
    for(int i = 0; i < AD_cnt; i ++)
    {
        if(str_cmp(user_name, ADs[i].username) == 0)
            continue;
        if(str_cmp(password, ADs[i].password) == 0)
            continue;
        ind = i;
        break;
    }
    if(ind == -1)
    {
        prnt(" Invalid username or password", 5);
        delay(dl);
        return;
    }
    prnt(" Entered successfully", 3);
    delay(dl);
    clear_screen();
    admin_entered();
}
void change_pass(char *student_id)
{
    char *p1, *p2;
    printf(" Enter your current pass : ");
    get_and_fix(p1);
    printf(" Enter your new pass :     ");
    get_and_fix(p2);
    int ind = 0;
    for(int i = 0; i < US_cnt; i ++)
    {
        if(str_cmp(student_id, users[i].student_id) == 0)
            continue;
        ind = i;
        break;
    }
    if(str_cmp(p1, users[ind].password) == 0)
    {
        prnt(" Invalid password", 5);
        delay(dl);
        return;
    }
    users[ind].password = p2;
    prnt(" Password Changed successfully", 3);
    delay(dl);
    return;
}
void profile(char *student_id)
{
    int ind = 0;
    for(int i = 0; i < US_cnt; i ++)
    {
        if(str_cmp(student_id, users[i].student_id) == 0)
            continue;
        ind = i;
        break;
    }
    printf("\n\n\n");
    printf("Firstname : %s\n\n", users[ind].firstname);
    printf("Lastname : %s\n\n", users[ind].lastname);
    printf("Student_id : %s\n\n", users[ind].student_id);
    printf("Cash : %d\n\n", users[ind].cash);
    printf("Phone_number : %s\n\n", users[ind].phone_number);
    printf("Maghta' : %s\n\n", users[ind].level);
    printf("Reshte : %s\n\n", users[ind].reshte);
    delay(dl);
    clear_screen();
    return;
}
void hesab_setting(char *student_id)
{
    printf("\n\n\n   ");
    prnt("1_ Profile", 1);
    prnt("2_ Change password", 4);
    prnt("3_ Back             ", 1);
    prnt("(Type the number of your choice)", 0);
    char t = getch();
    printf("you entered : <%c>\n", t);
    delay(dl);
    clear_screen();
    Invaliid(1, 3, t);
    if(t == '1')
        profile(student_id);
    if(t == '2')
        change_pass(student_id);
    if(t == '3')
        return;
    hesab_setting(student_id);
}
void Show_list(int ind2)
{
    for(int i = 0; i < days[ind2].size; i ++)
    {
        printf("\n name : %s    location : %s    count(tedad nimpors) : %d   price : %d\n", foods[days[ind2].list[i]].name, foods[days[ind2].list[i]].loc, foods[days[ind2].list[i]].cnt, foods[days[ind2].list[i]].price);
        printf("\n indice : %d\n", days[ind2].list[i]);
    }
}
void add_to_foodlist(int fd1, int ind)
{
   int *temp = new int[users[ind].size + 1];
   for(int i = 0; i < users[ind].size; i ++) 
        temp[i] = users[ind].list[i];
    temp[users[ind].size] = fd1;
    delete[] users[ind].list;
    users[ind].list = temp;
    users[ind].size ++;
}
void porsYaNimpors(int ind, int fd1)
{
    printf("\n\n\n   ");
    prnt("1_ Porse", 1);
    prnt("2_ Nimporse", 4);
    prnt("3_ Back             ", 1);
    prnt("(Type the number of your choice)", 0);
    char t = getch();
    printf("you entered : <%c>\n", t);
    delay(dl);
    clear_screen();
    Invaliid(1, 3, t);
    if(t == '1')
    {
        if(users[ind].cash / 2 < foods[fd1].price)
        {
            prnt(" NOT ENOUGH MONEY !", 7);
            delay(dl);
            return;
        }
        if(foods[fd1].cnt < 2)
        {
            prnt(" NOT ENOUGH FOOD !", 7);
            delay(dl);
            return;
        }
        for(int i = 0; i < users[ind].size; i ++)
        {
            if(users[ind].list[i] == fd1)
            {
                prnt(" in ghaza baraye in user reserve ast !", 7);
                delay(dl);
                return;
            }
        }
        foods[fd1].cnt -= 2;
        users[ind].cash -= foods[fd1].price * 2;
        add_to_foodlist(fd1, ind);
        prnt(" Food reserve successfully !", 3);
        delay(dl);
        clear_screen();
        return;
    }

    if(t == '2')
    {
        if(users[ind].cash < foods[fd1].price)
        {
            prnt(" NOT ENOUGH MONEY !", 7);
            delay(dl);
            return;
        }
        if(foods[fd1].cnt < 1)
        {
            prnt(" NOT ENOUGH FOOD !", 7);
            delay(dl);
            return;
        }
        for(int i = 0; i < users[ind].size; i ++)
        {
            if(users[ind].list[i] == fd1)
            {
                prnt(" in ghaza baraye in user reserve ast !", 7);
                delay(dl);
                return;
            }
        }
        foods[fd1].cnt --;
        users[ind].cash -= foods[fd1].price;
        add_to_foodlist(fd1, ind);
        prnt(" Food reserve successfully !", 3);
        delay(dl);
        return;
    }
    if(t == '3')
        return;
    porsYaNimpors(ind, fd1);
}
void pick_food(int ind, int ind2)
{
    int fd1;
    printf(" Enter indice : ");
    scanf("%d", &fd1);
    porsYaNimpors(ind, fd1);
}
void pick(int ind, int ind2)
{
    printf("\n\n\n   ");
    prnt("1_ Show list of foods", 1);
    prnt("2_ pick food", 4);
    prnt("3_ Back             ", 1);
    prnt("(Type the number of your choice)", 0);
    char t = getch();
    printf("you entered : <%c>\n", t);
    delay(dl);
    clear_screen();
    Invaliid(1, 3, t);
    if(t == '1')
        Show_list(ind2);
    if(t == '2')
        pick_food(ind, ind2);
    if(t == '3')
        return;
    pick(ind, ind2);
}
void reserve(char *student_id)
{

    int ind = 0;
    for(int i = 0; i < US_cnt; i ++)
    {
        if(str_cmp(student_id, users[i].student_id) == 0)
            continue;
        ind = i;
        break;
    }
    int d, m, y;
    printf(" Enter day of the date :     ");
    scanf("%d", &d);
    printf(" Enter month of the date :     ");
    scanf("%d", &m);
    printf(" Enter year of the date :     ");
    scanf("%d", &y);
    if(d + m * 30 + y * 12 * 30 - 2 < cur_day)
    {
        prnt(" monghazi shode ast", 7);
        delay(dl);
        return;
    }
    int ind2 = -1;
    for(int i = 0; i < DAY_cnt; i ++)
    {
        if(d != days[i].d)
            continue;
        if(m != days[i].m)
            continue; 
        if(y != days[i].y)
            continue;
        ind2 = i;
        break;
    }
    if(ind2 == -1 || (days[ind2].size == 0))
    {
        prnt(" This day food table is empty", 7);
        delay(dl);
        return;
    }
    pick(ind, ind2);
}
void afzayesh(char *student_id)
{
    int ind = 0;
    for(int i = 0; i < US_cnt; i ++)
    {
        if(str_cmp(student_id, users[i].student_id) == 0)
            continue;
        ind = i;
        break;
    }
    int cash;
    printf(" Enter cash : ");
    scanf("%d", &cash);
    users[ind].cash += cash *= 2;
    prnt(" Tarakonesh movaffagh !", 3);
    delay(dl);
    return;
}
void Samane_taghziziye(char *student_id)
{
    printf("\n\n\n   ");
    prnt("1_ Reserve", 1);
    prnt("2_ Afzayesh Etebar", 4);
    prnt("3_ Back             ", 1);
    prnt("(Type the number of your choice)", 0);
    char t = getch();
    printf("you entered : <%c>\n", t);
    delay(dl);
    clear_screen();
    Invaliid(1, 3, t);
    if(t == '1')
        reserve(student_id);
    if(t == '2')
        afzayesh(student_id);
    if(t == '3')
        return;
    Samane_taghziziye(student_id);
}
void user_entered(char *student_id)
{
    printf("\n\n\n   ");
    prnt("1_ Samane Taghziye", 1);
    prnt("2_ Tanzimat hesab karbary", 4);
    prnt("3_ Logout             ", 1);
    prnt("(Type the number of your choice)", 0);
    char t = getch();
    printf("you entered : <%c>\n", t);
    delay(dl);
    clear_screen();
    Invaliid(1, 3, t);
    if(t == '1')
        Samane_taghziziye(student_id);
    if(t == '2')
        hesab_setting(student_id);
    if(t == '3')
        return;
    user_entered(student_id);
}
void Enter_user()
{
    char *student_id, *password;
    printf(" Enter student_id : ");
    get_and_fix(student_id);
    printf(" Enter Password : ");
    get_and_fix(password);
    int ind = -1;
    for(int i = 0; i < US_cnt; i ++)
    {
        if(str_cmp(student_id, users[i].student_id) == 0)
            continue;
        if(str_cmp(password, users[i].password) == 0)
            continue;
        ind = i;
        break;
    }
    if(ind == -1)
    {
        prnt(" Invalid student_id or password", 5);
        delay(dl);
        return;
    }
    prnt(" Entered successfully", 3);
    delay(dl);
    clear_screen();
    user_entered(student_id);
}
void Enter_Samad()
{
    printf("\n\n\n   ");
    prnt("1_ Enter as an admin", 1);
    prnt("2_ Enter as a user  ", 4);
    prnt("3_ Back             ", 1);
    prnt("(Type the number of your choice)", 0);
    char t = getch();
    printf("you entered : <%c>\n", t);
    delay(dl);
    clear_screen();
    Invaliid(1, 3, t);
    if(t == '1')
        Enter_admin();
    if(t == '2')
        Enter_user();
    if(t == '3')
        return;
    Enter_Samad();
}
void start()
{
    printf("\n\n\n   ");
    prnt("1_ Register/Remove an admin", 1);
    prnt("2_ Register/Remove a user  ", 4);
    prnt("3_ Enter to SAMAD          ", 1);
    prnt("4_ Finish                  ", 4);
    prnt("(Type the number of your choice)", 0);
    char t = getch();
    printf("you entered : <%c>\n", t);
    delay(dl);
    clear_screen();
    if(t == 'D')
        cur_day --;
    if(t == 'A')
        cur_day ++;
    Invaliid(1, 4, t);
    if(t == '1')
        ADMIN();
    if(t == '2')
        USER();
    if(t == '3')
        Enter_Samad();
    if(t == '4')
        return;
    start();
}
int main()
{
    welcome();
    start();
}