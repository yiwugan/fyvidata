inherit ROOM;
void midnight_event();
void sunrise_event(); 
void create()
{
        set("short", "�����");
        set("long", @LONG
�����Ƿ��ƹ㳡�ı��ߣ��������������Կ���Զ�����ʵĳ�ǽ�����ֵĽֵ���
���������µĻ������˿˿֬�۵������������ǴӴ�ֶ����Ʈ�㻨�굴�������ģ�
��Ũ���֬����Ϣ�������������֬������ơ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"nwind1",
                "north" : __DIR__"nwind3",
                "east" : __DIR__"pxhdian",
                "west" : __DIR__"qcyzdian",
        ]));
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",20);
        set("coor/z",0);
        setup();
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
} 
void midnight_event() 
{
        object badguy;
        object room = this_object();
        int i, bandit_no = 3 + random(7);
        
        if(!random(10)) {
                for(i=0; i<bandit_no; i++) {
                        if(objectp(badguy = new("/obj/npc/bandit"))) {
                                badguy->setup_bandit("ɽ������", "/obj/armor/cloth", "/obj/weapon/blade_guitou", "fy");
                                badguy->move(room);
                                badguy->ccommand("chat �º�ɱ�ˣ���߷Ż�");
                        }
                }
                NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
} else {
                NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
        }
} 
void sunrise_event() 
{
        object *ob_list;
        int i;
        
        ob_list = children("/obj/npc/bandit");
        for(i=0; i<sizeof(ob_list); i++) {
                if(ob_list[i]->query("area_mark") == "fy") {
                        if(environment(ob_list[i])) {
                                message_vision("$N�е�������Ҳ��������\n",ob_list[i]);
                        }
                        destruct(ob_list[i]);
                }
        }
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
