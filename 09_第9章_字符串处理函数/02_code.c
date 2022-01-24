#include <stdio.h>
void test01()
{
    int year = 2021;
    int month = 7;
    int day = 30;

    char buf[128] = "";
    int len = sprintf(buf, "%d年%d月%d日", year, month, day);
    printf("len=%d, buf=%s\n", len, buf);
}

void test02()
{
    char buf[128] = "";
    sprintf(buf, "%d", 1234);
    printf("buf=%s\n", buf);
}

void test03()
{
    char buf[128] = "2021年7月30日";
    int year = 0;
    int month = 0;
    int day = 0;

    //sscanf 和 %d 提取'0'~'9'
    sscanf(buf, "%d年%d月%d日", &year, &month, &day);
    printf("%d %d %d\n", year, month, day);
}

void test04()
{
    char buf[128] = "2021年 7月 30日";
    char msg[128] = "";
    sscanf(buf, "%s", msg);
    printf("msg=%s\n", msg);
}
void test05()
{
    char buf[128] = "";
    sscanf("1234:::::5678", "%*d:%s", buf);
    printf("buf=%s\n", buf);
}

void test06()
{
    char buf[128] = "[02:04.94][00:36.09]我想大声宣布 对你依依不舍";

    char *song_lrc = buf;
    //定位到歌词的位置
    while (*song_lrc == '[')
    {
        song_lrc += 10;
    }

    //逐个时间分析
    char *time_lrc = buf;
    while (*time_lrc == '[')
    {
        int m = 0;
        int s = 0;
        sscanf(time_lrc, "[%d:%d", &m, &s);
        printf("时间%d秒 唱歌词:%s\n", m * 60 + s, song_lrc);

        time_lrc += 10;
    }
}

void test07()
{
    char buf[128] = "lianghe@1000phone.com";
    char name[128] = "";
    char log[128] = "";

    sscanf(buf, "%[^@]@%[^.]", name, log);
    printf("name=%s, log=%s\n", name, log);
}

#include <string.h>
void test08()
{
    char buf[] = "+CMGR:REC UNREAD,+8613466630259,98/10/01,18:22:11+00,ABCdefGHI";
    char *msg[32] = {buf};

    int i = 0;
    while ((msg[i] = strtok(msg[i], ",")) && (++i))
        ;

    //短信的读取状态
    //msg[0] = "+CMGR:REC UNREAD"
    char status[128] = "";
    sscanf(msg[0], "%*s %s", status);
    if (strcmp(status, "UNREAD") == 0)
    {
        printf("有未读信息\n");
    }
    else if (strcmp(status, "READ") == 0)
    {
        printf("已读信息\n");
    }

    //msg[1]="+8613466630259"
    printf("手机号:%s\n", msg[1] + 3);

    //msg[2]="98/10/01"
    int year = 0;
    int month = 0;
    int day = 0;
    sscanf(msg[2], "%d/%d/%d", &year, &month, &day);
    printf("日期:%02d年%02d月%02d日\n", year + 1900, month, day);

    //msg[3]="18:22:11+00"
    int h = 0, m = 0, s = 0;
    sscanf(msg[3], "%d:%d:%d", &h, &m, &s);
    printf("时间:%02d时%02d分%02d秒\n", h, m, s);

    printf("收到的消息:%s\n", msg[4]);
}
int main(int argc, char const *argv[])
{
    test08();
    return 0;
}
