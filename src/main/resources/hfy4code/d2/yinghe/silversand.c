 // Room: silversand.c --- by MapMaker
inherit ROOM;
string trail();
void create()
{
        set("short", "��ɫɳ��");
        set("long", @LONG
һ��Ƭ��Ө��׵�ɳ����ѩ�������Ų���ɳ���ϣ���Ȼ�������ö���������
ɳ�������������죬��֪���ж�Զ��������һ����ʽ�Źֵľ޴���á�����һ����
���ʯ�����������ɳ������һЩ���ѵĺۼ����ƺ���ʲô����������������
LONG);  
        //{{ --- by MapMaker
        set("type","street");
        set("exits",([
                "east":__DIR__"cylinder",
                "southup":__DIR__"silversand2",
                "north":__DIR__"weaponroom",
        ]) );
        //}}
        set("item_desc", ([
                "trail" : (: trail :),
                "�ۼ�" : (: trail :),
                "sand" : "ɳ������һЩ���ѵĺۼ���������죩��\n",
                "ɳ" : "ɳ������һЩ���ѵĺۼ���������죩��\n",
        ]));
        setup();
} 
void init(){
        add_action("do_search", "search");
}
string trail(){
        object me;
        me = this_player();
        if(me->query_skill("animal-training") > 50) {
                tell_object(me, "��ֱ�����ƺ������й��ĺۼ����������˼�Ƭһ��ɫ����Ƭ��\n");
                tell_object(me, "����ʶ��������������ߡ�\n");
                me->set_temp("marks/��ˮ��", 1);
        } else {
                tell_object(me, "�㲻��ѱ�޳�ʶ����ֱ�ó���Щ�ۼ���\n");
        } 
   return "";
} 
int do_search(){
        object me, snake;
        
        me = this_player();
        if(me->is_busy() || me->is_fighting()){
                return notify_fail("������æ��\n");
        }
        message_vision("$N��ɳ������ϸѰ�ҡ�\n", me);
        me->start_busy(1);
        snake = present("hanshui snake", this_object());
        if(objectp(snake)){
                return notify_fail("������������ǰ��Զ��ɳ���ϡ�\n");
        }
        if(!objectp(snake) && query("snake_gone")) {
                return notify_fail("�����ѱ��˷��ҹ��ˣ�����Ҳ�Ҳ���ʲô�����ˡ�\n");
        }
        if(!me->query_temp("marks/��ˮ��")){
                return notify_fail("�������Ѱ��һͨ��ʲô��û�з��֡�\n");
        }
        if(!random(3) && !objectp(snake)){
                tell_object(me, "����ɳ���һ�ǿ���һ��С�ߡ�����ɫ��С�߸�����ɫ��ɳ������һ�壬
����ϸ���ѿ�����\n");
                snake = new(__DIR__"npc/water_snake");
                if(objectp(snake)){
                        snake->move(this_object());
                }
                set("snake_gone", 1);
        } else {
                tell_object(me, "��ʲô��û�з��֡�\n");
        }
        return 1;
} 
void reset(){
        ::reset();
        if(query("snake_gone")){
                delete("snake_gone");
        }
}  
