 // Room: white_earth.c --- by neon
inherit ROOM; 
void create()
{
        set("short", "��ɫ����"); 
        set("long", @LONG
����һ���װ��������£���������£���������ɫ����������һ�档
LONG);
        set("type","street");
        set("exits",([
        "southup":__DIR__"earthtemple",
        ]) );
        //}}
        set("objects", ([
                __DIR__"npc/huo_tianqing" : 1,
        ]) );
        set("jade", 1);
        setup(); 
}
void init(){
        add_action("do_search", "search");
} 
int do_search(){
        object me, obj, huo;
        me = this_player();
        huo = present("huo tianqing", this_object());
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("������æ��\n");
        }
        me->start_busy(1);
        message_vision("$N����������ϸѰ�ҡ�\n", me);
        if(objectp(huo)){
                message_vision("$N����$n���һ��������������ڸ�ʲô��\n", huo, me);
                huo->kill_ob(me);
        } else if(query("jade")){
                obj = new(__DIR__"obj/white_jade");
                if(objectp(obj)){
                        obj->move(me);
                }
                message_vision("$N�ӵ��ϼ���һ���ɫ����ʯ��\n", me);
           delete("jade");
        } else {
                tell_object(me, "��ʲô��û�з��֡�\n");
        }
        return 1;
} 
void reset(){
        ::reset();
        if(!query("jade")) {
                set("jade", 1);
        }
}  
