inherit ROOM;

void create()
{
        set("short", "�μ�����");
        set("long", @LONG
����ǵ��˶�ϲ�������������ֵ��������ӻ�¯��ð���Ļ�⽫ǽ
��ӳ��ͨ�죬���ӵĽ���������˸�ʽ���������Ʒ��δ���Ʒ�����ǳ�
ͷ�����������ӡ������ȣ����������������õ��������졣
�ſ���һ����ľ�ƣ�������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wroad2",
]));

        set("outdoors", "dali");
        set("objects", ([
                "/d/dali/npc/smith": 1 ]) );
        set("item_desc", ([
                "sign": @TEXT

Ŀǰ���ǿɶ�����ding����

������axe����������blade����ذ�ף�dagger����
�ֲ棨fork����������hammer����
���ȣ�staff����������sword�������ޣ�whip��
��ì��spear������ָ��banzhi��
ÿ��ʮ���ƽ�

���ӣ�
ding blade $HIY$ ������ tulongblade tie

�������ͻ�������������ϰ�����һ�ѻ�ɫ�ģ��������� �� tulongblade.

$BLK$ - ��ɫ            $NOR$ - �ָ�������ɫ
$RED$ - ��ɫ            $HIR$ - ����ɫ
$GRN$ - ��ɫ            $HIG$ - ����ɫ
$YEL$ - ����ɫ          $HIY$ - ��ɫ
$BLU$ - ����ɫ          $HIB$ - ��ɫ
$MAG$ - ǳ��ɫ          $HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ          $HIC$ - ����ɫ
$WHT$ - ǳ��ɫ          $HIW$ - ��ɫ

TEXT
        ]) );

        set("coor/x",-880);
        set("coor/y",-760);
        set("coor/z",80);
        setup();
        replace_program(ROOM);
}