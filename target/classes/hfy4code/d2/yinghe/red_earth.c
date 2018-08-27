 // Room: red_earth.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "��ɫ����");
        set("long", @LONG
����һ����ͮͮ�����£���������£���������ɫ����������һ�档
LONG);
        set("type","street");
        set("exits",([
        "northup":__DIR__"earthtemple",
        ]) );
        //}}
    set("objects", ([
        __DIR__"npc/yan_duhe" : 1,
        __DIR__"npc/liu_yuhen" : 1,
        ]) );
        set("item_desc", ([
                "tupo" : "��ͮͮ�����������ƻã��㲻�ɵ���ú����ҡ���������裩\n",
                "slop" : "��ͮͮ�����������ƻã��㲻�ɵ���ú����ҡ���������裩\n",
                "����" : "��ͮͮ�����������ƻã��㲻�ɵ���ú����ҡ���������裩\n",
        ]));
        set("red_jade", 1);
        setup(); 
} 
void init(){
        add_action("do_search", "search");
} 
int do_search(){
        object me, obj, yan;
        me = this_player();
        yan = present("yan duhe", this_object());
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("������æ��\n");
        }
        me->start_busy(1);
        message_vision("$N�ں���������ϸѰ�ҡ�\n", me);
        if(objectp(yan)){
                message_vision("$N����$n���һ��������������ڸ�ʲô��\n", yan, me);
                yan->kill_ob(me);
   } else if(query("red_jade")){
                obj = new(__DIR__"obj/red_jade");
                if(objectp(obj)){
                        obj->move(me);
                }
                message_vision("$N�ӵ��ϼ���һ���ɫ����ʯ��\n", me);
                delete("red_jade");
        } else {
                tell_object(me, "��ʲô��û�з��֡�\n");
        }
        return 1;
} 
void reset(){
        ::reset();
        if(!query("red_jade")) {
                set("red_jade", 1);
        }
}
