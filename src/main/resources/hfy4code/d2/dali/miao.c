inherit ROOM;
void create()
{
        set("short", "土地庙");
        set("long", @LONG
这里是大理城人烧香( shaoxiang )还愿的地方。据说这里的土地公公
十分灵验，所以每当过年过节，这里都门庭若市。大家都盼望着通过祭祀
换来平安。中间一个香台，上面瓢出袅袅青湮。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"wroad2",
]));
        set("outdoors", "dali");
        set("coor/x",-880);
        set("coor/y",-740);
        set("coor/z",80);
        setup();
}
void init()
{
       add_action("do_ponder","shaoxiang");
}
int do_ponder(string arg)
{
       object who;

       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("你的神不够。\n");
       message_vision("$N虔诚地跪在香案前，默默祈祷。\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 15 ) );
       message_vision("$N似乎感觉神清气爽，身上的杀气也似乎减少了不少。 \n" , who);
    return 1;
}